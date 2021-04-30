/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 24, 2021
 *
 */

#include "BadChoice.hpp"

ostream&
BadChoice::print(ostream& out) {
	out << "\nYou entered: " << badInput
		<< ", try picking an action again." << endl;
	return out;
}

ostream&
DuplicateSlot::print(ostream& out) {
	out << "\nYou entered: " << badInput
		<< ", which are the same dice. Try picking a pair again." << endl;
	return out;
}

ostream&
BadSlot::print(ostream& out) {
	out << "\nYou entered: " << badInput
		<< ", which contains dice not in set. Try picking a pair again." << endl;
	return out;
}

ostream&
SlotAmount::print(ostream& out) {
	out << "\nYou entered: " << badInput
		<< ", which is more/less than two dice. Try picking a pair again." << endl;
	return out;
}

ostream&
BadPriority::print(ostream& out) {
	out << "\nYou entered: " << badInput
		<< ", which is neither of the pair options. Try picking a pair again." << endl;
	return out;
}

ostream&
BadColorChoice::print(ostream& out) {
	out << "\nYou entered: " << badInput
		<< ", which is not a valid color. Try picking a color again." << endl;
	return out;
}

ostream&
BadDiceSetChoice::print(ostream& out) {
	out << "\nYou entered: " << badInput
		<< ", which is not a valid dice set option. Try picking a dice set again." << endl;
	return out;
}
