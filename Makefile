CXX = gcc
CFLAGS = -Wall -pedantic -g
LINK = 

%.o: %.c
	$(CXX) $(CFLAGS) -c -o $@ $< $(LINK)

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

sudosolve: $(OBJS)
	@$(CXX) -o $@ $(CFLAGS) $(OBJS) $(LINK)

clean:
	rm -rf *.o

