#include <cstdio>
#include <iostream>
#include "ast.h"
#include "tokens.h"

int yyparse();
extern Program *program;
extern map<string,string> StringConstants;
extern map<char,string> CharConstants;

int main() {
    yyparse();

    cout << ".data" << endl;
    cout<< "newLine: .asciiz \"\\n\"" << endl;

    string code=program->generateCode();

    map<string,string>::iterator it=StringConstants.begin();
    while(it!=StringConstants.end()){
        cout << it->second << ": .asciiz \""<<it->first <<"\""<< endl;
                    it++;
    }
    map<char,string>::iterator it2=CharConstants.begin();
    while(it2!=CharConstants.end()){
        cout << it2->second << ": .byte \'"<<it2->first <<"\'"<< endl;
                    it2++;
    }

    cout << ".text\n" << code << endl;
}
