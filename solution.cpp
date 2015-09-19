// --------------------------
// projects/twobuttons/Twobuttons.h
// Copyright (C) 2015
// CS Hui
// --------------------------

#ifndef Twobuttons_h
#define Twobuttons_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// twobuttons_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the starting and ending numbers [i, j]
 */
pair<int, int> twobuttons_read (const string& s);

// ------------
// twobuttons_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the min number of button pressed for numbers [i, j]
 */
int twobuttons_eval (int i, int j);

// -------------
// twobuttons_print
// -------------

/**
 * print single int
 * @param w an ostream
 * @param v the min number of button pressed
 */
void twobuttons_print (ostream& w, int v);

// -------------
// twobuttons_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void twobuttons_solve (istream& r, ostream& w);

#endif // Twobuttons_h
// ----------------------------
// projects/twobuttons/Twobuttons.c++
// Copyright (C) 2015
// CS Hui
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair



using namespace std;

// ------------
// twobuttons_read
// ------------

pair<int, int> twobuttons_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// twobuttons_eval
// ------------

int twobuttons_eval (int i, int j) {
	int cnt = 0;

	while (i != j) {
//		cout << " count = " << cnt << " : " << "(i, j) = (" << i << ", " << j << ")" << endl;
		++cnt;
		if (j >= 2*i - 1) {
			if (j % 2 == 0) {
				j >>= 1; }
			else {
				j += 1; }}
		else {
			i -= 1; }}
			
	return cnt;
}

// -------------
// twobuttons_print
// -------------

void twobuttons_print (ostream& w, int v) {
    w << v << endl;}

// -------------
// twobuttons_solve
// -------------

void twobuttons_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = twobuttons_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = twobuttons_eval(i, j);
        twobuttons_print(w, v);}}
// ------------------------------/
// projects/twobuttons/RunTwobuttons.c++
// Copyright (C) 2015
// CS Hui
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout



// ----
// main
// ----

int main () {
    using namespace std;
    twobuttons_solve(cin, cout);
    return 0;}

/*
% g++ -pedantic -std=c++11 -Wall Twobuttons.c++ RunTwobuttons.c++ -o RunTwobuttons



% cat RunTwobuttons.in
1 10
100 200
201 210
900 1000



% RunTwobuttons < RunTwobuttons.in > RunTwobuttons.out



% cat RunTwobuttons.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
