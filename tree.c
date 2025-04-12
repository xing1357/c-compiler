#include "defs.h"
#include "data.h"
#include "decl.h"

struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int intval) {
    struct ASTnode* n;

    // malloc() a new AST node
    n = (struct ASTnode*)malloc(sizeof(struct ASTnode));
    if(n == NULL) {
        fprintf(stderr, "Unable to malloc() in mkastnode()\n");
        exit(1);
    }

    n->op = op;
    n->left = left;
    n->right = right;
    n->intval = intval;
}

// Make an AST leaf node
struct ASTnode *mkastleaf(int op, int intval) {
    return mkastnode(op, NULL, NULL, intval);
}

// Make a AST node with a single child
struct ASTnode *mkastunary(int op, struct ASTnode *child, int intval)
{
    return mkastnode(op, child, NULL, intval);
}