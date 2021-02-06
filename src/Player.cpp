/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 5, 2021
 *
 */
#include "Player.hpp"

Player::Player(string name, ColorEnum color) {
    playerName = name;
    playerColor = color;
}

ostream&
Player::print(ostream& out) const {
    if (playerName.find(' ') != string::npos) {
        out << "Player name input is invalid.";
        return out;
    } else if (playerColor == error) {
        out << "Player color input is invalid.";
        return out;
    }

    out << "Player Name:  " << playerName << endl;
    out << "Player Color: " << colors[playerColor] << endl;

    return out;
}
