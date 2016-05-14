#pragma once
#include <map>
#include "singleton.h"
#include "Player.h"
using namespace std;

class player_manager : public singleton<player_manager>
{
protected:
	friend singleton<player_manager>;
	player_manager();
public:
	~player_manager();
	map<string, player*>& get_player_datas();
	player* get_player_by_id(const string& id);
	void add_player(player* player);
	void remove_player(const string& id);
	void remove_player(player* player);
private:
	map<string, player*> _players;
	typedef map<string, player*>::iterator map_iterator;
};

