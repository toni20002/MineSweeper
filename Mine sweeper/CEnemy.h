#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "CPlayer.h"

class CEnemy {
public: 
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
private:
	unsigned count;
	char icon;
};

 std::ostream& operator<<(std::ostream&, const CEnemy&);
 std::istream& operator>>(std::istream&, CEnemy&);

#endif
