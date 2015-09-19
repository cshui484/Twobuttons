// --------------------------------
// projects/twobuttons/TestTwobuttons.c++
// Copyright (C) 2015
// CS Hui
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Twobuttons.h"

using namespace std;

// -----------
// TestTwobuttons
// -----------

// ----
// read
// ----

TEST(TwobuttonsFixture, read) {
    string s("1 10\n");
    const pair<int, int> p = twobuttons_read(s);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);}

// ----
// eval
// ----

TEST(TwobuttonsFixture, eval_1) {
    const int v = twobuttons_eval(4, 6);
    ASSERT_EQ(2, v);}

TEST(TwobuttonsFixture, eval_2) {
    const int v = twobuttons_eval(10, 1);
    ASSERT_EQ(9, v);}

TEST(TwobuttonsFixture, eval_3) {
    const int v = twobuttons_eval(7, 34);
    ASSERT_EQ(7, v);}

TEST(TwobuttonsFixture, eval_4) {
    const int v = twobuttons_eval(3, 11);
    ASSERT_EQ(3, v);}

// -----
// print
// -----

TEST(TwobuttonsFixture, print) {
    ostringstream w;
    twobuttons_print(w, 6);
    ASSERT_EQ("6\n", w.str());}

// -----
// solve
// -----

TEST(TwobuttonsFixture, solve) {
    istringstream r("1 10\n3 3\n5 19\n7 29\n");
    ostringstream w;
    twobuttons_solve(r, w);
    ASSERT_EQ("6\n0\n3\n8\n", w.str());}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Twobuttons.c++ TestTwobuttons.c++ -o TestTwobuttons -lgtest -lgtest_main -lpthread



% valgrind TestTwobuttons                                         >  TestTwobuttons.out 2>&1
% gcov -b Twobuttons.c++     | grep -A 5 "File 'Twobuttons.c++'"     >> TestTwobuttons.out
% gcov -b TestTwobuttons.c++ | grep -A 5 "File 'TestTwobuttons.c++'" >> TestTwobuttons.out



% cat TestTwobuttons.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestTwobuttons
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Twobuttons
[ RUN      ] Twobuttons.read
[       OK ] Twobuttons.read (31 ms)
[ RUN      ] Twobuttons.eval_1
[       OK ] Twobuttons.eval_1 (5 ms)
[ RUN      ] Twobuttons.eval_2
[       OK ] Twobuttons.eval_2 (3 ms)
[ RUN      ] Twobuttons.eval_3
[       OK ] Twobuttons.eval_3 (3 ms)
[ RUN      ] Twobuttons.eval_4
[       OK ] Twobuttons.eval_4 (3 ms)
[ RUN      ] Twobuttons.print
[       OK ] Twobuttons.print (17 ms)
[ RUN      ] Twobuttons.solve
[       OK ] Twobuttons.solve (10 ms)
[----------] 7 tests from Twobuttons (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Twobuttons.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Twobuttons.c++.gcov'
File 'TestTwobuttons.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestTwobuttons.c++.gcov'
*/
