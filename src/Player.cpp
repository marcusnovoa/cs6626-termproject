#include "Player.hpp"

Player::Player(string name, ColorEnum color) {
    playerName = name;
    playerColor = color;
}

ColorEnum Player::color() {
    cout << "Color: " << colors[playerColor];
    return playerColor;
}

ostream&
Player::print(ostream& out) const {
	if (playerName.find(' ') != std::string::npos) {
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
