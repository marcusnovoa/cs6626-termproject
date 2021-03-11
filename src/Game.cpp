/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 11, 2021
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
	int firstDice;
	int secondDice;
	int firstPair;
	int remainingDice;	// Set to total, then subtract chosen values
	int choice;
	bool choosing = true;

	while(choosing) {
		turnMenu(&choice, "Pick a function:\n", ACTIONS_LENGTH, actions);
		switch(choice) {
			case roll:
				// Reset dice on new roll
				firstDice = 0;
				secondDice = 0;
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
				chooseDiceNumber(&firstDice, 1);
				chooseDiceNumber(&secondDice, 2);

				// Update the pair values
				firstPair += diceSet->getDiceValue(firstDice - 1)
						   + diceSet->getDiceValue(secondDice - 1);
				remainingDice -= firstPair;

				cout << "\nFirst Pair: " << firstPair << "\n";
				cout << "Second Pair: " << remainingDice << "\n";

				// Attempt tower movement
				// Use | for OR, since || will short-circuit move on right
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
Game::chooseDiceNumber(int* dice, int diceNumber) {
	bool choosing = true;
	char inp;
	char max = nth_letter(DICE_SET_LENGTH);

	while (choosing) {
		cout << "Choose a letter from A to " << max
			 << " for Dice " << diceNumber << " of your desired pair: ";
		cin >> inp;
		inp = toupper(inp);
		if(inp >= 'A' && inp <= max) {
			inp -= 64;
			choosing = false;
		}
		else cout << "Invalid input, try again." << endl;
	}

	*dice = inp; // Convert letter input to number
}

void
Game::turnMenu(int* opt, string title, int n, const char* menu[]) {
	cout << title;
	for (int j = 0; j < n; j++)
		cout << j + 1 << ". " << menu[j] << "\n";
	cin >> *opt;
	cout << "\n";
}

const char
Game::nth_letter(int n) {
    if(n >= 1 && n <= 26)
    	return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n - 1];
	return '?';
}
