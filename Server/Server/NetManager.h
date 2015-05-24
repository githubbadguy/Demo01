#pragma once
#include <vector>
#include <string>
#include <map>
#include "Singleton.h"
#include "CallBack.h"


class NetManager : public Singleton<NetManager>
{
protected:
	friend Singleton<NetManager>;
	NetManager();
public:
	~NetManager();
	void SendMsg(const std::string& playerId, const std::string& msg);
	void SendMsg(const std::string& playerId, const char* msg, unsigned int length);
	void RegisterMsg(const std::string& id, CallBackVoidP callback);
	void UnRegisterMsg(const std::string& id);
private:
	std::map<std::string, CallBackVoidP> _callbackmap;
	typedef std::map<std::string, CallBackVoidP>::iterator CallBackIterator;
};

