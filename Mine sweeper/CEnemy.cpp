#include "CEnemy.h"
#include <iostream>

CEnemy::CEnemy() {
	std::cout << "Default constructor called here!\n";
	count = rand() % 10 + 1;
	icon = '@';

};
CEnemy::CEnemy(unsigned count, char icon):icon(icon), count(count) {
	std::cout << "Constructor with parameters is called here!\n";
};

CEnemy::~CEnemy() { 
	std::cout << "Destructor called here!\n"; 
};


int CEnemy::setCount(unsigned count) {
	if (count != 0)
	{
		this->count = count;
	}
	else
	{
		this->count = 1;
	}
	return 0;
};
int CEnemy::setIcon(char icon) {
	this->icon = icon;
	return 0;
};

unsigned CEnemy::getCount() const {
	return count;
};
char CEnemy::getIcon() const {
	return icon;
};

std::ostream & operator<<(std::ostream &out, const CEnemy &rhs)
{
	out << "Count: " << rhs.count << std::endl;
	out << "Icon: " << rhs.icon << std::endl;

	return out;
}

std::istream & operator>>(std::istream &in, CEnemy &rhs)
{
	in >> rhs.count;
	in >> rhs.icon;

	return in;
}
