#ifndef extern_
    #define extern_ extern
#endif

// Global variables to be used in file
extern_ int Line; // Current line compiler is on
extern_ int Putback; // Character putback
extern_ FILE *Infile; // File input pointer 
extern_ struct token Token;