OBJS = stripper.o

CFLAGS = -g -Wall
LDFLAGS = 

stripper : $(OBJS)
	g++ $(OBJS) -o stripper $(LDFLAGS)

%.o : %.cpp
	g++ -c $< $(CFLAGS)

clean : 
	rm stripper.o stripper
