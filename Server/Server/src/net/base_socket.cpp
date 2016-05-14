#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "base_socket.h"
using namespace std;

base_socket::base_socket()
{
	_ip = "";
	_port = 0;
	_protoType = socket_proto_type::proto_tcp;
	_socket = INVALID_SOCKET;
	_inited = false;
}
base_socket::~base_socket()
{
}
base_socket::base_socket(string ip, unsigned short port, socket_proto_type prototype) :
_ip(ip),
_port(port),
_protoType(prototype),
_socket(INVALID_SOCKET),
_inited(false)
{
}
bool base_socket::init()
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
	case socket_proto_type::proto_tcp:
		type = SOCK_STREAM;
		protocol = IPPROTO_TCP;
		break;
	case socket_proto_type::proto_udp:
		type = SOCK_DGRAM;
		protocol = IPPROTO_UDP;
		break;
	case socket_proto_type::proto_raw:
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
		clean();
		return false;
	}

	if (!bind(_ip, _port))
	{
		clean();
		return false;
	}

	return true;
}
void base_socket::clean()
{
	if (_socket != INVALID_SOCKET)
		closesocket(_socket);

	if (_inited)
		WSACleanup();

	_ip = "";
	_port = 0;
	_protoType = socket_proto_type::proto_tcp;
	_socket = INVALID_SOCKET;
	_inited = false;
}
bool base_socket::bind(string ip, unsigned short port)
{
	if (!_inited && !init())
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

	if (::bind(_socket, (SOCKADDR*)&addr, len) == SOCKET_ERROR)
	{
		return false;
	}
	return true;
}
bool base_socket::connect(string ip,unsigned short port)
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

	if (SOCKET_ERROR == ::connect(_socket, (SOCKADDR*)&addr, len))
		return false;

	return true;
}
void base_socket::send(const std::string& msg)
{
	send(msg.c_str(), msg.length());
}
void base_socket::send(const char* msg, unsigned int length)
{

}
