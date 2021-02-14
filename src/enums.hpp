/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 13, 2021
 *
 */
#ifndef ENUMS_HPP_
#define ENUMS_HPP_

enum ColorEnum {
    white,
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

extern const char* colors[6];
extern const char* columnStates[3];
extern const char  markerColors[5];

#endif /* ENUMS_HPP_ */
