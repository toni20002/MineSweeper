//Mine.h
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>

class CEnemy {
public: 
	friend std::ostream& operator<<(std::ostream&, const CEnemy&);
	friend std::istream& operator>>(std::istream&, CEnemy&);

	//constructors
	CEnemy();
	CEnemy(unsigned, char);

	//destructor
	~CEnemy();

	//Setters - mutators
	int setCount(unsigned);
	int setIcon(char);

	//Getters - accessors
	unsigned getCount() const;
	char getIcon() const;

private:
	unsigned count;
	char icon;

};

 std::ostream& operator<<(std::ostream&, const CEnemy&);
 std::istream& operator>>(std::istream&, CEnemy&);

#endif



