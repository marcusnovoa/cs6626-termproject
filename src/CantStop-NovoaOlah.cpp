/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 14, 2021
 *
 */
#include "Column.hpp"
#include "Dice.hpp"
#include "enums.hpp"
#include "Player.hpp"
#include "tools.hpp"

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
	Player* test0 = new Player("WhitePlayer", white);
	Player* test1 = new Player("OrangePlayer", orange);
	Player* test2 = new Player("YellowPlayer", yellow);
	Player* test3 = new Player("GreenPlayer", green);
	Player* test4 = new Player("BluePlayer", blue);
	Player* testInvalid = new Player("Error Player", white);
	Player* testInvalid2 = new Player("ErrorPlayer", error);

	//Print player names and colors on separate lines in console
	cout << "Printing player data in console." << endl;
	ofs << "Printing player data in console." << endl;
	cout << *test0 << endl;
	cout << *test1 << endl;
	cout << *test2 << endl;
	cout << *test3 << endl;
	cout << *test4 << endl;
	cout << *testInvalid << endl;
	cout << *testInvalid2 << endl;

	//Print player names and colors on separate lines into output file
	cout << "Printing player data into output file." << endl;
	ofs << "Printing player data into output file." << endl;
	ofs << *test0 << endl;
	ofs << *test1 << endl;
	ofs << *test2 << endl;
	ofs << *test3 << endl;
	ofs << *test4 << endl;
	ofs << *testInvalid << endl;
	ofs << *testInvalid2 << endl;

	// Test calls to wonColumn and printing
	bool[7] testColumnWins = false;
	testColumnWins[0] = test0->wonColumn(2);
	testColumnWins[1] = test1->wonColumn(3);
	testColumnWins[2] = test2->wonColumn(4);
	testColumnWins[3] = test3->wonColumn(5);
	testColumnWins[4] = test4->wonColumn(6);
	testColumnWins[5] = testInvalid->wonColumn(7);
	testColumnWins[6] = testInvalid2->wonColumn(8);

	for(int n = 0; n < 7; n++) {
		cout << "Column " << n  << ": " << testColumnWins[n] << endl;
		ofs << "Column " << n  << ": " << testColumnWins[n] << endl;
	}
}

void
unitColumn(ofstream& ofs) {
	//Create the example players
	cout << "Constructing player test objects." << endl;
	ofs << "Constructing player test objects." << endl;
	Player* p1 = new Player("OrangePlayer", orange);
	Player* p2 = new Player("YellowPlayer", yellow);

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

	// Stop P1 turn in Col 2
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

int
main() {
	ofstream testOutput;
	testOutput.open(OUTFILE, ofstream::app);
	if ( !testOutput.is_open() ) fatal("Error: Output file failed to open.\n");

	banner();
	fbanner(testOutput);
//	unitDice(testOutput);
//	unitPlayer(testOutput);
	unitColumn(testOutput);
	bye();

	testOutput.close();

	return 0;
}
