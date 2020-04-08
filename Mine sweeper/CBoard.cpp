#include "CBoard.h"
#include <iostream>
#include <random>
#include <time.h>
#include <typeinfo>


//default
	
CBoard::CBoard():rows(5), columns(5), viewBoard(new int *[5]), checkBoard(new int *[5]) {

	for (int i = 0; i < rows; i++)
	{
		viewBoard[i] = new int[columns];
		checkBoard[i] = new int[columns];
	}
};
CBoard::CBoard(unsigned rows) :rows(rows), columns(5), viewBoard(new int*[5]), checkBoard(new int*[5]) {
	for (int i = 0; i < rows; i++)
	{
		viewBoard[i] = new int[columns];
		checkBoard[i] = new int[columns];
	}
}
CBoard::CBoard(unsigned rows, unsigned columns):rows(rows), columns(columns) {
	//this->rows = rows;
//	this->columns = columns;

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
//TODO - done
CBoard::CBoard(unsigned rows, unsigned columns, unsigned countEnemies):rows(rows), columns(columns), countEnemy(countEnemies) {
	viewBoard = new int *[rows];
	checkBoard = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		viewBoard[i] = new int[columns];
		checkBoard[i] = new int[columns];
	}
}


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

	if (enemies != nullptr)
	{
		for (int i = 0; i < countEnemy; i++)
		{
			delete[] enemies[i];
		}
		delete[] enemies;
		enemies = nullptr;
	}
};

//Copy constructor
CBoard::CBoard(const CBoard & rhs) {
	std::cout << "Copy constructor for CBoard invoked! " << std::endl;
	rows = rhs.rows;
	columns = rhs.columns;
	countEnemy = rhs.countEnemy;

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
	enemies = new CEnemy *[rhs.countEnemy];
	for (int i = 0; i < rhs.countEnemy; i++)
	{
		enemies[i] = new CEnemy();
	//	enemies[i] = rhs.enemies[i];
	}
}

CBoard& CBoard::operator=(const CBoard &rhs) {
	if (this != &rhs)
	{
		rows = rhs.rows;
		columns = rhs.columns;
		countEnemy = rhs.countEnemy;

		delete[] viewBoard;
		viewBoard = new int *[rows];

		delete[] checkBoard;
		checkBoard = new int *[rows];

		delete[] enemies;
		enemies = new CEnemy*[countEnemy];
		for (int i = 0; i < rhs.countEnemy; i++)
		{
			enemies[i] = new CEnemy();
		}

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

int CBoard::createBoard(unsigned rows, unsigned columns, unsigned countEnemy)
{
	if (viewBoard != NULL)
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete[] viewBoard[i];
		}
		delete[] viewBoard;
	}
	if (checkBoard != NULL)
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete[] checkBoard[i];
		}
		delete[] checkBoard;
	}
	this->rows = rows;
	this->columns = columns;
	this->countEnemy = countEnemy;

	viewBoard = new int*[rows];
	checkBoard = new int *[rows];
		for (int i = 0; i < rows; i++)
		{
			viewBoard[i] = new int[columns] {0};
			checkBoard[i] = new int[columns] {0};
		}


	srand(time(NULL));
	int randRow, randCol;
	int enemyOnField = 0;
	while (enemyOnField < countEnemy)
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
		enemyOnField++;
	}

	enemyOnField = 0;
	for (int k = 0; k < rows; k++)
	{
		for (int l = 0; l < columns; l++)
		{
			if (viewBoard[k][l] == -1)
			{
				for (int ii = ((k == 0) ? k : k -1); ii <= ((k == rows-1) ? k: k+1); ii++)
				{
					for (int jj = ((l == 0) ? l : l - 1); jj <= ((l == columns - 1) ? l : l +1); jj++)
					{
						if (viewBoard[ii][jj] != -1)
						{
							viewBoard[ii][jj]++;
						}
					}
				}
				enemyOnField++;
			}
			if (enemyOnField == countEnemy)
			{
				return 0;
			}
		}
	}

	return 0;
}

