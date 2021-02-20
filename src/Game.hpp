/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 20, 2021
 *
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#define DICE_SET_LENGTH 4	// Constant number of dice in a set

#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"

using namespace std;

class Game {
public:
	Game();
	~Game() = default;
	Player* getNewPlayer();

private:
	int numOfPlayers = 0;// Used for output
	Dice* diceSet[DICE_SET_LENGTH];
	Player* p1;	// Needs input from keyboard
	Player* p2;	// Needs input from keyboard
	Column* c1;
	Column* c2;

};

#endif /* GAME_HPP_ */
