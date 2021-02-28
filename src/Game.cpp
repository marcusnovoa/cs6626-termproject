/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 20, 2021
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
