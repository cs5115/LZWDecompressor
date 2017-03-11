EXE = main
CXX = g++
OBJ = main.cpp LZWCompression.o CodeTranslator.o Dictionary.o 
CPPFLAGS = -Wall -g

$(EXE): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp %.h
	 $(CXX) $(CPPFLAGS) -c $<

clean:
	-rm -f *.o *~ $(EXE)

#exe: main.cpp LZWCompression.o CodeTranslator.o Dictionary.o
#	g++ -Wall main.cpp LZWCompression.o CodeTranslator.o Dictionary.o -o exe

#LZWCompression.o: LZWCompression.cpp LZWCompression.h
#	g++ -Wall -c LZWCompression.cpp -o LZWCompression.o

#CodeTranslator.o: CodeTranslator.cpp CodeTranslator.h
#	g++ -Wall -c CodeTranslator.cpp -o CodeTranslator.o

#Dictionary.o: Dictionary.cpp Dictionary.h
#	g++ -Wall -c Dictionary.cpp -o Dictionary.o