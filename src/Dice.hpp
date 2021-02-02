//Marcus Novoa & Brandon Olah
#ifndef DICE_HPP_
#define DICE_HPP_

#pragma once
#include "tools.hpp"
#include <iostream>

using namespace std;

class Dice {
public:
	Dice(int n);
	const int* roll();
	ostream& print(ostream& out) const;
	~Dice();

private:
	int nDice;
	int* diceValues;

};

#endif /* DICE_HPP_ */

inline ostream& operator <<( ostream& out, Dice& d ) {
	d.print(out);
	return out;
}
