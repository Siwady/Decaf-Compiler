#include <cstdio>
#include "tree.h"
#include "tokens.h"

int yyparse();
extern Program *program;

int main() {
    yyparse();
    program->Initialize();
    program->RunMain();
}
