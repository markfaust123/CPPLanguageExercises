CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

main1: main1.o grade_list.o
	g++ -o main1 main1.o grade_list.o && ./main1

main2: main2.o grade_list.o
	g++ -o main2 main2.o grade_list.o && ./main2

main3: main3.o grade_list.o
	g++ -o main3 main3.o grade_list.o && ./main3

main1.o: main1.cpp grade_list.h
	g++ -c main1.cpp $(CFLAGS)

main2.o: main2.cpp grade_list.h
	g++ -c main2.cpp $(CFLAGS)

main3.o: main3.cpp grade_list.h
	g++ -c main3.cpp $(CFLAGS)

grade_list.o: grade_list.cpp grade_list.h
	g++ -c grade_list.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o main?
