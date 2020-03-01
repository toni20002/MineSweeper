#pragma once
class CPlayer {

public:
	//default constructor
	CPlayer();
	
	CPlayer(const char *);
	CPlayer(unsigned, unsigned, bool, const char *);
	CPlayer(bool, const char *);

	CPlayer& operator=(const CPlayer&);
	CPlayer(const CPlayer&);

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

private:
	unsigned score;
	unsigned lives;
	bool state;
	char * nick;
};