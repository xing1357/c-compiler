int scan(struct token *t);

struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int intval);
struct ASTnode *mkastleaf(int op, int intval);
struct ASTnode *mkastunary(int op, struct ASTnode *child, int intval);

struct ASTnode *primary(void);
struct ASTnode *binexpr(void);