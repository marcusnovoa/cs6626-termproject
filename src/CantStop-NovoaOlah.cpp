/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 1, 2021
 *
 */
#include "Column.hpp"
#include "Dice.hpp"
#include "enums.hpp"
#include "Player.hpp"
#include "tools.hpp"
#include "Game.hpp"

#define OUTFILE "output.txt"

using namespace std;

void
unitDice(ofstream& ofs) {
	//Test cases for different amounts of dice
	cout << "Constructing dice test sets." << endl;
	ofs << "Constructing dice test sets." << endl;
	Dice* test0 = new Dice(0);
	Dice* test4 = new Dice(4);
	Dice* test25 = new Dice(25);
	Dice* test50 = new Dice(50);
	Dice* test100 = new Dice(100);
	Dice* testInvalid = new Dice(-1);

	//Rolling all test dice sets
	cout << "Rolling dice test sets." << endl;
	ofs << "Rolling dice test sets." << endl;
	test0->roll();
	test4->roll();
	test25->roll();
	test50->roll();
	test100->roll();
	testInvalid->roll();

	//Print dice sets on separate lines in console
	cout << "Printing dice test sets in console." << endl;
	ofs << "Printing dice test sets in console." << endl;
	cout << *test0 << endl;
	cout << *test4 << endl;
	cout << *test25 << endl;
	cout << *test50 << endl;
	cout << *test100 << endl;
	cout << *testInvalid << endl;

	//Print dice sets on separate lines into output file
	cout << "Printing dice test sets into output file." << endl;
	ofs << "Printing dice test sets into output file." << endl;
	ofs << *test0 << endl;
	ofs << *test4 << endl;
	ofs << *test25 << endl;
	ofs << *test50 << endl;
	ofs << *test100 << endl;
	ofs << *testInvalid << endl;

	//Re-roll all test dice sets
	cout << "Re-rolling dice test sets." << endl;
	ofs << "Re-rolling dice test sets." << endl;
	test0->roll();
	test4->roll();
	test25->roll();
	test50->roll();
	test100->roll();
	testInvalid->roll();

	//Re-print all test dice sets to console
	cout << "Re-printing dice test sets in console." << endl;
	ofs << "Re-printing dice test sets in console." << endl;
	cout << *test0 << endl;
	cout << *test4 << endl;
	cout << *test25 << endl;
	cout << *test50 << endl;
	cout << *test100 << endl;
	cout << *testInvalid << endl;

	//Re-print all test dice sets into output file
	cout << "Re-printing dice test sets into output file." << endl;
	ofs << "Re-printing dice test sets into output file." << endl;
	ofs << *test0 << endl;
	ofs << *test4 << endl;
	ofs << *test25 << endl;
	ofs << *test50 << endl;
	ofs << *test100 << endl;
	ofs << *testInvalid << endl;
}

