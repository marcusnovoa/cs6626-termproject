/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 29, 2021
 *
 */
#ifndef GAME_HPP_
#define GAME_HPP_

#define ACTIONS_LENGTH 3
#define DICE_SET_LENGTH 4
#define MAX_PLAYERS 4

#include "Board.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"
#include <string>
#include "CList.hpp"

using namespace std;

class Game {
public:
	Game();
	~Game(){delete diceSet;};
	Dice* getDiceSet() const {return diceSet;};
	Player* getNewPlayer();
	Player* getPlayerOne() const {return p1;};
	void oneTurn(Player* pp);
	void chooseDicePair(int& dicePair);
	const int turnMenu(string title, int n, const char* menu[]) const;
	void unitTurn(ofstream& ofs);

private:
	int numOfPlayers = 0; // Used for output
	Board b = Board();
	Dice* diceSet = new FakeDice();
	Player* p1;	// Needs input from keyboard
	const char* actions[3] = {"Roll", "Stop", "Resign"};
	static const char nth_letter(int n);

};

#endif /* GAME_HPP_ */
