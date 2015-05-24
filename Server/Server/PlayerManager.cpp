#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}
PlayerManager::~PlayerManager()
{
}
map<string, Player*>& PlayerManager::getPlayerDatas()
{
	return _players;
}
Player* PlayerManager::getPlayerById(const string& id)
{
	if (_players.find(id) != _players.end())
	{
		return _players[id];
	}
	return NULL;
}
void PlayerManager::AddPlayer(Player* player)
{
	if (_players.find(player->getId()) != _players.end())
	{
		_players[player->getId()] = player;
	}
}
void PlayerManager::RemovePlayer(const string& id)
{
	mapIterator it = _players.find(id);
	if (it != _players.end())
	{
		Player* player = it->second;
		_players.erase(id);
		delete player;
	}
}
void PlayerManager::RemovePlayer(Player* player)
{
	mapIterator it = _players.find(player->getId());
	if (it != _players.end())
	{
		Player* player = it->second;
		_players.erase(player->getId());
		delete player;
	}
}
