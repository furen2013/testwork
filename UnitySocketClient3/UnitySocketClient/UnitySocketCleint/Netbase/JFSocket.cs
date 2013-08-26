//using UnityEngine;
using System.Collections;
using System;
using System.Threading;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using Support.Net;
using Support.Message;

public class JFSocket
{
    //Socket客户端对象
    private Socket clientSocket;
    //JFPackage.WorldPackage是我封装的结构体，
    //在与服务器交互的时候会传递这个结构体
    //当客户端接到到服务器返回的数据包时，我把结构体add存在链表中。
    public Queue<ProtoBuf.IExtensible> recv_msgqueue;
    //消息队列锁
    Mutex msgqueue_mutex;
    //接受线程
    Thread recv_thread;

    //消息序列化
    private readonly MessageSerializer serializer;
    //单例模式
    private static JFSocket instance;
    public static JFSocket GetInstance()
    {
        if (instance == null)
        {
            instance = new JFSocket();
        }
        return instance;
    }

    //单例的构造函数
    JFSocket()
    {
        serializer = new MessageSerializer();
        msgqueue_mutex = new Mutex();
    }
    //连接服务器
    public void ConnectServer(String ip, int port)
    {
        if (clientSocket != null){
            clientSocket.Disconnect(true);
            recv_thread.Join();
            recv_thread = null;
            clientSocket = null;
        }
        clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        //服务器IP地址
        IPAddress ipAddress = IPAddress.Parse(ip);
        //服务器端口
        IPEndPoint ipEndpoint = new IPEndPoint(ipAddress, port);
        //这是一个异步的建立连接，当连接建立成功时调用connectCallback方法
        IAsyncResult result = clientSocket.BeginConnect(ipEndpoint, new AsyncCallback(connectCallback), clientSocket);
        //这里做一个超时的监测，当连接超过5秒还没成功表示超时
        bool success = result.AsyncWaitHandle.WaitOne(10000, true);
        if (!success){
            //超时
            Closed();
            Console.WriteLine("connect Time Out");
        }
        //与socket建立连接成功，开启线程接受服务端数据。
        if(recv_msgqueue == null){
            recv_msgqueue = new Queue<ProtoBuf.IExtensible>();
        }
        if(recv_thread == null){
            recv_thread = new Thread(new ThreadStart(ReceiveSocket));
            recv_thread.IsBackground = true;
            recv_thread.Start();
        }
    }

    //循环获取消息, 解析消息
    public void update()
    {
        msgqueue_mutex.WaitOne();
        if(null == recv_msgqueue){
            msgqueue_mutex.ReleaseMutex();
            return;
        }
        while(0 != recv_msgqueue.Count)
        {
            ProtoBuf.IExtensible msg = recv_msgqueue.Dequeue();
            MessageDispatcher.Dispatch(msg);
        }
        msgqueue_mutex.ReleaseMutex();
    }

    private void connectCallback(IAsyncResult asyncConnect)
    {
        Console.WriteLine("connectSuccess");
    }

    private void ReceiveSocket()
    {
        //在这个线程中接受服务器返回的数据
        while (true)
        {
            if (!clientSocket.Connected)
            {
                //与服务器断开连接跳出循环
                Console.WriteLine("Failed to clientSocket server.");
                clientSocket.Close();
                break;
            }
            try
            {
                int msglength = 0;
                if (clientSocket.Poll(-1, SelectMode.SelectRead) || clientSocket.Poll(-1, SelectMode.SelectError))
                {
                    if (!clientSocket.Connected)
                    {
                        //与服务器断开连接跳出循环
                        Console.WriteLine("Failed to clientSocket server.");
                        clientSocket.Close();
                        break;
                    }
                    //接受数据保存至bytes当中
                    byte[] bytes = new byte[9];
                    //Receive方法中会一直等待服务端回发消息
                    //如果没有回发会一直在这里等着。
                    int i = clientSocket.Receive(bytes);
                    if (i <= 0)
                    {
                        clientSocket.Close();
                        break;
                    }
                    msglength = GetMsgHead(bytes);
                    if (0 == msglength)
                    {
                        ResponsePing();
                        continue;
                    }
                }
                if (clientSocket.Poll(-1, SelectMode.SelectRead) || clientSocket.Poll(-1, SelectMode.SelectError))
                {
                    byte[] msgbytes = new byte[msglength];
                    int i = clientSocket.Receive(msgbytes);
                    if (i <= 0)
                    {
                        clientSocket.Close();
                        break;
                    }
                    ParseMsg(msgbytes);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Failed to clientSocket error");
                clientSocket.Close();
                break;
            }
        }
    }
    private int GetMsgHead(byte[] bytes)
    {
        //在这里进行拆包，因为一次返回的数据包的数量是不定的
        //所以需要给数据包进行查分。
        PackageHead header = new PackageHead();
        header.ReadFrom(bytes, 0);
        return header.MessageLength - PackageHead.SizeOf;
    }

    private void ParseMsg(byte[] bytes)
    {
        //消息序列化
        ProtoBuf.IExtensible message = this.serializer.Deserialize(bytes, 0, bytes.Length);
        //加入消息队列
        msgqueue_mutex.WaitOne();
        recv_msgqueue.Enqueue(message);
        msgqueue_mutex.ReleaseMutex();
    }
    //回复Ping包
    public void ResponsePing()
    {
        byte[] pingmsg = { 9, 0, 0, 0, 5, 0, 0, 0, 0 };
        SendMessage(pingmsg, 0, pingmsg.Length);
    }

    //发送成功回调
    private void sendCallback(IAsyncResult asyncSend)
    {
        Console.WriteLine("Send msg success" + asyncSend.ToString());
    }

    //向服务端发送一条字符串
    //一般不会发送字符串 应该是发送数据包
    public void SendMessage(byte[] msg, int offset, int size)
    {
        try
        {
            lock (this)
            {
                IAsyncResult asyncSend = clientSocket.BeginSend(msg, offset, size, SocketFlags.None, new AsyncCallback(sendCallback), clientSocket);
                bool success = asyncSend.AsyncWaitHandle.WaitOne(5000, true);
                if (!success)
                {
                    clientSocket.Close();
                    Console.WriteLine("Failed to SendMessage server.");
                }
            }
        }
        catch
        {
            clientSocket.Close();
            Console.WriteLine("send message error");
        }
    }

    //向服务端发送数据包，也就是一个结构体对象
    public void SendMessage(ProtoBuf.IExtensible message)
    {
        try
        {
            MemoryStream stream = new MemoryStream();
            byte[] headbuffer = new byte[PackageHead.SizeOf];
            stream.Write(headbuffer, 0, PackageHead.SizeOf);
            int messagename_length = serializer.Serialize(message, stream);
            PackageHead header = new PackageHead();
            // 写入包头
            header.MessageLength = (int)stream.Length;
            header.MessageType = (byte)6;
            header.MessageTypeLength = messagename_length;
            header.WriteTo(stream.GetBuffer(), 0);
            SendMessage(stream.GetBuffer(), 0, (int)stream.Length);
        }
        catch (Exception e)
        {
            Console.WriteLine("send message error: " + e);
        }
    }

    //关闭Socket
    public void Closed()
    {
        if (clientSocket != null && clientSocket.Connected)
        {
            clientSocket.Shutdown(SocketShutdown.Both);
            clientSocket.Close();
        }
        clientSocket = null;
    }

}