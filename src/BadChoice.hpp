/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 24, 2021
 *
 */

#ifndef BADCHOICE_HPP_
#define BADCHOICE_HPP_

#include "tools.hpp"

class BadChoice {
public:
	string badInput;

	BadChoice() = default;
	BadChoice(string data) : badInput(data){};
	virtual ~BadChoice() = default;
	virtual ostream& print(ostream& out);
};

inline ostream& operator<<( ostream& out, BadChoice& bc) {
	return bc.print(out);
}

class DuplicateSlot : public BadChoice {
public:
	DuplicateSlot() = default;
	DuplicateSlot(string data) : BadChoice(data){};
	~DuplicateSlot() = default;
	ostream& print(ostream& out);
};

class BadSlot : public BadChoice {
public:
	BadSlot() = default;
	BadSlot(string data) : BadChoice(data){};
	~BadSlot() = default;
	ostream& print(ostream& out);
};

class SlotAmount : public BadChoice {
public:
	SlotAmount() = default;
	SlotAmount(string data) : BadChoice(data){};
	~SlotAmount() = default;
	ostream& print(ostream& out);
};

class BadPriority : public BadChoice {
public:
	BadPriority() = default;
	BadPriority(string data) : BadChoice(data){};
	~BadPriority() = default;
	ostream& print(ostream& out);
};

class BadColorChoice : public BadChoice {
public:
	BadColorChoice() = default;
	BadColorChoice(string data) : BadChoice(data){};
	~BadColorChoice() = default;
	ostream& print(ostream& out);
};

#endif /* BADCHOICE_HPP_ */
