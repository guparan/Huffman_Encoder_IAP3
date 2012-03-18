CXX=gcc
CXXFLAGS=-Wall -ansi -pedantic
EXE=testArbre

all: $(EXE)

%.o: %.c %.h
	$(CXX) -c $(CXXFLAGS) $<
%.o: %.c
	$(CXX) -c $(CXXFLAGS) $<

testArbre: arbre.o listeArbres.o encodage.o testArbre.o compression.o decompression.o
	$(CXX) -o $@ $(LDFLAGS) $+
clean: 
	rm -f $(EXE) *.o

