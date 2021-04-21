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

	virtual ~BadPlayer();
	virtual ostream& print();
};

class BadName : public BadPlayer {
public:
	~BadName();
	ostream& print();
};

class BadColor : public BadPlayer {
public:
	~BadColor();
	ostream& print();
};

#endif /* BADPLAYER_HPP_ */
