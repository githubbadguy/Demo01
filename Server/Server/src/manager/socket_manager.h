#pragma once
#include <map>
#include "../net/base_socket.h"
#include "../base/singleton.h"

class socket_manager : public singleton<socket_manager>
{
protected:
	friend singleton<socket_manager>;
	socket_manager();
public:
	~socket_manager();
	void add_socket(const std::string& id, base_socket* bs);
	void remove_socket(const std::string& id);
	base_socket* get_socket(const std::string& id);
private:
	std::map<std::string, base_socket*> _socketmap;
	typedef std::map<std::string, base_socket*>::iterator socket_map_iterator;
};

