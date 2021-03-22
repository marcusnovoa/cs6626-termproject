/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 10, 2021
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
