/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 31, 2021
 * 
 */
#ifndef DICE_HPP_
#define DICE_HPP_

#include "tools.hpp"
#include <iostream>

#define INFILE "fakeDiceInput.txt"

using namespace std;

class Dice {
public:
	Dice(int n);
	virtual ~Dice() {delete [] diceValues;};
	virtual const int* roll();
	ostream& print(ostream& out) const;
	const int getDiceValue(int n) const {return diceValues[n];};

protected:
	int nDice;			// Number of dice in the array
	int* diceValues;	// Dynamically allocated array of dice

};

inline ostream& operator <<( ostream& out, Dice& d ) {
	return d.print(out);
}

class CantStopDice : public Dice {
public:
	CantStopDice() : Dice(Dice(4)) {};
	~CantStopDice() {delete[] diceValues;};
	const int* roll();
	const int choosePair() const;

private:
	int pairValues[2] = {0,0};
};

class FakeDice : public CantStopDice {
public:
	FakeDice() {diceFile.open(INFILE);};
	const int* roll();

private:
	ifstream diceFile;

};

#endif /* DICE_HPP_ */
