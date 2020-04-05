#include "DeadlyEnemy.h"

DeadlyEnemy::DeadlyEnemy() :CEnemy(), sound(500), duration(1000), power(2) {};
DeadlyEnemy::DeadlyEnemy(unsigned count, char icon, int sound, int duration, unsigned power) : CEnemy(count, icon), sound(sound),
duration(duration), power(power) {};

DeadlyEnemy::DeadlyEnemy(const DeadlyEnemy& rhs):CEnemy(rhs){
	sound = rhs.sound;
	duration = rhs.duration;
	power = rhs.power;

};

DeadlyEnemy::~DeadlyEnemy() {
	std::cout << "DeadlyEnemy destructor called! \n";
};
DeadlyEnemy& DeadlyEnemy::operator=(const DeadlyEnemy& rhs) {
	if (this != &rhs)
	{
		CEnemy::operator=(rhs);
		this->sound = sound;
		this->duration = duration;
		this->power = power;
	}
	return *this;
};
int DeadlyEnemy::getSound() const {
	return sound;
}
int DeadlyEnemy::getDuration() const {
	return duration;
}
unsigned DeadlyEnemy::getPower() const {
	return power;
}

int DeadlyEnemy::setSound(int sound) {
	this->sound = sound;
	
	return 0;
}
int DeadlyEnemy::setDuration(int duration) {
	this->duration = duration;
	return 0;
}
int DeadlyEnemy::setPower(unsigned power) {
	this->power = power;
	return 0;
}
std::ostream& DeadlyEnemy::ins(std::ostream& out) const {
	CEnemy::ins(out);
	return out << "sound: " << sound << std::endl
		<< "Duration: " << duration << std::endl
		<< "Power: " << power << std::endl;

}
std::istream& DeadlyEnemy::ext(std::istream& in) {
	CEnemy::ext(in);
	in >> sound >> duration >> power;
	return in;
}

int DeadlyEnemy::poison(CPlayer& player) const {
	player.setState(false);
	player.setLives(player.getLives() - 1);
	return 0;
}


/*std::ostream & operator<<(std::ostream & out, const DeadlyEnemy &rhs){
	out << "Icon: " << rhs.getIcon() << "\n";
	out << "Count: " << rhs.getCount() << "\n";
	out << "Sound: " << rhs.getSound() << "\n";
	out << "Duration: " << rhs.getDuration() << "\n";
	out << "Power: " << rhs.getPower() << "\n";
	return out;
}
std::istream& operator>>(std::istream& in, DeadlyEnemy& rhs) {
	char icon; int count, sound, duration; unsigned power;
	in >> icon;
	rhs.setIcon(icon);
	in >> count;
	rhs.setCount(count);
	in >> sound;
	rhs.setSound(sound);
	in >> duration;
	rhs.setDuration(duration);
	in >> power;
	rhs.setPower(power);


	return in;
}*/