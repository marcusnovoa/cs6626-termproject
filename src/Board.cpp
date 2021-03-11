/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 11, 2021
 *
 */
#include "Board.hpp"

Board::Board() {
    for(int n = 0; n < NUM_OF_COLUMNS; n++) {
        if(n == 0 || n == 1)
            backBone[n] = NULL;
        backBone[n] = new Column(n);
    }
}

ostream&
Board::print(ostream& out) const {
    for(int n = 0; n < NUM_OF_COLUMNS; n++)
        if(n == 0 || n == 1) continue;
        else backBone[n]->print(out);
    return out;
}

ostream&
Board::printTowersInUse(ostream& out) const {
    for(int n = 0; n < MAX_TOWERS; n++)
        if(towersInUse[n] == 0) out << towersInUse[n] << endl;
        else backBone[towersInUse[n]]->print(out);
    return out;
}

void
Board::startTurn(Player* p) {
    currentPlayer = p;
    towerCounter = 0;
    for(int n = 0; n < MAX_TOWERS; n++)
        towersInUse[n] = 0;
}

bool
Board::move(int column) {
    if(backBone[column]->getState() == pending ||
       backBone[column]->getState() == captured ||
       (backBone[column]->getMarkers()[0] == 0 && towerCounter >= MAX_TOWERS))
            return false;

    if(backBone[column]->getMarkers()[0] == 0)  // Start or move tower in column
        backBone[column]->startTower(currentPlayer);
    else
        backBone[column]->move();

    // Add column to towers in use
    for(int n = 0; n < MAX_TOWERS; n++) {
    	// Check if tower is already in use
    	if(towerExistsInColumn(column)) {
            break;
        }
    	else if(towersInUse[n] == 0) {
            towersInUse[n] = column;
            if(towerCounter < MAX_TOWERS) towerCounter++;
            break;
        } else continue;
    }
    return true;
}

void
Board::stop() {
    for(int n = 0; n < MAX_TOWERS; n++)
        backBone[towersInUse[n]]->stop(currentPlayer);
}

void
Board::bust() {
    for(int n = 0; n < MAX_TOWERS; n++)
        if(towersInUse[n] > 0)
            backBone[towersInUse[n]]->bust();
}

bool
Board::towerExistsInColumn(int colNum) {
	for(int n = 0; n < MAX_TOWERS; n++) {
		if(towersInUse[n] == colNum) return true;
	}

	return false;
}
