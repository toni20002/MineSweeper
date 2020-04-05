#pragma once
#include "CEnemy.h"
#include <iostream>

class DeadlyEnemy : public CEnemy {
public:
	DeadlyEnemy();
	DeadlyEnemy(unsigned, char, int, int, unsigned);
	virtual ~DeadlyEnemy();
	DeadlyEnemy(const DeadlyEnemy&);
	DeadlyEnemy& operator=(const DeadlyEnemy&);
	//hw set and get and << >> - done
	int getSound() const;
	int getDuration() const;
	unsigned getPower() const;

	int setSound(int);
	int setDuration(int);
	int setPower(unsigned);

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
	virtual int poison(CPlayer&) const;
private:
	int sound;
	int duration;
	unsigned power;
};

//std::ostream& operator<<(std::ostream&, const DeadlyEnemy&);
//std::istream& operator>>(std::istream&, DeadlyEnemy&);