void
unitPlayer(ofstream& ofs) {
	//Test cases for different player names and colors
	cout << "Constructing player test objects." << endl;
	ofs << "Constructing player test objects." << endl;
	Player* test0 = new Player("OrangePlayer", orange);
	Player* test1 = new Player("YellowPlayer", yellow);
	Player* test2 = new Player("GreenPlayer", green);
	Player* test3 = new Player("BluePlayer", blue);
	Player* testInvalid = new Player("Error Player", white);
	Player* testInvalid2 = new Player("ErrorPlayer", error);

	//Print player names and colors on separate lines in console
	cout << "Printing player data in console." << endl;
	ofs << "Printing player data in console." << endl;
	cout << *test0 << endl;
	cout << *test1 << endl;
	cout << *test2 << endl;
	cout << *test3 << endl;
	cout << *testInvalid << endl;
	cout << *testInvalid2 << endl;

	//Print player names and colors on separate lines into output file
	cout << "Printing player data into output file." << endl;
	ofs << "Printing player data into output file." << endl;
	ofs << *test0 << endl;
	ofs << *test1 << endl;
	ofs << *test2 << endl;
	ofs << *test3 << endl;
	ofs << *testInvalid << endl;
	ofs << *testInvalid2 << endl;

	//Test calls to wonColumn and printing
	cout << "Printing wonColumn results into console." << endl;
	ofs << "Printing wonColumn results into output file." << endl;
	bool testColumnWins[6] = {false};
	testColumnWins[0] = test0->wonColumn(8);
	testColumnWins[1] = test1->wonColumn(3);
	testColumnWins[2] = test2->wonColumn(4);
	testColumnWins[3] = test3->wonColumn(5);
	testColumnWins[4] = testInvalid->wonColumn(6);
	testColumnWins[5] = testInvalid2->wonColumn(7);

	for(int n = 0; n < 6; n++) {
		cout << "Column " << n << ": " << testColumnWins[n] << endl;
		ofs << "Column " << n << ": " << testColumnWins[n] << endl;
	}

	//Re-print player names and colors on separate lines in console
	cout << "Re-printing player data in console." << endl;
	ofs << "Re-printing player data in console." << endl;
	cout << *test0 << endl;
	cout << *test1 << endl;
	cout << *test2 << endl;
	cout << *test3 << endl;
	cout << *testInvalid << endl;
	cout << *testInvalid2 << endl;

	//Re-print player names and colors on separate lines into output file
	cout << "Re-printing player data into output file." << endl;
	ofs << "Re-printing player data into output file." << endl;
	ofs << *test0 << endl;
	ofs << *test1 << endl;
	ofs << *test2 << endl;
	ofs << *test3 << endl;
	ofs << *testInvalid << endl;
	ofs << *testInvalid2 << endl;
}

void
unitColumn(ofstream& ofs) {
	//Create the example players
	cout << "Constructing player test objects." << endl;
	ofs << "Constructing player test objects." << endl;
	Player* p1 = new Player("OrangePlayer", orange);
//	Player* p2 = new Player("YellowPlayer", yellow);

	//Create the columns [2 .. 11]
	cout << "Constructing column test objects." << endl;
	ofs << "Constructing column test objects." << endl;
	Column* col2 = new Column(2);	// 3 squares
	Column* col7 = new Column(7);	// 13 squares

	//Place the tower down for P1 in Col 2
	cout << "Starting tower for test player in column 2." << endl;
	ofs << "Starting tower for test player in column 2." << endl;
	col2->startTower(p1);

	//Print column properties on separate lines in console
	cout << "Printing column properties in console." << endl;
	ofs << "Printing column properties in console." << endl;
	Column::printBanner(cout);
	cout << *col2 << endl;	// T: 1
	cout << *col7 << endl;

	//Re-print column properties on separate lines into output file
	cout << "Re-printing column properties into output file." << endl;
	ofs << "Re-printing column properties into output file." << endl;
	Column::printBanner(ofs);
	ofs << *col2 << endl;	// T: 1
	ofs << *col7 << endl;

	//Move P1 tower up two spaces in Col 2
	cout << "Testing column movement for player in column 2." << endl;
	ofs << "Testing column movement for player in column 2." << endl;
	col2->move();	// State: 0 (Available)
	col2->move();	// State: 1 (Pending)

	//Print column properties on separate lines in console
	cout << "Printing column properties in console." << endl;
	ofs << "Printing column properties in console." << endl;
	Column::printBanner(cout);
	cout << *col2 << endl;	// T: 3
	cout << *col7 << endl;

	//Re-print column properties on separate lines into output file
	cout << "Re-printing column properties into output file." << endl;
	ofs << "Re-printing column properties into output file." << endl;
	Column::printBanner(ofs);
	ofs << *col2 << endl;	// T: 1
	ofs << *col7 << endl;

	//Stop P1 turn in Col 2
	cout << "Stopping test player's turn in column 2." << endl;
	ofs << "Stopping test player's turn in column 2." << endl;
	col2->stop(p1);	// State: 2 (Captured)

	//Print column properties on separate lines in console
	cout << "Printing column properties in console." << endl;
	ofs << "Printing column properties in console." << endl;
	Column::printBanner(cout);
	cout << *col2 << endl;	// T -> O: 3
	cout << *col7 << endl;

	//Re-print column properties on separate lines into output file
	cout << "Re-printing column properties into output file." << endl;
	ofs << "Re-printing column properties into output file." << endl;
	Column::printBanner(ofs);
	ofs << *col2 << endl;	// T: 1
	ofs << *col7 << endl;
}

