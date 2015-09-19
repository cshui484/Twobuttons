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
