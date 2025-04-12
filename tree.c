#include "defs.h"
#include "data.h"

struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int intval) {
    struct ASTnode* n;

    // malloc() a new AST node
    n = (struct ASTnode*)malloc(sizeof(struct ASTnode*));
    if(n == NULL) {
        fprintf(stderr, "Unable to malloc() in mkastnode()\n");
        exit(1);
    }

    n->op = op;
    n->left = left;
    n->right = right;
    n->intval = intval;
}