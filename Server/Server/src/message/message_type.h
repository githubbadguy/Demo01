#ifndef _MESSAGE_TYPE_H
#define _MESSAGE_TYPE_H

enum main_message
{
	none_msg = 0,
	login_msg = 1,
	chat_msg = 2,
};

enum socket_proto_type
{
	proto_tcp,
	proto_udp,
	proto_raw,
};

#endif // _MESSAGE_TYPE_H

