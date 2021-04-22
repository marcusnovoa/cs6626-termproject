/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 20, 2021
 *
 */

#ifndef BADCHOICE_HPP_
#define BADCHOICE_HPP_

#include "tools.hpp"

class BadChoice {
public:
	string badInput;

	virtual ~BadChoice() = default;
	virtual ostream& print(ostream& out);
};

class DuplicateSlot : public BadChoice {
public:
	~DuplicateSlot() = default;
	ostream& print(ostream& out);
};

class BadSlot : BadChoice {
public:
	~BadSlot() = default;
	ostream& print(ostream& out);
};

#endif /* BADCHOICE_HPP_ */