int CBoard::createBoardWithEnemies(unsigned rows, unsigned columns, unsigned countEnemy) {
	if (viewBoard != NULL)
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete[] viewBoard[i];
		}
		delete[] viewBoard;
	}
	if (checkBoard != NULL)
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete[] checkBoard[i];
		}
		delete[] checkBoard;
	}
	this->rows = rows;
	this->columns = columns;

	viewBoard = new int*[rows];
	checkBoard = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		viewBoard[i] = new int[columns] {0};
		checkBoard[i] = new int[columns] {0};
	}

	srand(time(NULL));
	int randRow, randCol;
	int enemyOnField = 0;
	
	if (enemies != nullptr)
	{
		for (int i = 0; i < countEnemy; i++)
		{
			delete enemies[i];
		}
		delete[] enemies;
	}
	this->countEnemy = countEnemy;

	//polimporphic container
	enemies = new CEnemy*[countEnemy];
	for (int i = 0; i < countEnemy; i++)
	{
		switch (rand() % 3) {
		case 0: enemies[i] = new CEnemy();
			break;
		case 1: enemies[i] = new DeadlyEnemy();
			break;
		case 2: enemies[i] = new SuperDeadlyEnemy();
			break;
		}
	}
	unsigned index = 0;
	while (enemyOnField < countEnemy)
	{
		randRow = rand() % rows + 0;
		randCol = rand() % columns + 0;

		if (viewBoard[randRow][randCol] != -1 && viewBoard[randRow][randCol] != -2 && viewBoard[randRow][randCol] != -3)
		{
			//if (dynamic_cast<CEnemy*>(enemies[index]) != NULL)
			//std::cout << typeid(*enemies[index]).name();
		//	std::cout << typeid(SuperDeadlyEnemy).name();
			
			if (typeid(CEnemy) == typeid(*enemies[index]))
			{
				viewBoard[randRow][randCol] = -1;
			}
			if (typeid(DeadlyEnemy)== typeid(*enemies[index]))
			{
				viewBoard[randRow][randCol] = -2;
			}
			if (typeid(SuperDeadlyEnemy) == typeid(*enemies[index]))
			{
				viewBoard[randRow][randCol] = -3;
			}
		}
		else
		{
			randRow = rand() % rows + 0;
			randCol = rand() % columns + 0;
			if (dynamic_cast<CEnemy*>(enemies[index]) != NULL)
			{
				viewBoard[randRow][randCol] = -1;
			}
			if (typeid(DeadlyEnemy*) == typeid(enemies[index]))
			{
				viewBoard[randRow][randCol] = -2;
			}
			if (typeid(SuperDeadlyEnemy*) == typeid(enemies[index]))
			{
				viewBoard[randRow][randCol] = -3;
			}
		}
		index++;
		enemyOnField++;
	}

	enemyOnField = 0;
	for (int k = 0; k < rows; k++)
	{
		for (int l = 0; l < columns; l++)
		{
			if (viewBoard[k][l] == -1 || viewBoard[k][l] == -2 || viewBoard[k][l] == -3)
			{
				for (int ii = ((k == 0) ? k : k - 1); ii <= ((k == rows - 1) ? k : k + 1); ii++)
				{
					for (int jj = ((l == 0) ? l : l - 1); jj <= ((l == columns - 1) ? l : l + 1); jj++)
					{
						if (viewBoard[ii][jj] != -1 && viewBoard[ii][jj] != -2 && viewBoard[ii][jj] != -3)
						{
							viewBoard[ii][jj]++;
						}
					}
				}
				enemyOnField++;
			}
			if (enemyOnField == countEnemy)
			{
				return 0;
			}
		}
	}
	return 0;
}

//getters
unsigned CBoard::getColumns() const {
	return columns;
}
unsigned CBoard::getRows() const {
	return rows;
}
unsigned CBoard::getCountEnemy() const {
	return countEnemy;
}
int ** CBoard::getViewBoard() const {
	return viewBoard;
}
int ** CBoard::getCheckBoard() const {
	return checkBoard;
}

//setters
int CBoard::setColumns(unsigned cols) {
	if (cols > 0)
	{
		this->columns = cols;
	}
	return 0;
}
int CBoard::setRows(unsigned rows) {
	if (rows > 0)
	{
		this->rows = rows;
	}
	return 0;
}
int CBoard::setCountEnemy(unsigned countEnemy) {
	this->countEnemy = countEnemy;
	return 0;
}
std::ostream& CBoard::ins(std::ostream& out) const {
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < columns; k++)
		{
			 out << viewBoard[i][k] << "\t";
		}
		 out << "\n";
	}
	return out;
}
std::istream& CBoard::ext(std::istream& in) {
	unsigned rows, cols, enemies;
	in >> rows;
	in >> cols;
	in >> enemies;

	setRows(rows);
	setColumns(cols);
	setCountEnemy(enemies);

	return in;
}

std::ostream & operator<<(std::ostream &out, const CBoard &rhs) {
	/*for (int i = 0; i < rhs.rows; i++)
	{
		for (int k = 0; k < rhs.columns; k++)
		{
			out << rhs.viewBoard[i][k] << "\t";
		}
		out << "\n";
	}*/
	return rhs.ins(out);
}
std::istream& operator>>(std::istream& in, CBoard& rhs) {
	

	return rhs.ext(in);
}
