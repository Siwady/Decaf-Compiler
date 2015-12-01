all: decaf

decaf: tree.o parser.o lexer.o main.o
	g++ -o $@ $^
	
tree.o: tree.cpp tree.h
	g++ -c -o $@ $<

main.o: main.cpp tree.h
	g++ -c -o $@ $<

lexer.o: lexer.cpp
	g++ -c -o $@ $<

lexer.cpp: lexer.l tree.h
	flex -o $@ $<

parser.cpp: parser.y tree.h
	bison --defines=tokens.h -o $@ $<

tparse.o: parser.cpp
	g++ -c -o $@ $<

clean:
	rm -f *.o
	rm -f lexer.cpp
	rm -f parser.cpp
	rm -f tokens.h
	rm -f tinyc
