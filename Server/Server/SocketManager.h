#pragma once
#include <map>
#include "BaseSocket.h"
#include "Singleton.h"

class SocketManager : public Singleton<SocketManager>
{
protected:
	friend Singleton<SocketManager>;
	SocketManager();
public:
	~SocketManager();
	void AddSocket(const std::string& id, BaseSocket* bs);
	void RemoveSocket(const std::string& id);
	BaseSocket* GetSocket(const std::string& id);
private:
	std::map<std::string, BaseSocket*> _socketmap;
	typedef std::map<std::string, BaseSocket*>::iterator SocketMapIterator;
};

