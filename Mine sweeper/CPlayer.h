#pragma once

#include <iostream>
const enum playerState { Smiled = 0, Frown, Asleep, InAcoma, Dead };

class CPlayer {

public:
	//default constructor
	CPlayer();
	
	CPlayer(const char *);
	CPlayer(unsigned, unsigned, playerState, const char *);
	CPlayer(playerState, const char *);
	CPlayer(const CPlayer&);

	CPlayer& operator=(const CPlayer&);

	~CPlayer();

	//Setters
	int setScore(unsigned);
	int	setLives(unsigned);
	int setState(playerState);
	int setNick(const char *);

	//Getters

	unsigned getScore() const;
	unsigned getLives() const;
	playerState getState() const;
	char * getNick() const;

	int print() const;

	std::ostream& ins(std::ostream&) const;
	std::istream& ext(std::istream&);


private:
	unsigned score;
	unsigned lives;
	playerState state;
	char * nick;
};

std::ostream& operator<<(std::ostream&, const CPlayer&);
std::istream& operator>>(std::istream&, CPlayer&);
