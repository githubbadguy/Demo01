#include "socket_manager.h"


socket_manager::socket_manager()
{
}
socket_manager::~socket_manager()
{
}
void socket_manager::add_socket(const std::string& id, base_socket* bs)
{
	if (_socketmap.find(id) == _socketmap.end())
	{
		_socketmap[id] = bs;
	}
};
void socket_manager::remove_socket(const std::string& id)
{
	socket_map_iterator& it = _socketmap.find(id);
	if (it != _socketmap.end())
	{
		base_socket* p = it->second;
		_socketmap.erase(it);
		delete p;
	}
}
base_socket* socket_manager::get_socket(const std::string& id)
{
	socket_map_iterator& it = _socketmap.find(id);
	if (it != _socketmap.end())
	{
		return it->second;
	}
	return NULL;
}
