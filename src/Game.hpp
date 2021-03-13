/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 12, 2021
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

using namespace std;

class Game {
public:
	Game();
	~Game(){delete b; delete diceSet;};
	Board* getBoard() const {return b;};
	Dice* getDiceSet() const {return diceSet;};
	Player* getNewPlayer();
	Player* getPlayerOne() const {return p1;};
	void oneTurn(Player* pp);
	void chooseDicePair(int& dicePair);
	void turnMenu(int* opt, string title, int n, const char* menu[]);

private:
	int numOfPlayers = 0; // Used for output
	Board* b = new Board();
	Dice* diceSet = new Dice(DICE_SET_LENGTH);
	Player* p1;	// Needs input from keyboard
	const char* actions[3] = {"Roll", "Stop", "Resign"};
	static const char nth_letter(int n);

};

#endif /* GAME_HPP_ */
