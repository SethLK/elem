#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <stdio.h>
#include <string.h>
#include "tokenList.h" // This should now work correctly with the updated path

typedef enum { 
    TOKEN_IDENTIFIER, // variable names, function names [a-zA-Z_]\w*\b
    TOKEN_KEYWORD, // void int func return 
    TOKEN_OPERATOR, // + = - /
    TOKEN_SEPERATOR, // ; {} ()
    TOKEN_LITERAL, // "Hello World" 0
    TOKEN_UNKNOWN, // unknown token
    TOKEN_NUMBER,
} TokenType;

void processToken(Token **head, char *token);
int isIdentifier(const char *token);
int isKeyword(const char *token);
int isFloat(const char *token);
int isInt(const char *token);

#endif // TOKEN_TYPE_H