void
unitGame(ofstream& ofs, Game& game) {
	//Testing game dice construction
	cout << "Printing game-constructed dice to console.\n";
	ofs << "Printing game-constructed dice to console.\n";
	game.getDiceSet()->print(cout) << "\n\n";

	cout << "Re-printing game-constructed dice into output file.\n";
	ofs << "Re-printing game-constructed dice into output file.\n";
	game.getDiceSet()->print(ofs) << "\n\n";

	//Testing rolling of game dice
	cout << "Printing game dice to console after rolling.\n";
	ofs << "Printing game dice to console after rolling.\n";
	game.getDiceSet()->roll();
	game.getDiceSet()->print(cout) << "\n\n";

	cout << "Re-printing game dice into output file after rolling.\n";
	ofs << "Re-printing game dice into output file after rolling.\n";
	game.getDiceSet()->print(ofs) << "\n\n";

	//Testing player construction
	cout << "Printing game-constructed players to console.\n";
	ofs << "Printing game-constructed players to console.\n";
	game.getPlayerOne()->print(cout) << "\n";
	//game.getPlayerTwo()->print(cout) << "\n\n";

	cout << "Re-printing game-constructed players into output file.\n";
	ofs << "Re-printing game-constructed players into output file.\n";
	game.getPlayerOne()->print(ofs) << "\n";
	//game.getPlayerTwo()->print(ofs) << "\n\n";

	//Testing column construction
	cout << "Printing game-constructed columns to console.\n";
	ofs << "Printing game-constructed columns to console.\n";
	Column::printBanner(cout);
	//game.getColumnOne()->print(cout) << "\n";
	//game.getColumnTwo()->print(cout) << "\n";

	cout << "Re-printing game-constructed columns into output file.\n";
	ofs << "Re-printing game-constructed columns into output file.\n";
	Column::printBanner(ofs);
	//game.getColumnOne()->print(ofs) << "\n";
	//game.getColumnTwo()->print(ofs) << "\n";

	//Testing column tower placement
	cout << "Printing placement of tower in column 7 to console.\n";
	ofs << "Printing placement of tower in column 7 to console.\n";
	Column::printBanner(cout);
	//game.getColumnTwo()->startTower(game.getPlayerOne());
	//game.getColumnTwo()->print(cout) << "\n";

	cout << "Re-printing placement of tower in column 7 into output file.\n";
	ofs << "Re-printing placement of tower in column 7 into output file.\n";
	Column::printBanner(ofs);
	//game.getColumnTwo()->print(ofs) << "\n";

	//Testing column state code
	cout << "Printing column pending state after moves to console.\n";
	ofs << "Printing column pending state after moves to console.\n";
	Column::printBanner(cout);
	//game.getColumnOne()->startTower(game.getPlayerTwo());
	//game.getColumnOne()->move();
	//game.getColumnOne()->move();
	//game.getColumnOne()->print(cout) << "\n";

	cout << "Re-printing column pending state after moves into output file.\n";
	ofs << "Re-printing column pending state after moves into output file.\n";
	Column::printBanner(ofs);
	//game.getColumnOne()->print(ofs);
}

