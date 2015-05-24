#pragma once
#include <map>
#include "Singleton.h"
#include "Player.h"
using namespace std;

class PlayerManager : public Singleton<PlayerManager>
{
protected:
	friend Singleton<PlayerManager>;
	PlayerManager();
public:
	~PlayerManager();
	map<string, Player*>& getPlayerDatas();
	Player* getPlayerById(const string& id);
	void AddPlayer(Player* player);
	void RemovePlayer(const string& id);
	void RemovePlayer(Player* player);
private:
	map<string, Player*> _players;
	typedef map<string, Player*>::iterator mapIterator;
};

