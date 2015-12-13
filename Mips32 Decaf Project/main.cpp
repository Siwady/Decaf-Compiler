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

    cout << ".data" << endl<<endl;
    string code=program->generateCode();

    map<string,string>::iterator it=StringConstants.begin();
    while(it!=StringConstants.end()){
        cout << it->second << ": .asciiz \""<<it->first <<"\""<< endl;
                    it++;
    }
    cout<<endl;
    map<char,string>::iterator it2=CharConstants.begin();
    while(it2!=CharConstants.end()){
        switch (it2->first) {
        case '\n':
            cout << it2->second << ": .byte "<<"\'\\n\'"<< endl;
            break;
        case '\t':
            cout << it2->second << ": .byte "<<"\'\\t\'"<< endl;
            break;
        case '\r':
            cout << it2->second << ": .byte "<<"\'\\r\'"<< endl;
            break;
        case '\a':
            cout << it2->second << ": .byte "<<"\'\\a\'"<< endl;
            break;
        default:
            cout << it2->second << ": .byte \'"<<it2->first <<"\'"<< endl;
        }
        it2++;
    }
    cout << ".text\n\n" << code << endl;
}
