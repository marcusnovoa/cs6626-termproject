/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 8, 2021
 *
 */
#ifndef BOARD_HPP_
#define BOARD_HPP_

#define MAX_TOWERS 3
#define NUM_OF_COLUMNS 13

#include "enums.hpp"
#include "Column.hpp"
#include "Player.hpp"

using namespace std;

class Board {
public:
    Board();
    ~Board() = default;
    ostream& print(ostream& out) const;
    ostream& printTowersInUse(ostream& out) const;
    void startTurn(Player* p);
    bool move(int column);
    void stop();
    void bust();
    Player* getCurrentPlayer() const {return currentPlayer;};
    const int* getTowersInUse() const {return towersInUse;};

private:
    int towerCounter = 0;
    int towersInUse[MAX_TOWERS] = {0};
    Column* backBone[NUM_OF_COLUMNS];
    Player* currentPlayer;

};

inline ostream& operator <<( ostream& out, Board& b ) {
	return b.print(out);
}

#endif /* BOARD_HPP_ */
