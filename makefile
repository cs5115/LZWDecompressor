EXE = main
CXX = g++
OBJ = main.cpp LZWCompression.o CodeExtractor.o Dictionary.o 
CPPFLAGS = -Wall -g

$(EXE): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp %.h
	 $(CXX) $(CPPFLAGS) -c $<

clean:
	-rm -f *.o *~ $(EXE)
