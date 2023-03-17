src = g++
ccflags = -c

run : mainfile
	./main.exe

mainfile : main.cpp registers.o global_objects.h memory.o  
	$(src) main.cpp registers.o memory.o -o main.exe

registers.o : registers.cpp registers.h
	$(src) $(ccflags) registers.cpp

memory.o : memory.cpp registers.o memory.h
	$(src) $(ccflags) memory.cpp