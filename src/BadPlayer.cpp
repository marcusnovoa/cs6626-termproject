/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 24, 2021
 *
 */

#include "BadPlayer.hpp"
#include "enums.hpp"

ostream& BadPlayer::basePrint(ostream& out) {
	out << "You entered the name: "
		<< badInput.substr(0, badInput.find(' ')) << endl;
	out << "You entered the color: "
		<< colors[stoi(badInput.substr(badInput.find(' ') + 1, 1))] << endl;
	return out;
}

ostream&
BadPlayer::print(ostream& out) {
	BadPlayer::basePrint(out);
	out << "Name and Color already taken, player creation cancelled." << endl;
	return out;
}

ostream&
BadName::print(ostream& out) {
	BadPlayer::basePrint(out);
	out << "Name already taken, player creation cancelled." << endl;
	return out;
}

ostream&
BadColor::print(ostream& out) {
	BadPlayer::basePrint(out);
	out << "Color already taken, player creation cancelled." << endl;
	return out;
}
