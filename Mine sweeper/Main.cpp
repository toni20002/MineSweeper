#include "CEnemy.h"
#include "CPlayer.h"
#include "CBoard.h"
#include "DeadlyEnemy.h"
#include <iostream>

using namespace std;

int main() {
/*	CEnemy enemy(10, '!');
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
	//testBoard.fillBoard();
	cout << testBoard;

	cout << "SECOND BOARD" << endl;
	CBoard secondBoard(4, 4);
	//secondBoard.fillBoard();
	cout << secondBoard;
	testBoard = secondBoard;

	cout << "Changed test board - should be 4 by 4" << endl;
	cout << testBoard << endl;


	CBoard copyBoard = testBoard;
	cout << copyBoard;

	cout << "filled board" << endl;
	copyBoard.createBoard(9,9,9);
	cout << copyBoard;

	testBoard = copyBoard;
	cout << "Test board with the copied values of copyBoard" << endl;
	cout << testBoard;

	DeadlyEnemy dEnemy;
	cout << dEnemy;
	DeadlyEnemy dEenem2(20, '%', 100, 100, 100);
	cout << dEenem2;
	cout << "Enter deadly enemy in the order: icon, count, sound, duration, power" << endl;
	cin >> dEenem2;
	cout << dEenem2;

	cout << "Enter board" << endl;
	CBoard bbb;
	cout << "BBB before createBoard: " << endl;
	bbb.createBoard(6, 6, 6);
	cout << bbb;

	cin >> bbb;
	bbb.createBoard(bbb.getRows(), bbb.getColumns(), bbb.getCountEnemy());
	cout << "BBB after createBoard: " << endl;
	cout << bbb;*/
	/*CBoard board;
	 board.createBoardWithEnemies(5,5,5);
	 cout << board;
	 CBoard board2;
	 board2 = board;
	 cout << board2;*/
/*	 CPlayer player1;
	 cin >> player1;
	// player1.setState(Dead);
	 //cout << player1.getState() << endl;
	 cout << player1;*/

	CEnemy enemy;
	CEnemy enemy2(20, 'K');
	DeadlyEnemy dEnemy;
	SuperDeadlyEnemy sdEnemy;
	cout << enemy2.getInstances() << endl;
	return 0;
}