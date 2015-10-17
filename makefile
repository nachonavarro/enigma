enigma: Main.o Rotor.o Plugboard.o Reflector.o 
	g++ -g -o enigma Main.o Rotor.o Plugboard.o Reflector.o 

Main.o: Main.cpp
	g++ -g -c Main.cpp

Rotor.o: Rotor.cpp 
	g++ -g -c Rotor.cpp

Plugboard.o: Plugboard.cpp 
	g++ -g -c Plugboard.cpp 

Reflector.o: Reflector.cpp 
	g++ -g -c Reflector.cpp

.PHONY: clean

clean:
	rm -rf enigma *.o
	rm -rf *.gch
