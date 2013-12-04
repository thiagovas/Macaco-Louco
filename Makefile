# all: main

main: main.cpp ALU.o Control.o DataMemory.o InstructionMemory.o Register.o ShiftLeft.o SignExtend.o
	g++ main.cpp ALU.o Control.o DataMemory.o InstructionMemory.o Register.o ShiftLeft.o SignExtend.o -o main

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

ShiftLeft: ShiftLeft.cpp ShiftLeft.hpp
	g++ -c ShiftLeft.cpp

SignExtend: SignExtend.cpp SignExtend.hpp
	g++ -c SignExtend.cpp

clean:
	rm -f *.o
	rm -f main
	clear