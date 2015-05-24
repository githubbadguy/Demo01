#include "NetManager.h"
#include "SocketManager.h"

NetManager::NetManager()
{
}
NetManager::~NetManager()
{
}
void NetManager::SendMsg(const std::string& playerId, const std::string& msg)
{
	BaseSocket* bs = SocketManager::GetInstance()->GetSocket(playerId);
	if (bs != NULL)
		bs->Send(msg);
}
void NetManager::SendMsg(const std::string& playerId, const char* msg, unsigned int length)
{
	BaseSocket* bs = SocketManager::GetInstance()->GetSocket(playerId);
	if (bs != NULL)
		bs->Send(msg,length);
}
void NetManager::RegisterMsg(const std::string& id, CallBackVoidP callback)
{
	if (_callbackmap.find(id) == _callbackmap.end())
	{
		_callbackmap[id] = callback;
	}
};
void NetManager::UnRegisterMsg(const std::string& id)
{
	CallBackIterator& it = _callbackmap.find(id);
	if (it != _callbackmap.end())
	{
		_callbackmap.erase(it);
	}
};
