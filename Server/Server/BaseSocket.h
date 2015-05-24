#pragma once
#include <string>
#include <winsock.h>
#include "MessageType.h"
#pragma comment(lib,"wsock32.lib")


class BaseSocket
{
private:
	SOCKET _socket;
	SocketProtoType _protoType;
	std::string _ip;
	unsigned short _port;
	bool _inited;
public:
	BaseSocket();
	virtual ~BaseSocket();
	BaseSocket(std::string ip, unsigned short port, SocketProtoType prototype = SocketProtoType::PROTO_TCP);
	bool Bind(std::string ip, unsigned short port);
	bool Connect(std::string ip, unsigned short port);

	void Send(const std::string& msg);
	void Send(const char* msg, unsigned int length);
protected:
	bool Init();
	void Clean();
};

