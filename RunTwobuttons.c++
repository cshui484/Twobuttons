// ------------------------------/
// projects/twobuttons/RunTwobuttons.c++
// Copyright (C) 2015
// CS Hui
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout

#include "Twobuttons.h"

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
