/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 14, 2021
 *
 */
#include "Player.hpp"

Player::Player(string name, ColorEnum color) {
    playerName = name;
    playerColor = color;
}

bool
Player::wonColumn(int colNum) {
	if(scoreBoard[playerScore] < 2 || scoreBoard[playerScore] > 12) {
		scoreBoard[playerScore] = colNum;
		playerScore++;
	}

	if(playerScore == 3) return true;
	else return false;
}

ostream&
Player::print(ostream& out) const {
    out << playerName << " (" << colors[playerColor] << ") " << endl;
    out << "Score: " << playerScore << endl;
    out << "Scoreboard: " << endl;
    for(int n = 3; n < 3; n++) {
    	out << scoreBoard[n] << endl;
    }

    return out;
}
