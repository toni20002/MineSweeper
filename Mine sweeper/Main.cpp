#include "CEnemy.h"
#include "CPlayer.h"
#include "CBoard.h"
#include <iostream>

using namespace std;

int main() {
	CEnemy enemy(10, '!');
	cout << enemy << endl;
	CEnemy enemy2, enemy3;
	cout << enemy2 << endl;
	cout << enemy3 << endl;
	{
		CEnemy * penemy = new CEnemy();
		cout << *penemy << endl;

		if (penemy != nullptr) {
			delete penemy;
			penemy = nullptr;
		}
		penemy = new CEnemy(20, '?');
		cout << *penemy << endl;
		if (penemy != nullptr) {
			delete penemy;
			penemy = nullptr;
		}
	}

	CPlayer pesho(0, 4, true, "Pesho");
	cout << pesho << endl;
	cout << enemy << endl;
	cout << "Enter a player in the following order: name, lives, score , state " << endl;
	cin >> pesho;
	cout << pesho << endl;


	cout << enemy << endl;
	cout << "Enter an enemy in the order: count, icon " << endl;
	cin >> enemy;
	cout << enemy << endl;

	cout << "BOARD TEST" << endl;
	CBoard testBoard;
	testBoard.fillBoard();
	cout << testBoard;

	cout << "SECOND BOARD" << endl;
	CBoard secondBoard(4, 4);
	secondBoard.fillBoard();
	cout << secondBoard;
	testBoard = secondBoard;

	cout << "Changed test board - should be 4 by 4" << endl;
	cout << testBoard << endl;


	CBoard copyBoard = testBoard;
	cout << copyBoard;

	cout << "filled board" << endl;
	copyBoard.createBoard();
	cout << copyBoard;

	testBoard = copyBoard;
	cout << "Test board with the copied values of copyBoard" << endl;
	cout << testBoard;

	return 0;
}