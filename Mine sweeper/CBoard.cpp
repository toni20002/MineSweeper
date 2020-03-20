#include "CBoard.h"
#include <iostream>
#include <random>
#include <time.h>


//default
CBoard::CBoard():rows(5), columns(5) {
	viewBoard = new int *[rows];
	checkBoard = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		viewBoard[i] = new int[columns];
		checkBoard[i] = new int[columns];
	}
};

CBoard::CBoard(unsigned rows, unsigned columns) {
	this->rows = rows;
	this->columns = columns;

	viewBoard = new int*[rows];
	checkBoard = new int *[rows];
	if (rows > 0 && columns > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			viewBoard[i] = new int[columns];
			checkBoard[i] = new int[columns];
		}
	}

};

CBoard::~CBoard() {

	if (viewBoard != nullptr) {
		for (int i = 0; i<rows; i++) {
			delete[] viewBoard[i];
		}
		delete[] viewBoard;
	}

	if (checkBoard != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] checkBoard[i];
		}
		delete[] checkBoard;
	}
};

//Copy constructor
CBoard::CBoard(const CBoard & rhs) {
	std::cout << "Copy constructor invoked! " << std::endl;
	rows = rhs.rows;
	columns = rhs.columns;

	viewBoard = new int *[rhs.rows];
	checkBoard = new int *[rhs.rows];
	for (int i = 0; i < rhs.columns; i++)
	{
		viewBoard[i] = new int[rhs.columns];
		checkBoard[i] = new int[rhs.columns];
	}
	for (int l = 0; l < rows; l++)
	{
		for (int m = 0; m < columns; m++)
		{
			viewBoard[l][m] = rhs.viewBoard[l][m];
			checkBoard[l][m] = rhs.checkBoard[l][m];
		}
	}
}

CBoard& CBoard::operator=(const CBoard &rhs) {
	if (this != &rhs)
	{
		rows = rhs.rows;
		columns = rhs.columns;

		delete[] viewBoard;
		viewBoard = new int *[rows];

		delete[] checkBoard;
		checkBoard = new int *[rows];

		for (int i = 0; i < rhs.columns; i++)
		{
			viewBoard[i] = new int[rhs.columns];
			checkBoard[i] = new int[rhs.columns];
		}

	}
	for (int l = 0; l < rows; l++)
	{
		for (int m = 0; m < columns; m++)
		{
			viewBoard[l][m] = rhs.viewBoard[l][m];
			checkBoard[l][m] = rhs.checkBoard[l][m];
		}
	}

	return *this;
}

CBoard CBoard::createBoard()
{
	srand(time(NULL));
	int bombs;
	int randRow, randCol;

	if (rows < 9 && columns < 9)
	{
		bombs = rows;
	}
	for (int l = 0; l < bombs; l++)
	{
		randRow = rand() % rows + 0;
		randCol = rand() % columns + 0;

		if (viewBoard[randRow][randCol] != -1)
		{
			viewBoard[randRow][randCol] = -1;
		}
		else
		{
			randRow = rand() % rows + 0;
			randCol = rand() % columns + 0;
			viewBoard[randRow][randCol] = -1;
		}

	}

	return CBoard();
}

CBoard CBoard::fillBoard()
{
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < columns; k++)
		{
			viewBoard[i][k] = 0;
		}
	}
	return CBoard();
}

std::ostream & operator<<(std::ostream &out, const CBoard &rhs) {
	for (int i = 0; i < rhs.rows; i++)
	{
		for (int k = 0; k < rhs.columns; k++)
		{
			out << rhs.viewBoard[i][k] << "\t";
		}
		out << "\n";
	}

	return out;
}
