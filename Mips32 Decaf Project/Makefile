all: decaf

decaf: ast.o parser.o lexer.o main.o
	g++ -g -o $@ $^
	
ast.o: ast.cpp ast.h
	g++ -g -c -o $@ $<

main.o: main.cpp ast.h
	g++ -g -c -o $@ $<

lexer.o: lexer.cpp
	g++ -g -c -o $@ $<

lexer.cpp: lexer.l ast.h
	flex -o $@ $<

parser.cpp: parser.y ast.h
	bison --defines=tokens.h -o $@ $<

tparse.o: parser.cpp
	g++ -g -c -o $@ $<

clean:
	rm -f *.o
	rm -f lexer.cpp
	rm -f parser.cpp
	rm -f tokens.h
	rm -f tinyc
