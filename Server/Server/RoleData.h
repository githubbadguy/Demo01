#pragma once
#include <string>

using namespace std;

class role_data
{
public:
	role_data();
	virtual ~role_data();

	const string& id() const;
	void id(const string& value);

	const string& name() const;
	void name(const string& value);

	unsigned int level() const;
	void level(unsigned int value);

	unsigned int experience() const;
	void experience(unsigned int value);

	unsigned int upgrade_experience() const;
	void upgrade_experience(unsigned int value);
protected:
	string _id;//全局唯一id
	string _name;//名称
	unsigned int _level;//经验值
	unsigned int _experience;//等级
	unsigned int _upgrade_experience;//升级当前等级需要的经验值
};

