#include "CEnemy.h"
#include <iostream>

CEnemy::CEnemy() {
	std::cout << "Default constructor called here!\n";
	count = rand() % 10 + 1;
	icon = '@';

};

CEnemy::CEnemy(unsigned count):count(count),icon('*') {
}

CEnemy::CEnemy(unsigned count, char icon):icon(icon), count(count) {
	std::cout << "Constructor with parameters is called here!\n";
};

CEnemy::CEnemy(const CEnemy& rhs) {
	icon = rhs.icon;
	count = rhs.count;
};
CEnemy& CEnemy::operator=(const CEnemy& rhs) {
	if (this != &rhs)
	{
		icon = rhs.icon;
		count = rhs.count;
	}
	return *this;
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
CEnemy CEnemy::operator+(const CEnemy& rhs) {

}
std::ostream& CEnemy::ins(std::ostream& out) const {
	return out << "Count: " << count << std::endl
		<< "Icon: " << icon << std::endl;
}
std::istream& CEnemy::ext(std::istream& in) {
	unsigned cnt;
	char i;
	in >> cnt >> i;
	setCount(cnt);
	setIcon(i);
	return in;

}

std::ostream & operator<<(std::ostream &out, const CEnemy &rhs){
	return rhs.ins(out);
}

std::istream & operator>>(std::istream &in, CEnemy &rhs){
	return rhs.ext(in);
}

int CEnemy::poison(CPlayer& player) const {
	player.setState(false);
	return 0;
}