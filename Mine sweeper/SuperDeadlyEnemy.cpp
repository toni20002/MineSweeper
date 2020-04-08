#include "SuperDeadlyEnemy.h"
SuperDeadlyEnemy::SuperDeadlyEnemy():DeadlyEnemy(), multiPower(100) {}

SuperDeadlyEnemy::SuperDeadlyEnemy(unsigned count, char icon, int sound, int duration, unsigned power, int multiPower) : DeadlyEnemy(count, icon, sound, duration, power)
, multiPower(multiPower) {}

SuperDeadlyEnemy::SuperDeadlyEnemy(const SuperDeadlyEnemy& rhs):DeadlyEnemy(rhs), multiPower(rhs.multiPower) {
}
SuperDeadlyEnemy::~SuperDeadlyEnemy() {
	std::cout << "SuperDeadlyEnemy destructor invoked! \n";
}

SuperDeadlyEnemy& SuperDeadlyEnemy::operator=(const SuperDeadlyEnemy& rhs) {
	if (this != &rhs)
	{
		DeadlyEnemy::operator=(rhs);
		multiPower = rhs.multiPower;
	}
	return *this;
}

std::ostream& SuperDeadlyEnemy::ins(std::ostream& out) const {
	DeadlyEnemy::ins(out);
	return out << "Multiply power: " << multiPower << std::endl;
}
std::istream& SuperDeadlyEnemy::ext(std::istream& in) {
	DeadlyEnemy::ext(in);
	in >> multiPower;
	return in;
}

int SuperDeadlyEnemy::getMultiPower() const {
	return multiPower;
}
int SuperDeadlyEnemy::setMultiPower(int multiPower) {
	this->multiPower = multiPower;
	return 0;
}
//virtual functions 
int SuperDeadlyEnemy::poison(CPlayer& player)const {
	player.setState(Dead);
	player.setLives(0);
	player.setScore(player.getScore() - 10);
	return 0;
}
int SuperDeadlyEnemy::eliminate(CPlayer& player) const {
	player.setLives(player.getLives() + 3);
	return 0;
}
