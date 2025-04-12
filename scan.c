#include "defs.h"
#include "data.h" 
#include "decl.h"

// Lexical scanner

static int next(void) {
    int c;

    if(Putback) { // If we read to far in the input stream... then we need to putback the character
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile); // Get the character

    if(c == '\n') // If it is a newline, then skip to next line
        Line++;

    return c;
}

static void putback(int c) {
    Putback = c;
}
 
// Skip past characters we don't have to scan
// Returns with the next new character we have to deal with, and returns it
static int skip(void){
    int c;

    c = next();

    // Cycle thru until we get a character we can use
    while(' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c)
    {
        c = next();
    }

    return (c);
}

// Returns the position of character c in char array s
static int chrpos(char* s, int c)
{
    char *p;

    p = strchr(s, c);

    return (p ? p - s: -1);
}

static int scanint(int c) {
    int k, val = 0;

    while((k = chrpos("0123456789", c)) >= 0) {
        val = val * 10 + k;
        c = next();
    }

    // We hit a non-integer value, so putback
    putback(c);

    return val;
}

// Scans through the file, and finds tokens and matches them
// Returns 1 for valid token, and 0 when there are no tokens left
int scan(struct token *t) {
    int c;

    c = skip();

    switch(c) {
        case EOF:
            t->token = T_EOF;
            return 0;
        case '+':
            t->token = T_PLUS;
            break;
        case '-':
            t->token = T_MINUS;
            break;
        case '*':
            t->token = T_STAR;
            break;
        case '/':
            t->token = T_SLASH;
            break;
        default:
            // If it is an int, then scan the literal value
            if(isdigit(c)) {
                t->intval = scanint(c);
                t->token = T_INTLIT;
                break;
            }

            printf("Error: Unrecognized character %c on line %d\n", c, Line);
            exit(1);
    }

    return 1; // We found a valid token
}