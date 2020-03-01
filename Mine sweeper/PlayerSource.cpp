#include "Player.h";	
#include <iostream>
#include <cstring>

//Default constructor
CPlayer::CPlayer():lives(2), score(100), state(true), nick(new char[10]) {
	strcpy_s(nick, 10, "Goshko" );
}

//Basic - first constructor
CPlayer::CPlayer(const char * nick):lives(2), score(50), state(true), nick(new char[strlen(nick)+1]) {
	strcpy_s(this->nick, strlen(nick) + 1, nick);

}
CPlayer::CPlayer(unsigned lives, unsigned score, bool state, const char * nick):nick(new char[strlen(nick)+1]) {
	if (score >= 0)
	{
		this->score = score;
	}
	else
	{
		this->score = 0;
	}

	if (lives > 5)
	{
		this->lives = 5;
	}
	else
	{
		this->lives = lives;
	}
	if (lives > 0 && !state)
	{
		this->state = true;
	}
	else
	{
		this->state = state;
	}
	strcpy_s(this->nick, strlen(nick)+1 , nick);
}


CPlayer::CPlayer(bool state, const char * nick):state(true), nick(new char[strlen(nick)+1])	{
	strcpy_s(this->nick, strlen(nick) + 1, nick);
	if (!state)
	{
		this->state = true;
	}
	this->state = state;
}


//Copy constructor
CPlayer::CPlayer(const CPlayer& adder) {
//	nick = new char [strlen(nick) + 1];
	this->nick = adder.nick;
}

CPlayer& CPlayer::operator=(const CPlayer& rhs) {
	if (this != &rhs)
	{
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
	this->state = state;
	return 0;
}

int CPlayer::setNick(const char * nick) {
	/*if (nick != nullptr)
	{
		delete[] nick;
		nick = nullptr;
	}*/
	//this->nick = new char[strlen(nick) + 1];
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