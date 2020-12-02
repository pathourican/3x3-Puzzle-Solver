# Patrick Hourican
# pjh4as
# 11/20/2020
# Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall #Enable all warnings
DEBUG=-g

puzzleSolver: puzzleSolver.o
		$(CXX) $(DEBUG) puzzleSolver.o -o a.out
		doxygen Doxyfile

puzzleSolver.o: puzzleSolver.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out
