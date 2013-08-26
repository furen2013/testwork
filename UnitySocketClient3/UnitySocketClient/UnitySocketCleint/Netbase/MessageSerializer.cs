using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;
using System.Diagnostics;

namespace Support.Message
{
	/// <summary>
	/// <see cref="ProtoBuf.IExtensible"/>对象和字节流间的编码器
	/// </summary>
	public class MessageSerializer
	{
		#region Serialize
		public byte[] Serialize<T>(T message)
			where T : ProtoBuf.IExtensible
		{
			var stream = new MemoryStream();
			Serialize(message, stream);
			return stream.ToArray();
		}

		public int Serialize<T>(T message, Stream dest)
			where T : ProtoBuf.IExtensible
		{
			Debug.Assert(ProtoBuf.Serializer.NonGeneric.CanSerialize(message.GetType()));
            //写名称
            string messagename = message.GetType().FullName;
            byte[] byteArray = Encoding.Default.GetBytes(messagename);
            dest.Write(byteArray, 0, byteArray.Length);
            dest.WriteByte(0);
            //serialize Type
            SerializeImpl(dest, message);
            return messagename.Length + 1;
		}

		private static void SerializeImpl<T>(Stream stream, T message)
			where T : ProtoBuf.IExtensible
		{
			ProtoBuf.Serializer.NonGeneric.Serialize(stream, message);
		}
		#endregion

		#region Deserialize

		public ProtoBuf.IExtensible Deserialize(byte[] messagePackageData)
		{
			return DeserializeImpl(new MemoryStream(messagePackageData, 0, messagePackageData.Length));
		}

		public ProtoBuf.IExtensible Deserialize(byte[] messagePackageData, int offset, int count)
		{
			return DeserializeImpl(new MemoryStream(messagePackageData, offset, count));
		}

		private ProtoBuf.IExtensible DeserializeImpl(Stream stream)
		{
            //byte[] message_typelen = new byte[4];
            //stream.Read(message_typelen, 0, 4);
            //int message_len = System.BitConverter.ToInt32(message_typelen, 0);

            //byte[] message_typename = new byte[message_len - 1];
            //stream.Read(message_typename, 0, message_len - 1);
            //string messagename = Encoding.Default.GetString(message_typename);
            //stream.ReadByte();
            StreamReader reader = new StreamReader(stream);
            string messagename = reader.ReadLine();

            System.Type type = MessageDispatcher.getTypeByStr(messagename.Substring(0, messagename.Length - 1));
            stream.Position = messagename.Length;
            return (ProtoBuf.IExtensible)ProtoBuf.Serializer.NonGeneric.Deserialize(type, stream);
		}
		#endregion

	}
}
