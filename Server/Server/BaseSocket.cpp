#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "BaseSocket.h"
using namespace std;

BaseSocket::BaseSocket()
{
	_ip = "";
	_port = 0;
	_protoType = SocketProtoType::PROTO_TCP;
	_socket = INVALID_SOCKET;
	_inited = false;
}
BaseSocket::~BaseSocket()
{
}
BaseSocket::BaseSocket(string ip, unsigned short port, SocketProtoType prototype) :
_ip(ip),
_port(port),
_protoType(prototype),
_socket(INVALID_SOCKET),
_inited(false)
{
}
bool BaseSocket::Init()
{
	_inited = true;
	WORD wversion = MAKEWORD(2, 2);
	WSADATA wsdata;
	int err = -1;
	err = WSAStartup(wversion, &wsdata);
	if (err == SOCKET_ERROR && wsdata.wVersion != wversion)
	{
		return false;
	}
	int type = 0;
	int protocol = 0;
	switch (_protoType)
	{
	case PROTO_TCP:
		type = SOCK_STREAM;
		protocol = IPPROTO_TCP;
		break;
	case PROTO_UDP:
		type = SOCK_DGRAM;
		protocol = IPPROTO_UDP;
		break;
	case PROTO_RAW:
		type = SOCK_RAW;
		protocol = IPPROTO_RAW;
		break;
	default:
		type = SOCK_DGRAM;
		protocol = IPPROTO_IP;
		break;
	}
	_socket = socket(AF_INET, type, protocol);
	if (_socket == INVALID_SOCKET || _socket == SOCKET_ERROR)
	{
		Clean();
		return false;
	}

	if (!Bind(_ip, _port))
	{
		Clean();
		return false;
	}

	return true;
}
void BaseSocket::Clean()
{
	if (_socket != INVALID_SOCKET)
		closesocket(_socket);

	if (_inited)
		WSACleanup();

	_ip = "";
	_port = 0;
	_protoType = SocketProtoType::PROTO_TCP;
	_socket = INVALID_SOCKET;
	_inited = false;
}
bool BaseSocket::Bind(string ip, unsigned short port)
{
	if (!_inited && !Init())
		return false;

	if (_socket == INVALID_SOCKET)
		return false;

	SOCKADDR_IN addr;
	int len = sizeof(SOCKADDR);
	memset(&addr, 0, sizeof(SOCKADDR_IN));

	_ip = ip;
	_port = port;

	if (_ip == "")
		addr.sin_addr.s_addr = htonl(INADDR_ANY);
	else
		addr.sin_addr.s_addr = inet_addr(_ip.c_str());

	addr.sin_family = AF_INET;
	addr.sin_port = htons(_port);

	if (bind(_socket, (SOCKADDR*)&addr, len) == SOCKET_ERROR)
	{
		return false;
	}
	return true;
}
bool BaseSocket::Connect(string ip,unsigned short port)
{
	SOCKADDR_IN addr;
	int len = sizeof(SOCKADDR);
	memset(&addr, 0, sizeof(SOCKADDR_IN));

	if (ip == "")
		addr.sin_addr.s_addr = htonl(INADDR_ANY);
	else
		addr.sin_addr.s_addr = inet_addr(ip.c_str());

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);

	if (SOCKET_ERROR == connect(_socket, (SOCKADDR*)&addr, len))
		return false;

	return true;
}
void BaseSocket::Send(const std::string& msg)
{

}
void BaseSocket::Send(const char* msg, unsigned int length)
{

}
