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
	string id;//ȫ��Ψһid
	string name;//����
	unsigned int level;//����ֵ
	unsigned int exp;//�ȼ�
	unsigned int upgradeexp;//������ǰ�ȼ���Ҫ�ľ���ֵ
};

