#pragma once

#include <iostream>

class CPlayer {

public:
	//default constructor
	CPlayer();
	
	CPlayer(const char *);
	CPlayer(unsigned, unsigned, bool, const char *);
	CPlayer(bool, const char *);
	CPlayer(const CPlayer&);

	CPlayer& operator=(const CPlayer&);

	~CPlayer();

	//Setters
	int setScore(unsigned);
	int	setLives(unsigned);
	int setState(bool);
	int setNick(const char *);

	//Getters

	unsigned getScore() const;
	unsigned getLives() const;
	bool getState() const;
	char * getNick() const;

	int print() const;

	std::ostream& ins(std::ostream&) const;
	std::istream& ext(std::istream&);

private:
	unsigned score;
	unsigned lives;
	bool state;
	char * nick;
};

std::ostream& operator<<(std::ostream&, const CPlayer&);
std::istream& operator>>(std::istream&, CPlayer&);
