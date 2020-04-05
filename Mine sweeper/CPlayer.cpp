#include "CPlayer.h";	
#include <iostream>
#include <cstring>

//Default constructor
CPlayer::CPlayer():lives(2), score(0), state(true), nick(new char[10]) {
	strcpy_s(nick, 10, "Goshko" );
}

//Basic - first constructor
CPlayer::CPlayer(const char * nick):lives(2), score(0), state(true), nick(new char[strlen(nick)+1]) {
	strcpy_s(this->nick, strlen(nick) + 1, nick);

}
CPlayer::CPlayer(unsigned lives, unsigned score, bool state, const char * nick):nick(new char[strlen(nick)+1]) {
	this->score = (score >= 0) ? score : 0;
	this->lives = (lives <= 5) ? lives : 5;
	this->state = (lives > 0 && !state) ? true : state;
	strcpy_s(this->nick, strlen(nick)+1 , nick);
}


CPlayer::CPlayer(bool state, const char * nick):nick(new char[strlen(nick)+1]), score(0), lives(2) {
	strcpy_s(this->nick, strlen(nick) + 1, nick);
	if (!state)
	{
		this->state = true;
	}
	this->state = state;
}


//Copy constructor
CPlayer::CPlayer(const CPlayer& rhs):score(rhs.score), lives(rhs.lives), state(rhs.state) {
	nick = new char [strlen(rhs.nick) + 1];
	strcpy_s(nick, strlen(rhs.nick) + 1, rhs.nick);

}

CPlayer& CPlayer::operator=(const CPlayer& rhs) {
	if (this != &rhs)
	{
		/*delete[] nick;
		nick = new char[strlen(rhs.nick) + 1];
		strcpy_s(nick, strlen(rhs.nick) + 1, rhs.nick);*/
		this->setNick(rhs.nick);
		score = rhs.score;
		lives = rhs.lives;
		state = rhs.state;
	}

	return *this;
}

//Deconstructor
CPlayer::~CPlayer() {
	if (nick != nullptr)
	{
		delete[] nick;
		nick = nullptr;
	}
}

//Setters
int CPlayer::setScore(unsigned score) {
	this->score = score;
	return 0;
}
int CPlayer::setLives(unsigned lives) {
	this->lives = lives;
	return 0;
}
int CPlayer::setState(bool state) {
	if (!state && lives == 0) this->state = state;
	this->state = state;
	return 0;
}

int CPlayer::setNick(const char * nick) {
	if (this->nick != nullptr)
	{
		delete[] this->nick;
		this->nick = nullptr;
	}
	this->nick = new char[strlen(nick) + 1];
	strcpy_s(this->nick, strlen(nick) + 1, nick);
	return 0;
}

//Getters
unsigned CPlayer::getScore() const {
	return score;
}

unsigned CPlayer::getLives() const {
	return lives;
}

bool CPlayer::getState() const {
	return state;
}

char * CPlayer::getNick() const {
	return nick;
}

int CPlayer::print() const {
	std::cout << "Nick: " << nick << std::endl;
	std::cout << "Lives: " << lives << std::endl;
	std::cout << "Score: " << score << std::endl;
	std::cout << "State: " << (state ? ":-)" : ":-(") << std::endl;
	return 0;
}
std::ostream& CPlayer::ins(std::ostream& out) const {
	return out << "Nick: " << nick << std::endl
		<< "Lives: " << lives << std::endl
		<< "Score: " << score << std::endl
		<< "State: " << (state ? ":-P" : ":-(") << std::endl;

}

std::istream& CPlayer::ext(std::istream& in) {
	char * name = new char[30];
	in >> name;
	setNick(name);
	in >> lives >> score >> state;
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const CPlayer& rhs) {
	return rhs.ins(out);
}

std::istream& operator>>(std::istream& in, CPlayer& rhs) {
	return rhs.ext(in);
}

