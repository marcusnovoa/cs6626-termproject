/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 8, 2021
 *
 */
#ifndef BOARD_HPP_
#define BOARD_HPP_

#define NUM_OF_COLUMNS 13

#include "enums.hpp"
#include "Column.hpp"
#include "Player.hpp"
#include "tools.hpp"

using namespace std;

class Board {
public:
    Board();
    ~Board() {for(int n = 0; n < NUM_OF_COLUMNS; ++n) delete backBone[n];};
    ostream& print(ostream& out) const;
    void startTurn(Player* p);
    const bool move(int column);
    void stop();
    void bust();
    void unitBoard(ofstream& ofs);

private:
    int towerCounter;
    int towersInUse[3] = {0};
    Column* backBone[NUM_OF_COLUMNS];
    Player* currentPlayer;

};

inline ostream& operator <<( ostream& out, Board& b ) {
	return b.print(out);
}

#endif /* BOARD_HPP_ */
