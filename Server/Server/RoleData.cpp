#include "RoleData.h"


RoleData::RoleData()
{
}

RoleData::~RoleData()
{
}
const string& RoleData::getId() const
{
	return id;
}
void RoleData::setId(const string& id)
{
	this->id = id;
}
const string& RoleData::getName() const
{
	return name;
}
void RoleData::setName(const string& name)
{
	this->name = name;
}
unsigned int RoleData::getLevel() const
{
	return level;
}
void RoleData::setLevel(unsigned int level)
{
	this->level = level;
}
unsigned int RoleData::getExp() const
{
	return exp;
}
void RoleData::setExp(unsigned int exp)
{
	this->exp = exp;
}
unsigned int RoleData::getUpgradeExp() const
{
	return upgradeexp;
}
void RoleData::setUpgradeExp(unsigned int upgradeexp)
{
	this->upgradeexp = upgradeexp;
}
