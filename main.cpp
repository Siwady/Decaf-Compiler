#include <cstdio>
#include "tree.h"
#include "tokens.h"

extern Program *program;

int main() {
    yyparse();
    program->Initialize();
    program->RunMain();
}
