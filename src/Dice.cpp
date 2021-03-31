/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 31, 2021
 *
 */
#include "Dice.hpp"

#define MAX_DICE 50		// Largest allowed number of dice

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

const int*
CantStopDice::roll() {
	//Roll and get total
	Dice::roll();
	char pairPriority = 1;
	int diceTotal = 0;
	for(int d = 0; d < nDice; ++d) diceTotal += diceValues[d];

	//Display dice and choose pair
	cout << "The dice values you rolled are:\n";
	for(int n = 0; n < nDice; n++)
		cout << "test" << ". "
		<< diceValues[n] << "\n";
	cout << "\n";
	pairValues[0] = choosePair();
	pairValues[1] = diceTotal - pairValues[0];

	//Display pairs chosen and give priority to one
	cout << "\nPair 1:  " << pairValues[0] << "\n";
	cout << "Pair 2: " << pairValues[1] << "\n\n";

	while(true) {
		cout << "Choose the number of the pair to use first (1 or 2): ";
		cin >> pairPriority;
		if(pairPriority >= '1' && pairPriority <= '2') break;
		cout << "Invalid input, try again." << endl;
	}

	if(pairPriority == 2) swap(pairValues[0], pairValues[1]);
	return pairValues;
}

const int
CantStopDice::choosePair() const {
	bool choosing = true;
	string inp;
	while (choosing) {
		cout << "Choose two unique letters from A to D for Dice pair: ";
		cin >> inp;
		for(int k = 0; k < inp.length(); ++k) inp[k] = toupper(inp[k]);
		for(int n = 0; n < inp.length(); ++n) {
			if(inp[n] >= 'A' && inp[n] <= 'D'
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

	return diceValues[inp[0]] + diceValues[inp[1]];
}

const int*
FakeDice::roll() {
	if(!diceFile.eof()) {

	}
	else fatal("Reached end of fakeDice file");
}
