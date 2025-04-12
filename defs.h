#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Tokens
enum {
    T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

// Token Structure definition
struct token {
    int token;
    int intval;
};

// Different AST Node Types
enum {
    A_ADD, A_SUBTRACT, A_MUTIPLY, A_DIVIDE, A_INTLIT
};

// Abstract Syntax Tree Node
struct ASTnode {
    int op; // The operation for this node
    struct ASTnode *left; // Left and right child node values
    struct ASTnode *right;
    int intval; // For if there is A_INTLIT child values
};
