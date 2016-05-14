#include "playermanager.h"


player_manager::player_manager()
{
}
player_manager::~player_manager()
{
}
map<string, player*>& player_manager::get_player_datas()
{
	return _players;
}
player* player_manager::get_player_by_id(const string& id)
{
	if (_players.find(id) != _players.end())
	{
		return _players[id];
	}
	return NULL;
}
void player_manager::add_player(player* player)
{
	if (_players.find(player->id()) != _players.end())
	{
		_players[player->id()] = player;
	}
}
void player_manager::remove_player(const string& id)
{
	map_iterator it = _players.find(id);
	if (it != _players.end())
	{
		player* player = it->second;
		_players.erase(id);
		delete player;
	}
}
void player_manager::remove_player(player* p)
{
	map_iterator it = _players.find(p->id());
	if (it != _players.end())
	{
		_players.erase(p->id());
		delete p;
	}
}
