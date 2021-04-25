/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 24, 2021
 *
 */
#ifndef GAME_HPP_
#define GAME_HPP_

#define ACTIONS_LENGTH 3
#define DICE_SET_LENGTH 4
#define MAX_PLAYERS 4

#include "BadPlayer.hpp"
#include "Board.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"
#include <string>
#include "CList.hpp"
#include "BadPlayer.hpp"
#include "BadChoice.hpp"

using namespace std;

class Game {
public:
	Game();
	~Game() = default;
	Dice* getDiceSet() const {return diceSet;};
	Player* getNewPlayer();
	bool hasWinner();
	void oneTurn();
	void fakeOneTurn();
	const char turnMenu(string title, int n, const char* menu[]) const;
	void unitTurn(ofstream& ofs);

private:
	int numOfPlayers = 0; // Used for output
	Board b = Board();
	Dice* diceSet;
	CList<Player*> playerList;
	Player* winner;
	const char* actions[3] = {"Roll", "Stop", "Resign"};
	string takenNames[4] = {"", "", "", ""};
	int takenColors[4] = {0, 0, 0, 0};
	bool usingFakeDice;

	void checkData(string data);
};

#endif /* GAME_HPP_ */
