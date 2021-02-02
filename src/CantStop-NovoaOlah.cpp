//Marcus Novoa & Brandon Olah
#include "tools.hpp"
#include "Dice.hpp"

#define OUTFILE "output.txt"

using namespace std;

void
unitDice(ofstream& ofs) {
	//Test cases for different amounts of dice
	Dice* test0 = new Dice(0);
	Dice* test4 = new Dice(4);
	Dice* test25 = new Dice(25);
	Dice* test50 = new Dice(50);
	Dice* test100 = new Dice(100);
	Dice* testInvalid = new Dice(-1);

	//Rolling all test dice sets
	test0->roll();
	test4->roll();
	test25->roll();
	test50->roll();
	test100->roll();
	testInvalid->roll();

	//Print dice sets on separate lines in console
	cout << *test0 << endl;
	cout << *test4 << endl;
	cout << *test25 << endl;
	cout << *test50 << endl;
	cout << *test100 << endl;
	cout << *testInvalid << endl;

	//Print dice sets on separate lines into output file
	ofs << *test0 << endl;
	ofs << *test4 << endl;
	ofs << *test25 << endl;
	ofs << *test50 << endl;
	ofs << *test100 << endl;
	ofs << *testInvalid << endl;

	//Re-roll all test dice sets
	test0->roll();
	test4->roll();
	test25->roll();
	test50->roll();
	test100->roll();
	testInvalid->roll();

	//Re-print all test dice sets to console
	cout << *test0 << endl;
	cout << *test4 << endl;
	cout << *test25 << endl;
	cout << *test50 << endl;
	cout << *test100 << endl;
	cout << *testInvalid << endl;

	//Re-print all test dice sets into output file
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
