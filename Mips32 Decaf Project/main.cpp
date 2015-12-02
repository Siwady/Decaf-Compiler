#include <cstdio>
#include <iostream>
#include "ast.h"
#include "tokens.h"

int yyparse();
extern Program *program;

int main() {
    yyparse();

    cout << ".data" << endl;
    cout<< "newLine: .asciiz \"\\n\"" << endl;
    //cout<< program->generateCode();

    string code=program->generateCode();

    cout << ".text\n" << code << endl;
    cout << "# Exit\n"
           << "li $v0, 10\n"
           << "syscall\n";
}
