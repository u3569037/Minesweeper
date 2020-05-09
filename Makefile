FLAGS = -pedantic-errors -std=c++11

mine.o: mine.cpp
				g++ $(FLAGS) -c mine.cpp

mine: mine.o
			g++ $(FLAGS) mine.o -o mine
