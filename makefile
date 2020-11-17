enigma: main.o machine.o rotor.o reflector.o plugboard.o
	g++ -g -Wall main.o machine.o rotor.o reflector.o plugboard.o -o enigma

main.o: main.cpp machine.hpp constants.hpp
	g++ -g -Wall -Wextra main.cpp -c

machine.o: machine.cpp machine.hpp rotor.hpp reflector.hpp plugboard.hpp constants.hpp errors.h
	g++ -g -Wall -Wextra machine.cpp -c

rotor.o: rotor.cpp rotor.hpp errors.h constants.hpp
	g++ -g -Wall -Wextra rotor.cpp -c

reflector.o: reflector.cpp reflector.hpp errors.h constants.hpp
	g++ -g -Wall -Wextra reflector.cpp -c

plugboard.o: plugboard.cpp plugboard.hpp errors.h constants.hpp
	g++ -g -Wall -Wextra plugboard.cpp -c

clean:
	rm *.o