//Mine.h
#ifndef MINE_H
#define MINE_H

class CMine {
public: 
	//constructors
	CMine();
	CMine(unsigned, char);

	//destructor
	~CMine();

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
#endif



