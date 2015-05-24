#include "SocketManager.h"


SocketManager::SocketManager()
{
}
SocketManager::~SocketManager()
{
}
void SocketManager::AddSocket(const std::string& id, BaseSocket* bs)
{
	if (_socketmap.find(id) == _socketmap.end())
	{
		_socketmap[id] = bs;
	}
};
void SocketManager::RemoveSocket(const std::string& id)
{
	SocketMapIterator& it = _socketmap.find(id);
	if (it != _socketmap.end())
	{
		BaseSocket* p = it->second;
		_socketmap.erase(it);
		delete p;
	}
}
BaseSocket* SocketManager::GetSocket(const std::string& id)
{
	SocketMapIterator& it = _socketmap.find(id);
	if (it != _socketmap.end())
	{
		return it->second;
	}
	return NULL;
}
