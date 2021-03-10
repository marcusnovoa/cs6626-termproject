/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 27, 2021
 *
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Board.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"

using namespace std;

class Game {
public:
	Game();
	~Game(){delete b; delete diceSet;};
	Board* getBoard() const {return b;};
	Dice* getDiceSet() const {return diceSet;};
	Player* getNewPlayer();
	Player* getPlayerOne() const {return p1;};

private:
	int numOfPlayers = 0;// Used for output
	Board* b = new Board();
	Dice* diceSet = new Dice(4);
	Player* p1;	// Needs input from keyboard

};

#endif /* GAME_HPP_ */
