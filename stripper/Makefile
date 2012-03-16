OBJS = stripper.o

CFLAGS = -g
LDFLAGS = 

stripper : $(OBJS)
	g++ $(OBJS) -o stripper $(LDFLAGS)

%.o : %.cpp
	g++ -c $< $(CFLAGS)
