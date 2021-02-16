/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 15, 2021
 *
 */
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "enums.hpp"
#include <iostream>
#include <string>

using namespace std;

class Player {
public:
    Player(string name, ColorEnum color);
    ~Player() = default;
    ColorEnum color() const {return playerColor;};
//  int score() const{return playerScore;};
    bool wonColumn(int colNum);
    ostream& print(ostream& out) const;

private:
    string playerName;
    ColorEnum playerColor;
    int playerScore = 0;
    int scoreBoard[3] = {0};

};

inline ostream& operator <<(ostream& out, Player& p) {
    return p.print(out);
}

#endif /* PLAYER_HPP_ */
