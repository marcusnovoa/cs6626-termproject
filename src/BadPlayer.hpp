/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 20, 2021
 *
 */

#ifndef BADPLAYER_HPP_
#define BADPLAYER_HPP_

#include "tools.hpp"

class BadPlayer {
public:
	string badInput;

	virtual ~BadPlayer() = default;
	virtual ostream& print(ostream& out);
};

class BadName : public BadPlayer {
public:
	~BadName() = default;
	ostream& print(ostream& out);
};

class BadColor : public BadPlayer {
public:
	~BadColor() = default;
	ostream& print(ostream& out);
};

#endif /* BADPLAYER_HPP_ */
