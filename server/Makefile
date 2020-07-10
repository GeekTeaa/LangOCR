CC = g++
SRC = $(wildcard *.cpp) $(wildcard *.c) $(wildcard ../lib/*.cpp) 
IDIR = -I. -I.. -I$(HOME)/dev/include/
LDDIRS = -L$(HOME)/dev/lib/
LDFLAGS += -lboost_system -lcrypto -lssl -ltesseract -lcpprest

langocrd: 
	$(CC) $(SRC) -o $@ $(IDIR) $(LDDIRS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f *.o langocr-server
