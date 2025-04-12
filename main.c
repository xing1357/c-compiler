#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"
#include <errno.h>

// Init global variables
static void init() {
    Line = 1;
    Putback = '\n';
}

// Print usage if cmd entered incorrect
static void usage(char *prog) {
    fprintf(stderr, "Usage: %s infile\n", prog);
    exit(1);
}

char *tokstr[] = {"+", "-", "*", "/", "intlit"};

static void scanfile() {
    struct token T;

    while(scan(&T)) {
        printf("Token %s", tokstr[T.token]);
        if(T.token == T_INTLIT)
            printf(", value %d", T.intval);
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    struct ASTnode *n;
    if(argc != 2)
        usage(argv[0]);
    init();

    if((Infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open file %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scan(&Token);
    n = binexpr();

    printf("AST Interpreter: %d\n", interpretAST(n));
    exit(0);
}