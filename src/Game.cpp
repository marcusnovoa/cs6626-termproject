/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 20, 2021
 *
 */

#include "Game.hpp"

Game::Game() {

}

Game::~Game() {

}

Player*
Game::getNewPlayer() {
	string pName;
	int pColor;
	cout << "Player's Name: ";
	cin >> pName;
	cout << "\n1. Orange 2. Yellow 3. Green 4. Blue" << endl;
	cout << "Pick a color by inputting a number: ";
	while( pColor > 0 && pColor < 5 ) {
		cin >> pColor;
		if(pColor < 1 || pColor > 4) cout << "Invalid selection." << endl;
		else break;
	}
	return new Player(pName, ColorEnum(pColor));
}
