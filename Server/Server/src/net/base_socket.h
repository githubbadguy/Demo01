#pragma once
#include <string>
#include <winsock.h>
#include "../message/message_type.h"

#pragma comment(lib,"wsock32.lib")


class base_socket
{
private:
	SOCKET _socket;
	socket_proto_type _protoType;
	std::string _ip;
	unsigned short _port;
	bool _inited;
public:
	base_socket();
	virtual ~base_socket();
	base_socket(std::string ip, unsigned short port, socket_proto_type prototype = socket_proto_type::proto_tcp);
	bool bind(std::string ip, unsigned short port);
	bool connect(std::string ip, unsigned short port);

	void send(const std::string& msg);
	void send(const char* msg, unsigned int length);
protected:
	bool init();
	void clean();
};

