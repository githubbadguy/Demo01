#pragma once
#include <string>
#include <WinSock2.h>
#include "MessageType.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;


class BaseSocket
{
private:
	SOCKET _socket;
	SocketProtoType _protoType;
	string _ip;
	unsigned short _port;
	bool _inited;
public:
	BaseSocket();
	virtual ~BaseSocket();
	BaseSocket(string ip, unsigned short port, SocketProtoType prototype = SocketProtoType::PROTO_TCP);
	bool Bind(string ip, unsigned short port);
	bool Connect(string ip, unsigned short port);
	virtual bool Receive();
	virtual bool Send();
	virtual void ReceiveFrom();
	virtual void SendTo();
protected:
	bool Init();
	void Clean();
	bool CheckRead();
	bool CheckWrite();
	virtual void OnReceive();
	virtual void OnSend();
	virtual void OnSendTo();
	virtual void OnReceiveFrom();
};

