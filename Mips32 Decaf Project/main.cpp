#include <cstdio>
#include <iostream>
#include "ast.h"
#include "tokens.h"

int yyparse();
extern Program *program;
extern map<string,string> StringConstants;
extern map<char,string> CharConstants;
extern map<string,VValue> sTable;
int main() {
    yyparse();

    string code=program->generateCode();
    program->ValidateSemantic();

    cout << ".data" << endl<<endl;
    map<string,VValue>::iterator it3=sTable.begin();
    while(it3!=sTable.end()){
        VValue v=it3->second;
        if(v.isArray){
            cout << it3->first << ": .word 0";
            for(int c=1;c<v.ArraySize;c++){
                cout<<",0";
            }
            cout<< endl;
        }else{
            cout << it3->first << ": .word 0"<<endl;
        }
        it3++;
    }
    map<string,string>::iterator it=StringConstants.begin();
    while(it!=StringConstants.end()){
        cout << it->second << ": .asciiz \""<<it->first <<"\""<< endl;
                    it++;
    }
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
