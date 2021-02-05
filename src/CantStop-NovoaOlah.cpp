/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 3, 2021
 *
 */
#include "tools.hpp"
#include "Dice.hpp"

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

int
main() {
	ofstream testOutput;
	testOutput.open(OUTFILE, ofstream::app);
	if ( !testOutput.is_open() ) fatal("Error: Output file failed to open.\n");

	banner();
	fbanner(testOutput);
	unitDice(testOutput);
	bye();

	testOutput.close();

	return 0;
}
