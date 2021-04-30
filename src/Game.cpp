/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 26, 2021
 *
 */

#include "Game.hpp"

Game::Game() {
	char creatingChoice = 'Y';
	while(playerList.count() < 4)
	{
		try {
			Player* newPlayer = getNewPlayer();
			checkData(newPlayer->getName() + " " + to_string(newPlayer->color()));
			playerList.addItem(newPlayer);
			if(numOfPlayers < 4) numOfPlayers++;	// Increase current number of players in-game
			if(numOfPlayers >= 4) {
				cout << "\nGame is full." << endl;
				break;
			}
			cout << "\nCreate another player? (y / n): ";
			cin >> creatingChoice;
			if(toupper(creatingChoice) == 'N') {
				break;
			}
			cout << '\n';
		} catch (BadPlayer& bp) {
			cout << bp << endl;
		} catch (...) {
			fatal("Caught something besides BadPlayer.");
		}
	}

	playerList.init();

	bool choosing = true;
	int diceChoice = 0;
	cout << "\n1. CantStop Dice, 2. Fake Dice\n";
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
	string pColor;

	cout << "[Player " << numOfPlayers + 1 << "] Enter your name: ";
	cin >> pName;

	cout << endl;

	while (true) {
		try {
			cout << "1. Orange, 2. Yellow, 3. Green, 4. Blue" << endl;
			cout << "[Player " << numOfPlayers + 1 << "] Pick a color by inputting a number: ";
			cin >> pColor;
			if (pColor != "1" &&
				pColor != "2" &&
				pColor != "3" &&
				pColor != "4")
				throw BadColorChoice(pColor);
			break;
		} catch(BadColorChoice& bcc) {
			cout << bcc << endl;
		}
	}

	takenNames[numOfPlayers] = pName;
	takenColors[numOfPlayers] = stoi(pColor);
	return new Player(pName, ColorEnum(stoi(pColor)));
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
	bool choosing = true;

	while(choosing) {
		switch(turnMenu("Pick an Action:\n", ACTIONS_LENGTH, actions)) {
			case roll:
				// Begin roll
				diceSet->roll();

				// Attempt tower movement
				if(!(b.move(diceSet->getPairValues()[0]) | 
					b.move(diceSet->getPairValues()[1]))) {
					cout << "\nBusted!\n" << endl;
					b.bust();
					choosing = false;
					break;
				}
				cout << "\n" << b << "\n";
				break;
			case stop:
				cout << playerList.getCurrentData()->getName() 
					 << " has stopped their turn.\n" << endl;
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

const char
Game::turnMenu(string title, int n, const char* menu[]) const {
	string result;
	cout << title;
	for (int j = 0; j < n; j++)
		cout << j + 1 << ". " << menu[j] << "\n";

	cout << endl;
	while(true){
		try {
			cout << "Enter desired number: ";
			cin >> result;
			if(result.length() != 1 ||
			   result[0] < '1' ||
			   result[0] > (char)(n + '0'))
				throw BadChoice(result);
			break;
		} catch (BadChoice& bc) {
			cout << bc << endl;
		} catch (...) {
			fatal("Caught something besides BadChoice.");
		}
	}

	cout << "\n";
	return result[0] - '0';
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
	//split data into name and color
	int dataColor = stoi(data.substr(data.find(' ') + 1, 1));
	string dataName = data.substr(0, data.find(' '));

	bool nameTaken, colorTaken = false;

	for(int n = 0; n < playerList.count(); ++n) {
		if (!takenNames[n].empty() && dataName == takenNames[n]) {
			nameTaken = true;
		}
		if (takenColors[n] > 0 && dataColor == takenColors[n]) {
			colorTaken = true;
		}
	}

	if (nameTaken && colorTaken) {
		throw BadPlayer(data);
	}
	else if (nameTaken) {
		throw BadName(data);
	}
	else if (colorTaken) {
		throw BadColor(data);
	}
}
