using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Net;
using Support.Net;
using Support.Message;
using System.Reflection;
using System.Diagnostics;
using System.Net.Sockets;
using System.IO;
using clientmsg;

/// App.xaml 的交互逻辑
/// </summary>
public class ProtobufClient
{
    private static ProtobufClient instance;
    public static ProtobufClient Instance { get { return instance; } }

    public string UserName { get; set; }

    public string ContentPath { get; private set; }

    public ProtobufClient()
    {
    }

    public void Run()
    {
        instance = this;

        InitContentPath();

        JFSocket.GetInstance().ConnectServer("127.0.0.1", 30100);
        clientmsg.LoginRequest msg = new clientmsg.LoginRequest();
        msg.name = "test";
        msg.pwd = "123456";
        JFSocket.GetInstance().SendMessage(msg);
        while(true)
        {
            //解析消息
            JFSocket.GetInstance().update();
            System.Threading.Thread.Sleep(1);
        }
    }

    private void InitContentPath()
    {
        ContentPath = System.IO.Path.Combine(
            Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments),
            "Support");
        Directory.CreateDirectory(ContentPath);
    }

    public static void Main(string[] args)  
    {
        ProtobufClient client = new ProtobufClient();
        client.Run();
    }
}