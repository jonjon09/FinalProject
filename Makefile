GPP=g++

Sort: Main.o Sort.o
	$(GPP) Main.o Sort.o -o Sort
	
Main.o: Main.cpp Sort.h
	$(GPP) -c Main.cpp
	
Sort.o: Sort.h Sort.cpp
	$(GPP) -c Sort.cpp
	
clean:
	rm *.o Sort
