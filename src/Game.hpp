/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 23, 2021
 *
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"

using namespace std;

class Game {
public:
	Game();
	~Game(){delete diceSet;};
	Dice* getDiceSet() const {return diceSet;};
	Player* getNewPlayer();
	Player* getPlayerOne() const {return p1;};
	Player* getPlayerTwo() const {return p2;};
	Column* getColumnOne() const {return c1;};
	Column* getColumnTwo() const {return c2;};

private:
	int numOfPlayers = 0;// Used for output
	Dice* diceSet = new Dice(4);
	Player* p1;	// Needs input from keyboard
	Player* p2;	// Needs input from keyboard
	Column* c1;
	Column* c2;

};

#endif /* GAME_HPP_ */
