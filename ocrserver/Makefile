CC = g++
SRC = $(wildcard *.cpp) ../lib/log.cpp
IDIR = -I. -I../../lib/src/casablanca/Release/include/ -I..
LDDIRS = -L../../lib/
LDFLAGS += -lboost_system -lcrypto -lssl -ltesseract -lcpprest

langocr-server: 
	$(CC) $(SRC) -o $@ $(IDIR) $(LDDIRS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) ocrserver
