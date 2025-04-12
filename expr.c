#include "defs.h"
#include "data.h"
#include "decl.h"

// Convert a given token to a AST Operation
int arithop(int tok) {
    switch(tok) {
        case T_PLUS:
            return A_ADD;
        case T_MINUS:
            return A_SUBTRACT;
        case T_STAR:
            return A_MUTIPLY;
        case T_SLASH:
            return A_DIVIDE;
        default:
            fprintf(stderr, "Unkown token in arithop() on line %d\n", Line);
            exit(1);
    }
}

// Parse primary factor, and return AST node that represents it
struct ASTnode *primary(void) {
    struct ASTnode *n;

    // Get the current token, and if it is integer literal than make an new ast leaf
    // Otherwise, it is a syntax error
    switch(Token.token) {
        case T_INTLIT: 
            n = mkastleaf(A_INTLIT, Token.intval);
            scan(&Token);
            return n;
        default:
            fprintf(stderr, "Syntax Error on line %d", Line);
    }
}

// Return an handle for AST tree that starts with a binary operator
struct ASTnode *binexpr(void) {
    struct ASTnode *left, *right;
    int type; // What type of node is it?

    left = primary(); // Make sure we have an integer literal on left, then fetch next one

    if(Token.token == T_EOF) // If it's the end of file, then it must be the last node in the tree
        return left; // Just return the left
    
    type = arithop(Token.token);

    // Now get the next token in
    scan(&Token);

    right = binexpr();

    return (mkastnode(type, left, right, 0));
}