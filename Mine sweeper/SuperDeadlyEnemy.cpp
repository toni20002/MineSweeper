#include "SuperDeadlyEnemy.h"
SuperDeadlyEnemy::SuperDeadlyEnemy():DeadlyEnemy() {}

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

int SuperDeadlyEnemy::poison(CPlayer& player)const {
	player.setState(false);
	player.setLives(0);
	player.setScore(player.getScore() - 10);
	return 0;
}


int SuperDeadlyEnemy::getMultiPower() const {
	return multiPower;
}
int SuperDeadlyEnemy::setMultiPower(int multiPower) {
	this->multiPower = multiPower;
}