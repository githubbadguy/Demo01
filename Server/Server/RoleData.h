#pragma once
#include <string>

using namespace std;

class RoleData
{
public:
	RoleData();
	virtual ~RoleData();

	const string& getId() const;
	void setId(const string& id);

	const string& getName() const;
	void setName(const string& name);

	unsigned int getLevel() const;
	void setLevel(unsigned int level);

	unsigned int getExp() const;
	void setExp(unsigned int exp);

	unsigned int getUpgradeExp() const;
	void setUpgradeExp(unsigned int upgradeexp);
protected:
	string id;//全局唯一id
	string name;//名称
	unsigned int level;//经验值
	unsigned int exp;//等级
	unsigned int upgradeexp;//升级当前等级需要的经验值
};

