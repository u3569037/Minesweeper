FLAGS = -pedantic-errors -std=c++11

explode.o: explode.cpp explode.h
					g++ $(FLAGS) -c explode.cpp

mine.o: mine.cpp explode.h
				g++ $(FLAGS) -c mine.cpp

mine: explode.o mine.o
			g++ $(FLAGS) explode.o mine.o -o mine
