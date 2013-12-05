# all: main

main: main.cpp ALU.o DataMemory.o InstructionMemory.o Register.o
	g++ main.cpp ALU.o DataMemory.o InstructionMemory.o Register.o -o main

ALU: ALU.cpp ALU.hpp
	g++ -c ALU.cpp

DataMemory: DataMemory.cpp DataMemory.hpp
	g++ -c DataMemory.cpp

InstructionMemory: InstructionMemory.cpp InstructionMemory.hpp
	g++ -c InstructionMemory.cpp

Register: Register.cpp Register.hpp
	g++ -c Register.cpp

clean:
	rm -f *.o
	rm -f main
	clear
