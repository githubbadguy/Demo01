#pragma once
#include <vector>
#include <string>
#include <map>
#include "singleton.h"
#include "CallBack.h"


class net_manager : public singleton<net_manager>
{
protected:
	friend singleton<net_manager>;
	net_manager();
public:
	~net_manager();
	void send_message(const std::string& playerId, const std::string& msg);
	void send_message(const std::string& playerId, const char* msg, unsigned int length);
	void register_message(const std::string& id, callback_pvoid callback);
	void unregister_message(const std::string& id);
private:
	std::map<std::string, callback_pvoid> _callbackmap;
	typedef std::map<std::string, callback_pvoid>::iterator callback_iterator;
};

