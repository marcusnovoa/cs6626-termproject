/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 29, 2021
 *
 */

#include "Game.hpp"

Game::Game() : p1(getNewPlayer()) {}

Player*
Game::getNewPlayer() {
	string pName;
	int pColor;
	numOfPlayers++;	// Increase current number of players in-game

	cout << "[Player " << numOfPlayers << "] Enter your name: ";
	cin >> pName;
	cout << "\n1. Orange, 2. Yellow, 3. Green, 4. Blue\n";
	cout << "[Player " << numOfPlayers << "] Pick a color by inputting a number: ";
	cin >> pColor;

	while ( pColor < 1 || pColor > 4 ) {
		cout << "\nInvalid option. Please try again.\n";
		cout << "1. Orange, 2. Yellow, 3. Green, 4. Blue\n";
		cout << "[Player " << numOfPlayers << "] Pick a color by inputting a number: ";
		cin >> pColor;
	}
	cout << endl;
	return new Player(pName, ColorEnum(pColor));
}

void
Game::oneTurn(Player* pp) {
	int choice;
	bool choosing = true;

	while(choosing) {
		choice = turnMenu("Pick an Action:\n", ACTIONS_LENGTH, actions);
		switch(choice) {
			case roll:
				// Begin roll
				diceSet->roll();

				// Attempt tower movement
				if(!(b.move(diceSet->getPairValues()[0]) | b.move(diceSet->getPairValues()[1]))) {
					cout << "Busted!\n";
					b.bust();
					choosing = false;
					break;
				}
				cout << b << "\n";
				break;
			case stop:
				cout << pp->getName() << " has stopped their turn.\n";
				b.stop();

				// Print column winnings, if any
				cout << b << "\n";
				
				choosing = false;
				break;
			case resign:
				// To be implemented later.
				break;
		}
	}
}

void
Game::chooseDicePair(int& dicePair) {
	bool choosing = true;
	string inp;
	char max = nth_letter(DICE_SET_LENGTH);

	while (choosing) {
		cout << "Choose two unique letters from A to " << max
			 << " for Dice pair: ";
		cin >> inp;
		for(int k = 0; k < inp.length(); ++k) inp[k] = toupper(inp[k]);
		for(int n = 0; n < inp.length(); ++n) {
			if(inp[n] >= 'A' && inp[n] <= max
			   && inp.length() == 2 && inp[0] != inp[1]) {
				inp[n] -= 'A';
			}
			else {
				cout << "Invalid input, try again." << endl;
				choosing = true;
				break;
			}
			choosing = false;
		}
	}

	dicePair += diceSet->getDiceValue(inp[0]) + diceSet->getDiceValue(inp[1]);
}

const int
Game::turnMenu(string title, int n, const char* menu[]) const {
	char result = 0;
	cout << title;
	for (int j = 0; j < n; j++)
		cout << j + 1 << ". " << menu[j] << "\n";
	while(true) {
		cout << "\nEnter desired number: ";
		cin >> result;
		if(result >= '1' && result <= (char)(n + '0')) break;
		cout << "Invalid input, try again." << endl;
	}
	cout << "\n";
	return result - '0';
}

const char
Game::nth_letter(int n) {
    if(n >= 1 && n <= 26) return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n - 1];
	return '?';
}

void
Game::unitTurn(ofstream& ofs) {
	b.startTurn(p1); // Start turn
	oneTurn(p1);
}
