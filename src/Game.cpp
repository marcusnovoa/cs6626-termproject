/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 15, 2021
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
	int firstPair;
	int remainingDice;	// Set to total, then subtract chosen values
	int choice;
	bool choosing = true;

	while(choosing) {
		choice = turnMenu("Pick an Action:\n", ACTIONS_LENGTH, actions);
		switch(choice) {
			case roll:
				// Reset dice on new roll
				firstPair = 0;
				remainingDice = 0;

				// Begin roll
				diceSet->roll();
				for(int n = 0; n < DICE_SET_LENGTH; n++)
					remainingDice += diceSet->getDiceValue(n);
				
				// Choose the dice pairs
				cout << "The dice values you rolled are:\n";
				for(int n = 0; n < DICE_SET_LENGTH; n++)
					cout << nth_letter(n + 1) << ". "
					<< diceSet->getDiceValue(n) << "\n";
				cout << "\n";
				chooseDicePair(firstPair);

				// Update the remaining pair
				remainingDice -= firstPair;

				cout << "\nFirst Pair: " << firstPair << "\n";
				cout << "Second Pair: " << remainingDice << "\n";

				// Attempt tower movement
				if(!(b->move(firstPair) | b->move(remainingDice))) {
					cout << "Busted!\n";
					b->bust();
					choosing = false;
					break;
				}
				Column::printBanner(cout);
				cout << *b << "\n";
				break;
			case stop:
				cout << pp->getName() << " has stopped their turn." << endl;
				b->stop();
				for (int n = 0; n < 3; n++) pp->wonColumn(b->getTowersInUse()[n]);
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
		for(int n = 0; n < inp.length(); n++) {
			inp[n] = toupper(inp[n]);
			if(inp[n] >= 'A' && inp[n] <= max && inp.length() == 2) {
				inp[n] -= 65;
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

int
Game::turnMenu(string title, int n, const char* menu[]) {
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
