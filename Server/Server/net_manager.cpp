#include "net_manager.h"
#include "socket_manager.h"

net_manager::net_manager()
{
}
net_manager::~net_manager()
{
}
void net_manager::send_message(const std::string& playerId, const std::string& msg)
{
	base_socket* bs = socket_manager::get_instance()->get_socket(playerId);
	if (bs != NULL)
		bs->send(msg);
}
void net_manager::send_message(const std::string& playerId, const char* msg, unsigned int length)
{
	base_socket* bs = socket_manager::get_instance()->get_socket(playerId);
	if (bs != NULL)
		bs->send(msg, length);
}
void net_manager::register_message(const std::string& id, callback_pvoid callback)
{
	if (_callbackmap.find(id) == _callbackmap.end())
	{
		_callbackmap[id] = callback;
	}
};
void net_manager::unregister_message(const std::string& id)
{
	callback_iterator& it = _callbackmap.find(id);
	if (it != _callbackmap.end())
	{
		_callbackmap.erase(it);
	}
};
