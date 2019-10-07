CC = g++
CFLAGS = -Wall -Werror
DEPS = SearchNewBooks.h

SearchNewBooks: SearchNewBooks.cpp SearchNewBooks.h
	$(CC) -o SearchNewBooks SearchNewBooks.cpp SearchNewBooks.h $(CFLAGS)

clean:
	rm -f *.o *.dat
