/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 8, 2021
 *
 */

#include "Game.hpp"

Game::Game() {
	p1 = getNewPlayer();	// Initialize Player 1
}

Player*
Game::getNewPlayer() {
	string pName;
	int pColor;
	numOfPlayers++;	// Increase current number of players in-game

	cout << "[Player " << numOfPlayers << "] Enter your name: ";
	cin >> pName;
	cout << "\n1. Orange, 2. Yellow, 3. Green, 4. Blue" << endl;
	cout << "[Player " << numOfPlayers << "] Pick a color by inputting a number: ";
	cin >> pColor;

	while ( pColor < 1 || pColor > 4 ) {
		cout << "\nInvalid option. Please try again." << endl;
		cout << "1. Orange, 2. Yellow, 3. Green, 4. Blue" << endl;
		cout << "[Player " << numOfPlayers << "] Pick a color by inputting a number: ";
		cin >> pColor;
	}
	cout << endl;
	return new Player(pName, ColorEnum(pColor));
}

void
Game::oneTurn(Player* pp) {
	int firstDice = 0;
	int secondDice = 0;
	int remainingDice = 0;	// Set to total, then subtract chosen values

	while(true) {
		int choice = menu("Pick a function: ", 3, actions);
		switch(choice) {
			case roll:
				diceSet->roll();
				for(int n = 0; n < 4; n++) remainingDice += diceSet->getDiceValue(n);
				// insert choosing logic here


				if(!(b->move(diceSet->getDiceValue(firstDice - 1) + diceSet->getDiceValue(secondDice - 1)) &&
					 b->move(remainingDice))) b->bust();
				b->print(cout);
				break;
			case stop:
				cout << pp->getName() << " has stopped their turn." << endl;
				b->stop();
				for (int n = 0; n < 3; n++) pp->wonColumn(b->getTowersInUse()[n]);
				break;
			case resign:
				// To be implemented later.
				break;
		}
		if(choice == stop) break;
	}
}
