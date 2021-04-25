/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 24, 2021
 *
 */
#include "Dice.hpp"

#define MAX_DICE 50		// Largest allowed number of dice
#define PAIR_LENGTH 2

Dice::Dice(int n) {
	if(n <= 0) fatal("Error: Invalid amount of dice.\n");
	if(n >= MAX_DICE) nDice = MAX_DICE;
	else nDice = n;

	diceValues = new int[nDice];
	srand( time( NULL ) );
}

const int*
Dice::roll() {
	for(int n = 0; n < nDice; n++) {
		diceValues[n] = (rand() % 6) + 1;
	}
	return diceValues;
}

ostream&
Dice::print(ostream& out) const {
	if(nDice <= 0) fatal("Impossible error: No dice.\n");
	for(int n = 0; n < nDice; n++) {
		out << diceValues[n] << " ";
	}
	return out;
}

void
Dice::resetDiceValues() {
	for(int k = 0; k < nDice; ++k) diceValues[k] = 0;
}

const int*
CantStopDice::roll() {
	//Roll and get total
	Dice::roll();
	string pairPriority;
	int diceTotal = 0;
	for(int d = 0; d < nDice; ++d) diceTotal += diceValues[d];

	//Display dice and choose pair
	cout << "The dice values you rolled are:\n";
	char opt = 'A';
	for(int n = 0; n < nDice; n++)
		cout << opt++ << ". " << diceValues[n] << "\n";
	cout << "\n";
	pairValues[0] = choosePair();
	pairValues[1] = diceTotal - pairValues[0];

	//Display pairs chosen and give priority to one
	cout << "\nPair 1: " << pairValues[0] << "\n";
	cout << "Pair 2: " << pairValues[1] << "\n\n";

	while(true) {
		try {
			cout << "Choose the number of the pair to use first (1 or 2): ";
			cin >> pairPriority;
			if(pairPriority != "1" && pairPriority != "2")
				throw BadPriority(pairPriority);
			break;
		} catch(BadPriority& bp) {
			cout << bp << endl;
		}
	}

	if(pairPriority == "2") swap(pairValues[0], pairValues[1]);
	return pairValues;
}

const int
CantStopDice::choosePair() const {
	string inp;
	while (true) {
		try {
			cout << "Choose two unique letters from A to D for Dice pair: ";
			cin >> inp;
			if(inp.length() != PAIR_LENGTH) throw SlotAmount(inp);
			for(int k = 0; k < PAIR_LENGTH; ++k) inp[k] = toupper(inp[k]);

			if(inp[0] == inp[1]) throw DuplicateSlot(inp);

			if(inp[0] < 'A' || inp[0] > 'D' ||
			   inp[1] < 'A' || inp[1] > 'D')
				throw BadSlot(inp);

			for(int n = 0; n < PAIR_LENGTH; ++n) {
				inp[n] -= 'A';
			}
			break;
		} catch(DuplicateSlot& ds) {
			cout << ds << endl;
		} catch(BadSlot& bs) {
			cout << bs << endl;
		} catch(SlotAmount& sa) {
			cout << sa << endl;
		}
	}
	return diceValues[inp[0]] + diceValues[inp[1]];
}

const int*
FakeDice::roll() {
	string line;
	diceFile.seekg(infPosition, ios::beg);
	getline(diceFile, line);

	int n = 0;
	for (int k = 0; k < nDice; ++k) {
		diceValues[k] = (int) (line[n] - '0');
		n += 2; // Skip spaces on each line
	}

	int diceTotal = 0;
	for(int d = 0; d < nDice; ++d) diceTotal += diceValues[d];

	//Generate pre-determined pairs
	pairValues[0] = diceValues[0] + diceValues[1];
	pairValues[1] = diceTotal - pairValues[0];

	//Display pairs chosen and give priority to one
	if(pairValues[0] <= 12) cout << "Pair 1: " << pairValues[0] << "\n";
	if(pairValues[1] <= 12) cout << "Pair 2: " << pairValues[1] << "\n\n";

	infPosition += 8;

	return pairValues;
}
