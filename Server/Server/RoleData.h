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
	string _id;//ȫ��Ψһid
	string _name;//����
	unsigned int _level;//����ֵ
	unsigned int _experience;//�ȼ�
	unsigned int _upgrade_experience;//������ǰ�ȼ���Ҫ�ľ���ֵ
};

