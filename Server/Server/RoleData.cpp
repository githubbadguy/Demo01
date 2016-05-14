#include "roledata.h"


role_data::role_data()
{
}

role_data::~role_data()
{
}
const string& role_data::id() const
{
	return _id;
}
void role_data::id(const string& value)
{
	_id = value;
}
const string& role_data::name() const
{
	return _name;
}
void role_data::name(const string& value)
{
	_name = value;
}
unsigned int role_data::level() const
{
	return _level;
}
void role_data::level(unsigned int value)
{
	_level = value;
}
unsigned int role_data::experience() const
{
	return _experience;
}
void role_data::experience(unsigned int value)
{
	_experience = value;
}
unsigned int role_data::upgrade_experience() const
{
	return _upgrade_experience;
}
void role_data::upgrade_experience(unsigned int value)
{
	_upgrade_experience = value;
}
