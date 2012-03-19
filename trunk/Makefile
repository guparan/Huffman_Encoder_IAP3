CXX=gcc
CXXFLAGS=-Wall -ansi -pedantic
EXE=main

all: $(EXE)

%.o: %.c %.h
	$(CXX) -c $(CXXFLAGS) $<
%.o: %.c
	$(CXX) -c $(CXXFLAGS) $<

main: arbre.o listeArbres.o encodage.o op_bits.o compression.o decompression.o tests.o main.o
	$(CXX) -o $@ $(LDFLAGS) $+
clean: 
	rm -f $(EXE) *.o

