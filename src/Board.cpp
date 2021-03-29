/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 29, 2021
 *
 */
#include "Board.hpp"

Board::Board() {
	backBone[0] = NULL;
	backBone[1] = NULL;
    for(int n = 2; n < NUM_OF_COLUMNS; n++) backBone[n] = new Column(n);
}

ostream&
Board::print(ostream& out) const {
    for(int n = 2; n < NUM_OF_COLUMNS; n++) backBone[n]->print(out);
    return out;
}

void
Board::startTurn(Player* p) {
    currentPlayer = p;
    towerCounter = 0;
}

const bool
Board::move(int column) {
    if(backBone[column]->getState() == pending ||
       backBone[column]->getState() == captured ||
       (!towerExistsInColumn(column) && towerCounter >= 3))
            return false;

    if(!towerExistsInColumn(column))  // Start or move tower in column
        backBone[column]->startTower(currentPlayer);
    else
        backBone[column]->move();

    // Add column to towers in use
    for(int n = 0; n < 3; n++) {
    	// Check if tower is already in use
    	if(towerExistsInColumn(column)) {
            break;
        }
    	else if(towersInUse[n] == 0) {
            towersInUse[n] = column;
            if(towerCounter < 3) towerCounter++;
            break;
        } else continue;
    }
    return true;
}

void
Board::stop() {
    for(int n = 0; n < towerCounter; n++)
        backBone[towersInUse[n]]->stop(currentPlayer);
}

void
Board::bust() {
    for(int n = 0; n < 3; n++)
        if(towersInUse[n] > 0)
            backBone[towersInUse[n]]->bust();
}

/*
 * Might be able to change calls to this function
 * with if (backBone[colNum]->markers[0] != 0)
 */
bool
Board::towerExistsInColumn(int colNum) {
	for(int n = 0; n < towerCounter; n++) {
		if(towersInUse[n] == colNum) return true;
	}

	return false;
}

void
Board::unitBoard(ofstream& ofs) {
	//Create game instance
	cout << "Constructing game instance." << endl;
	ofs << "Constructing game instance." << endl;

	//Testing game board print function
	cout << "Printing game board columns to console.\n";
	ofs << "Printing game board columns to console.\n";
	print(cout) << "\n";

	cout << "Re-printing game board columns into output file.\n";
	ofs << "Re-printing game board columns into output file.\n";
	print(ofs) << "\n";

	//Testing game board start turn
	cout << "Starting turn for player 1 in game board.\n\n";
	ofs << "Starting turn for player 1 in game board.\n\n";
	startTurn(currentPlayer);

	//Testing game board current player
	cout << "Printing game board current player to console.\n";
	ofs << "Printing game board current player to console.\n";
	cout << currentPlayer << "\n";

	cout << "Re-printing game board current player into output file.\n";
	ofs << "Re-printing game board current player into output file.\n";
	ofs << currentPlayer << "\n\n";

	//Testing game board move for current player
	cout << "Moving game board current player.\n";
	ofs << "Moving game board current player.\n";
	move(2);

	cout << "Printing game board columns to console.\n";
	ofs << "Printing game board columns to console.\n";
	print(cout) << "\n";

	cout << "Re-printing game board columns into output file.\n";
	ofs << "Re-printing game board columns into output file.\n";
	print(ofs) << "\n";

	//Testing move logic for pending state
	cout << "Moving game board current player thrice.\n";
	ofs << "Moving game board current player thrice.\n";
	move(2);
	move(2);
	move(2);

	// When moved 4 times in a 3-space column, tower does not move past end

	cout << "Printing game board columns to console.\n";
	ofs << "Printing game board columns to console.\n";
	print(cout) << "\n";

	cout << "Re-printing game board columns into output file.\n";
	ofs << "Re-printing game board columns into output file.\n";
	print(ofs) << "\n";

	//Testing game board stop for current player
	cout << "Stopping game board current player.\n";
	ofs << "Stopping game board current player.\n";
	stop();
}