void
unitBoard(ofstream& ofs) {
	//Create game instance
	cout << "Constructing game instance." << endl;
	ofs << "Constructing game instance." << endl;
	Game g = Game();

	//Testing game board print function
	cout << "Printing game board columns to console.\n";
	ofs << "Printing game board columns to console.\n";
	Column::printBanner(cout);
	g.getBoard()->print(cout) << "\n";

	cout << "Re-printing game board columns into output file.\n";
	ofs << "Re-printing game board columns into output file.\n";
	Column::printBanner(ofs);
	g.getBoard()->print(ofs) << "\n";

	//Testing game board start turn
	cout << "Starting turn for player 1 in game board.\n\n";
	ofs << "Starting turn for player 1 in game board.\n\n";
	g.getBoard()->startTurn(g.getPlayerOne());

	//Testing game board current player
	cout << "Printing game board current player to console.\n";
	ofs << "Printing game board current player to console.\n";
	cout << *g.getBoard()->getCurrentPlayer() << "\n";

	cout << "Re-printing game board current player into output file.\n";
	ofs << "Re-printing game board current player into output file.\n";
	ofs << *g.getBoard()->getCurrentPlayer() << "\n\n";

	//Testing initial game board towers in use
	cout << "Printing game board towers in use to console.\n";
	ofs << "Printing game board towers in use to console.\n";
	Column::printBanner(cout);
	g.getBoard()->printTowersInUse(cout) << "\n";

	cout << "Re-printing game board towers in use into output file.\n";
	ofs << "Re-printing game board towers in use into output file.\n";
	Column::printBanner(ofs);
	g.getBoard()->printTowersInUse(ofs) << "\n";

	//Testing game board move for current player
	cout << "Moving game board current player.\n";
	ofs << "Moving game board current player.\n";
	g.getBoard()->move(2);

	cout << "Printing game board columns to console.\n";
	ofs << "Printing game board columns to console.\n";
	Column::printBanner(cout);
	g.getBoard()->print(cout) << "\n";

	cout << "Re-printing game board columns into output file.\n";
	ofs << "Re-printing game board columns into output file.\n";
	Column::printBanner(ofs);
	g.getBoard()->print(ofs) << "\n";

	cout << "Printing game board towers in use to console.\n";
	ofs << "Printing game board towers in use to console.\n";
	Column::printBanner(cout);
	g.getBoard()->printTowersInUse(cout) << "\n";

	cout << "Re-printing game board towers in use into output file.\n";
	ofs << "Re-printing game board towers in use into output file.\n";
	Column::printBanner(ofs);
	g.getBoard()->printTowersInUse(ofs) << "\n";

	//Testing move logic for pending state
	cout << "Moving game board current player thrice.\n";
	ofs << "Moving game board current player thrice.\n";
	g.getBoard()->move(2);
	g.getBoard()->move(2);
	g.getBoard()->move(2);

	//When moved 4 times in a 3-space column, tower does not move past end

	cout << "Printing game board columns to console.\n";
	ofs << "Printing game board columns to console.\n";
	Column::printBanner(cout);
	g.getBoard()->print(cout) << "\n";

	cout << "Re-printing game board columns into output file.\n";
	ofs << "Re-printing game board columns into output file.\n";
	Column::printBanner(ofs);
	g.getBoard()->print(ofs) << "\n";

	//Testing game board stop for current player
	cout << "Stopping game board current player.\n";
	ofs << "Stopping game board current player.\n";
	g.getBoard()->stop();
}

int
main() {
	ofstream testOutput;
	testOutput.open(OUTFILE, ofstream::app);
	if ( !testOutput.is_open() ) fatal("Error: Output file failed to open.\n");

	banner();
	fbanner( testOutput );
//	unitDice( testOutput );
//	unitPlayer( testOutput );
//	unitColumn( testOutput );

//	Game g = Game();
//	unitGame( testOutput, g );

	unitBoard( testOutput );

	bye();

	testOutput.close();

	return 0;
}
