/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 13, 2021
 *
 */
#include "Column.hpp"

const int Column::numOfSquares[13] = {
    0, 0, 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3    // Column lengths
};

Column::Column(int colNumber) : number(colNumber) {};

ostream&
Column::print(ostream& out) const {
    out << number << "\t" << columnStates[state];

    // Print column color values
    for (int c = 0; c < MARKER_COLORS_LEN; ++c) {
        out << '\t';
        if ( markers[c] <= 0 )
            out << '-';
        else
            out << markers[c];
    }
    out << endl;
	return out;
};

const ostream& Column::printBanner(ostream& out) {
    out << "\n==========================================================";
	out << "\n#\tState\t\tT\tO\tY\tG\tB\n";
    out << "----------------------------------------------------------\n";
    return out;
};

bool
Column::startTower(Player* p) {
	if(state == available) {
	    if ( markers[p->color()] <= 0 ) // If player has no marker in the column
	        markers[0] = 1;             // Place a tower at position 1
	    else {
	        markers[0] = markers[p->color()] + 1;   // Place tower 1 space ahead of marker
	        if(markers[0] == numOfSquares[number]) state = pending;
	    }
	    return true;
	}
	else {
		return false;
	}
};

bool
Column::move() {
    if ( markers[0] > 0 ) {
        if ( markers[0] < numOfSquares[number] ) {
            markers[0]++;                    // Move the tower up one space
            if ( markers[0] == numOfSquares[number] )
                state = pending; // If tower lands on last space, set pending
            return true;
        }
    }
    return false;
};

void
Column::stop(Player* p) {
    markers[p->color()] = markers[0];   // Set the tower to a colored tile
    markers[0] = 0;                     // Remove the tower
    if ( state == pending )             // If the column state is pending
        state = captured;               // Set the state to captured
    p->wonColumn(number);               // Player wins column number
};
