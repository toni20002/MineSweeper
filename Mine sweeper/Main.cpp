#include "Mine.h"
#include "Player.h"
#include <iostream>

using namespace std;

int main() {
/*	CMine mine;
	CMine mine1(20, '@');
	CMine mine2(22, '&');

	cout << "Mine default" << endl;
	cout << mine.getCount() << endl;
	cout << mine.getIcon() << endl;
	unsigned x;
	cin >> x;
	mine.setCount(x);
	cout << mine.getCount() << endl;
	cout << mine.getIcon() << endl;

	cout << mine1.getCount() << endl;
	cout << mine1.getIcon() << endl;

	cout << mine2.getCount() << endl;
	cout << mine2.getIcon() << endl;

	CMine * pointer = &mine;
	pointer->setIcon('~');
	cout << pointer->getCount() << endl;
	cout << pointer->getIcon() << endl;

	pointer = new CMine();
	if (pointer != nullptr) {
		delete pointer;
		pointer = nullptr;
	}

	pointer = new CMine(10, '!');
	cout << pointer->getCount() << endl;
	cout << pointer->getIcon() << endl;

	CMine defaultValue = CMine();
	cout << "The value of the default constructor is:" << endl;
	cout << defaultValue.getCount() << endl;
	cout << defaultValue.getIcon() << endl;*/
	/*CPlayer defaultPlayer;
	cout << defaultPlayer.getNick() << endl;
	cout << defaultPlayer.getLives() << endl;
	cout << defaultPlayer.getScore() << endl;
	cout << defaultPlayer.getState() << endl;

	int newScore;
	cout << "Enter the new score for the default player: ";
	cin >> newScore;

	defaultPlayer.setScore(newScore);
	cout << "The new score is: " << defaultPlayer.getScore() << endl;

	CPlayer player1("Jeko");
	cout << "Player1 : ";
	cout << player1.getNick() << endl;

	char * newNick = new char[15];
	cin.ignore();
	cin.getline(newNick, 15);
	player1.setNick(newNick);

	cout << "Player1's new nick is: " << player1.getNick() << endl;

	if (newNick != nullptr) {
		delete[] newNick;
		newNick = nullptr;
	}*/

	CPlayer pesho(0, 4, false, "Pesho");
	CPlayer ivan(pesho);

	pesho.print();
	ivan.print();
	//When we delete the delete[] in the setter we can actually change the name
	ivan.setNick("Ivan");
	ivan.setState(true);
	ivan.setLives(10);
	ivan.print();

	return 0;
}