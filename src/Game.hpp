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

class Game {
public:
	Game();
	~Game();
	Player getNewPlayer();

private:
	Dice* dice = new Dice(4);
	Player p1 = Player("Brandon", blue);	// Needs info to be from keyboard
	Player p2 = Player("Marcus", orange);	// Needs info to be from keyboard
	Column c1 = Column(5);
	Column c2 = Column(7);

};

#endif /* GAME_HPP_ */
