CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunTwobuttons
	rm -f RunTwobuttons.tmp
	rm -f TestTwobuttons
	rm -f TestTwobuttons.tmp
	rm -f solution

config:
	git config -l

scrub:
	make  clean
	rm -f  Twobuttons.log
	rm -rf twobuttons-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: RunTwobuttons.tmp TestTwobuttons.tmp

solution: solution.cpp
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) solution.cpp -o solution

RunTwobuttons: Twobuttons.h Twobuttons.c++ RunTwobuttons.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Twobuttons.c++ RunTwobuttons.c++ -o RunTwobuttons

RunTwobuttons.tmp: RunTwobuttons
	./RunTwobuttons < RunTwobuttons.in > RunTwobuttons.tmp
	diff RunTwobuttons.tmp RunTwobuttons.out

TestTwobuttons: Twobuttons.h Twobuttons.c++ TestTwobuttons.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Twobuttons.c++ TestTwobuttons.c++ -o TestTwobuttons $(LDFLAGS)

TestTwobuttons.tmp: TestTwobuttons
	$(VALGRIND) ./TestTwobuttons                                       >  TestTwobuttons.tmp 2>&1
	$(GCOV) -b Twobuttons.c++     | grep -A 5 "File 'Twobuttons.c++'"     >> TestTwobuttons.tmp
	$(GCOV) -b TestTwobuttons.c++ | grep -A 5 "File 'TestTwobuttons.c++'" >> TestTwobuttons.tmp
	cat TestTwobuttons.tmp
