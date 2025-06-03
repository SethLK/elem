#ifndef TOKEN_LIST_H
#define TOKEN_LIST_H

#include "tokenType.h" // Include tokenType.h, not tokenList.h


typedef enum { 
    TOKEN_IDENTIFIER, // variable names, function names [a-zA-Z_]\w*\b
    TOKEN_KEYWORD, // void int func return 
    TOKEN_OPERATOR, // + = - /
    TOKEN_SEPERATOR, // ; {} ()
    TOKEN_LITERAL, // "Hello World" 0
    TOKEN_UNKNOWN, // unknown token
    TOKEN_NUMBER,
} TokenType;



typedef struct Token {
    char name[1024];
    char value[1024];
    TokenType tokenType;
    struct Token *next;
} Token;

Token *createToken(
    char name[1024],
    char value[1024],
    TokenType tokenType
);

void appendToken(Token **head, char name[1024],
    char value[1024],
    TokenType tokenType);

void deleteTokenList(Token *head);

#endif // TOKEN_LIST_H
