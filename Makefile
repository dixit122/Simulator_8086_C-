src = g++
ccflags = -c

run : mainfile
	./main.exe

mainfile : main.cpp registers.o global_objects.h memory.o operation.o immediate.o
	$(src) main.cpp registers.o memory.o operation.o immediate.o -o main.exe

registers.o : registers.cpp registers.h
	$(src) $(ccflags) registers.cpp

memory.o : memory.cpp registers.o memory.h
	$(src) $(ccflags) memory.cpp

operation.o : operation.cpp operation.h
	$(src) $(ccflags) operation.cpp

immediate.o : immediate.cpp immediate.h registers.h
	$(src) $(ccflags) immediate.cpp


