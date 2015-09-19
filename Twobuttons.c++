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

#include "Twobuttons.h"

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
