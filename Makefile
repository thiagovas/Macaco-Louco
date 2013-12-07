all: main cleanafter

main: main.cpp ALU.o DataMemory.o InstructionMemory.o Register.o Control.o Mux.o InstructionReg.o Adder.o
	g++ main.cpp ALU.o DataMemory.o InstructionMemory.o Register.o Control.o Mux.o InstructionReg.o Adder.o -o main

ALU: ALU.cpp ALU.hpp
	g++ -c ALU.cpp

Control: Control.cpp Control.hpp
	g++ -c Control.cpp

DataMemory: DataMemory.cpp DataMemory.hpp
	g++ -c DataMemory.cpp

InstructionMemory: InstructionMemory.cpp InstructionMemory.hpp
	g++ -c InstructionMemory.cpp

Register: Register.cpp Register.hpp
	g++ -c Register.cpp

Mux:
	g++ -c Mux.cpp

InstructionReg:
	g++ -c InstructionReg.cpp

Adder: ALU
	g++ -c Adder.cpp

clean: cleanafter
	rm -f main
	clear

cleanafter:
	rm -rf *.o
	rm -rf *~
