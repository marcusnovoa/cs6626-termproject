/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Apr 24, 2021
 *
 */

#ifndef BADPLAYER_HPP_
#define BADPLAYER_HPP_

#include "tools.hpp"

class BadPlayer {
public:
	string badInput;
	BadPlayer() = default;
	BadPlayer(string data) : badInput(data){};
	virtual ~BadPlayer() = default;
	virtual ostream& print(ostream& out);
	ostream& basePrint(ostream& out);
};

inline ostream& operator<<( ostream& out, BadPlayer& bp) {
	return bp.print(out);
}

class BadName : public BadPlayer {
public:
	BadName() = default;
	BadName(string data) : BadPlayer(data){};
	~BadName() = default;
	ostream& print(ostream& out);
};

class BadColor : public BadPlayer {
public:
	BadColor() = default;
	BadColor(string data) : BadPlayer(data){};
	~BadColor() = default;
	ostream& print(ostream& out);
};

#endif /* BADPLAYER_HPP_ */
