#pragma once

#include <iostream>

class CBoard {
	
	friend std::ostream& operator<<(std::ostream&, const CBoard&);

public:
	CBoard();
	CBoard(unsigned, unsigned);
	~CBoard();
	CBoard(const CBoard&);

	CBoard& operator=(const CBoard&);
	CBoard createBoard();
	CBoard fillBoard();

private:
	int ** viewBoard;
	int ** checkBoard;
	unsigned columns, rows;
};


std::ostream& operator<<(std::ostream & , const CBoard&);


