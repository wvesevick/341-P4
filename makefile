blah: driver.cpp congaline.o node.o pirate.o
		g++ driver.cpp congaline.o node.o pirate.o -o blah
		valgrind --tool=memcheck --log-file=valgrindoutput.txt --leak-check=full ./blah

congaline.o: congaline.cpp congaline.h
	g++ -c congaline.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

pirate.o: pirate.cpp pirate.h
	g++ -c pirate.cpp

clean:
	rm -f *.o blah
