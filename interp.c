#include "defs.h"
#include "data.h"
#include "decl.h"

// Just smth so we can print out the result of AST 
int interpretAST(struct ASTnode *n) {
    int lval;
    int rval;

    // Recursively interpret AST nodes until there are nono left
    if(n->left)
        lval = interpretAST(n->left);
    if(n->right)
        rval = interpretAST(n->right);
    
    switch(n->op) {
        case A_ADD:
            return (lval + rval);
        case A_SUBTRACT:
            return (lval - rval);
        case A_MUTIPLY:
            return (lval * rval);
        case A_DIVIDE:
            return (lval / rval);
        case A_INTLIT:
            return n->intval;
        default:
            fprintf(stderr, "Unknown AST Operator %d\n", n->op);
            exit(1);
    }
}