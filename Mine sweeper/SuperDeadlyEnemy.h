#pragma once
#include "DeadlyEnemy.h"
#include <iostream>
class SuperDeadlyEnemy : public DeadlyEnemy {
public:
	SuperDeadlyEnemy();
	SuperDeadlyEnemy(unsigned, char, int, int, unsigned, int);
	SuperDeadlyEnemy(const SuperDeadlyEnemy&);
	virtual ~SuperDeadlyEnemy();

	SuperDeadlyEnemy& operator=(const SuperDeadlyEnemy&);

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
	virtual int poison(CPlayer&)const;
	virtual int eliminate(CPlayer&) const;

	int getMultiPower() const;
	int setMultiPower(int);
private:
	int multiPower;
};

