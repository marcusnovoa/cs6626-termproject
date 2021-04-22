/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 8, 2021
 *
 */

#include "Game.hpp"

Game::Game() {
	bool creating = true;
	char creatingChoice = 'Y';
	while (creating && playerList.count() < 4) {
		playerList.addItem(getNewPlayer());
		cout << "\nCreate another player? (y / n): ";
		cin >> creatingChoice;
		if(toupper(creatingChoice) == 'N') creating = false;
		cout << '\n';
	}
	playerList.init();

	bool choosing = true;
	int diceChoice = 0;
	cout << "1. CantStop Dice, 2. Fake Dice\n";
	cout << "[Player " << numOfPlayers << "] Which set of dice would you like to use? ";
	cin >> diceChoice;
	cout << '\n';

	while (choosing) {
		switch(diceChoice) {
			case 1:
				diceSet = new CantStopDice();
				usingFakeDice = false;
				choosing = false;
				break;
			case 2:
				diceSet = new FakeDice();
				usingFakeDice = true;
				choosing = false;
				break;
			default:
				cout << "\nInvalid option. Please try again.\n";
		}
	}
}

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

bool
Game::hasWinner() {
	Player* pp = playerList.getCurrentData();
	bool isWinner = false;
	for (int p = 0; p < numOfPlayers; ++p) {
		isWinner = pp->score() >= 3;
		if (isWinner) {
			cout << pp->getName() << " is the winner!\n";
			break;
		}
		pp = playerList.getNext();
	}
	return isWinner;
}

void
Game::oneTurn() {
	int choice;
	bool choosing = true;

	while(choosing) {
		choice = turnMenu("Pick an Action:\n", ACTIONS_LENGTH, actions);
		switch(choice) {
			case roll:
				// Begin roll
				diceSet->roll();

				// Attempt tower movement
				if(!(b.move(diceSet->getPairValues()[0]) | 
					b.move(diceSet->getPairValues()[1]))) {
					cout << "Busted!\n";
					b.bust();
					choosing = false;
					break;
				}
				cout << b << "\n";
				break;
			case stop:
				cout << playerList.getCurrentData()->getName() 
					 << " has stopped their turn.\n";
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
	playerList.next();
}

void
Game::fakeOneTurn() {
	const int* pairs;
	bool running = true;
	while (running) {
		pairs = diceSet->roll();

		// If STOP signal is found in file (7 7 7 7)
		if(pairs[0] > 12 && pairs[1] > 12) {
			cout << playerList.getCurrentData()->getName() 
				 << " has stopped their turn.\n\n";
			b.stop();
			running = false;
		} else {
			// Attempt tower movement
			if(!(b.move(pairs[0]) | b.move(pairs[1]))) {	// If pair totals can be moved
				cout << "Busted!\n";
				b.bust();
			}
		}
		cout << b << "\n";
	}
	playerList.next();
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

void
Game::unitTurn(ofstream& ofs) {
	b.startTurn(playerList.getCurrentData()); // Start turn
	if (!usingFakeDice)
		oneTurn();
	else
		fakeOneTurn();
}

void
Game::checkData(string data) {

}
