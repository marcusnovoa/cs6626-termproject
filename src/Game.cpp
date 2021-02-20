/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 20, 2021
 *
 */

#include "Game.hpp"

Game::Game() {
	p1 = getNewPlayer();	// Initialize Player 1
	p2 = getNewPlayer();	// Initialize Player 2
	c1 = new Column(2);	// Initialize Column 1
	c2 = new Column(7);	// Initialize Column 2

	for(int n = 0; n < DICE_SET_LENGTH; n++)
		diceSet[n] = new Dice(6);	// Populate Dice set
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
