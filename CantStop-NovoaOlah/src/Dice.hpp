/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 10, 2021
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

private:
	int nDice;			// Number of dice in the array
	int* diceValues;	// Dynamically allocated array of dice

};

#endif /* DICE_HPP_ */

inline ostream& operator <<( ostream& out, Dice& d ) {
	return d.print(out);
}
