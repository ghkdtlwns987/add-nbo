add-nbo : add-nbo.o
	g++ -o add-nbo add-nbo.o

add-nbo.o : add-nbo.cpp
	g++ -c add-nbo.cpp

clean : 
	rm add-nbo.o
