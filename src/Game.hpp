/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 20, 2021
 *
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "tools.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"

using namespace std;

class Game {
public:
	Game();
	~Game();
	Player* getNewPlayer();

private:
	Dice* dice = new Dice(4);
	Player* p1 = new Player( "Brandon", blue );	// Needs info from keyboard
	Player* p2 = new Player( "Marcus", orange );// Needs info from keyboard
	Column* c1;
	Column* c2;

};

#endif /* GAME_HPP_ */
