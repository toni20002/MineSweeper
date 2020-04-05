#pragma once

#include <iostream>
#include "CEnemy.h"
#include "DeadlyEnemy.h"
#include "SuperDeadlyEnemy.h"

class CBoard {
	
	friend std::ostream& operator<<(std::ostream&, const CBoard&);

public:
	CBoard();
	CBoard(unsigned);
	CBoard(unsigned, unsigned);
	CBoard(unsigned, unsigned, unsigned);
	~CBoard();
	CBoard(const CBoard&);

	CBoard& operator=(const CBoard&);
	int createBoard(unsigned, unsigned, unsigned);
	int createBoardWithEnemies(unsigned, unsigned, unsigned);

	//getters
	unsigned getColumns() const;
	unsigned getRows() const;
	unsigned getCountEnemy() const;
	int ** getViewBoard() const;
	int ** getCheckBoard() const;

	//setters
	int setColumns(unsigned);
	int setRows(unsigned);
	int setCountEnemy(unsigned);

	
private:
	int ** viewBoard;
	int ** checkBoard;
	unsigned columns, rows, countEnemy;
	unsigned countEnemy;
	CEnemy ** enemies; // dynamic array of pointers
};


std::ostream& operator<<(std::ostream & , const CBoard&);
std::istream& operator>>(std::istream&, CBoard&);

