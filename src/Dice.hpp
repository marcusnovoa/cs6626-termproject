/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 24, 2021
 * 
 */
#ifndef DICE_HPP_
#define DICE_HPP_

#include "tools.hpp"
#include <iostream>
#include "BadChoice.hpp"

#define INFILE "./src/fakeDiceInput.txt"

using namespace std;

class Dice {
public:
	Dice(int n);
	virtual ~Dice() {delete [] diceValues;};
	virtual const int* roll();
	ostream& print(ostream& out) const;
	const int getDiceValue(int n) const {return diceValues[n];};
	const int* getPairValues() const {return pairValues;};
	void resetDiceValues();

protected:
	int nDice;			// Number of dice in the array
	int* diceValues;	// Dynamically allocated array of dice
	int pairValues[2] = {0,0};

};

inline ostream& operator <<( ostream& out, Dice& d ) {
	return d.print(out);
}

class CantStopDice : public Dice {
public:
	CantStopDice() : Dice(Dice(4)) {};
	~CantStopDice() {delete[] diceValues;};
	virtual const int* roll();
	const int choosePair() const;

};

class FakeDice : public CantStopDice {
public:
	FakeDice() {diceFile.open(INFILE);};
	int infPosition = 0; // Keep track of in-file position
	const int* roll();

private:
	ifstream diceFile;

};

#endif /* DICE_HPP_ */
