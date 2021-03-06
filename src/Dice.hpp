/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 8, 2021
 * 
 */
#ifndef DICE_HPP_
#define DICE_HPP_

#include "tools.hpp"
#include <iostream>

using namespace std;

class Dice {
public:
	Dice(int n);
	~Dice(){delete [] diceValues;};
	const int* roll();
	ostream& print(ostream& out) const;
	const int getDiceValue(int n) const {return diceValues[n];};

private:
	int nDice;			// Number of dice in the array
	int* diceValues;	// Dynamically allocated array of dice

};

inline ostream& operator <<( ostream& out, Dice& d ) {
	return d.print(out);
}

#endif /* DICE_HPP_ */
