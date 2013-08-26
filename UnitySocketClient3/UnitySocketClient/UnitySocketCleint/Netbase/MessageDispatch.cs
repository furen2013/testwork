using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;
using System.IO;
//这边定义消息
using clientmsg;

public interface IMessageHandler
{
    void Process(ProtoBuf.IExtensible msg);
}

public class DefaultMessageHandler : IMessageHandler
{
    public void Process(ProtoBuf.IExtensible msg)
    {
        //默认处理函数, 相当于switch case 操作
        if( msg is clientmsg.LoginResponse)
        {
        }
    }
}

public class LoginResponseHandle : IMessageHandler
{
    public void Process(ProtoBuf.IExtensible msg)
    {
        clientmsg.LoginResponse responsemsg = msg as clientmsg.LoginResponse;
        JFSocket.GetInstance().ConnectServer(responsemsg.gate_ip, (int)responsemsg.gate_port);
        clientmsg.LoginGame gamemsg = new clientmsg.LoginGame();
        gamemsg.user_account = responsemsg.user_account;
        JFSocket.GetInstance().SendMessage(gamemsg);
    }
}

public class ClientInitHandle : IMessageHandler
{
    public void Process(ProtoBuf.IExtensible msg)
    {
        clientmsg.ClientInit responsemsg = msg as clientmsg.ClientInit;
        //TODO
    }
}

public static class MessageDispatcher
{
    private static readonly IMessageHandler s_DefaultHandler =
        new DefaultMessageHandler();
    private static readonly Dictionary<Type, IMessageHandler> s_Handlers =
        new Dictionary<Type, IMessageHandler>();
    private static readonly Dictionary<string, Type> typelist = new Dictionary<string, Type>();

    static MessageDispatcher()
    {
        // Register a bunch of handlers.
        s_Handlers.Add(typeof(clientmsg.LoginResponse), new LoginResponseHandle());
        typelist.Add(typeof(clientmsg.LoginResponse).FullName, typeof(clientmsg.LoginResponse));

        s_Handlers.Add(typeof(clientmsg.ClientInit), new ClientInitHandle());
        typelist.Add(typeof(clientmsg.ClientInit).FullName, typeof(clientmsg.ClientInit));
    }

    public static void Dispatch(ProtoBuf.IExtensible msg)
    {
        Type key = msg.GetType();
        if (s_Handlers.ContainsKey(key))
        {
            // We found a specific handler! :)
            s_Handlers[key].Process(msg);
        }
        else
        {
            // We will have to resort to the default handler. :(
            s_DefaultHandler.Process(msg);
        }
    }
    public static  Type getTypeByStr(string name)
    {
        return typelist[name];
    }
}

