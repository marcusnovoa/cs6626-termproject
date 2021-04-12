/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 8, 2021
 *
 */
#ifndef ENUMS_HPP_
#define ENUMS_HPP_

enum ColorEnum {
    white,		// To be used for towers, not players
    orange,
    yellow,
    green,
    blue,
    error
};

enum ColumnState {
    available,
    pending,
    captured
};

enum playerChoice {
	roll = 1,
	stop,
	resign
};

extern const char* colors[6];
extern const char* columnStates[3];
extern const char  markerColors[5];

#endif /* ENUMS_HPP_ */
