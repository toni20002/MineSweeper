#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "CPlayer.h"

class CEnemy {
public: 
	static int instancesCount;

	//constructors
	CEnemy();
	CEnemy(unsigned);
	CEnemy(unsigned, char);
	//copy constructor
	CEnemy(const CEnemy&);
	CEnemy& operator=(const CEnemy&);
	//destructor
	virtual ~CEnemy();

	//Setters - mutators
	int setCount(unsigned);
	int setIcon(char);

	//Getters - accessors
	unsigned getCount() const;
	char getIcon() const;

	CEnemy operator+(const CEnemy&);
	virtual	std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
	virtual int poison(CPlayer&) const;
	//when we eliminate an enemy we get +1 life , deadlyEnemy - +2 lives, superDeadlyEnemy - +3 lives and additional functionality
	virtual int eliminate(CPlayer&) const;

	int getInstances() const;
	int setInstances(int);

private:
	unsigned count;
	char icon;
	//to do - static data member that counts the instances of CEnemy and its descendants.

};
//int CEnemy::instancesCount = 0;

 std::ostream& operator<<(std::ostream&, const CEnemy&);
 std::istream& operator>>(std::istream&, CEnemy&);

#endif
