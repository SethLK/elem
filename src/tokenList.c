//tokenList.c

#include "header/tokenList.h"
#include <tokenType.h>
#include <stdlib.h>
#include <stdio.h>

Token *createToken(char name[1024], char value[1024], TokenType tokenType)
{
    Token *newToken = (Token *)malloc(sizeof(Token));
    if (!newToken)
    {
        printf("Memory Allocation failed");
        exit(1);
    }

    strncpy(newToken->name, name, 1024);
    newToken->name[1023] = '\0';

    strncpy(newToken->value, value, 1024);
    newToken->value[1023] = '\0';

    newToken->tokenType = tokenType;
    newToken->next = NULL;

    return newToken;
}

void appendToken(Token **head, char name[1024], char value[1024], TokenType tokenType)
{
    Token *newToken = createToken(name, value, tokenType);
    if (*head == NULL)
    {
        *head = newToken;
    }
    else
    {
        Token *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newToken;
    }
}

void deleteTokenList(Token *head)
{
    while (head != NULL)
    {
        Token *temp = head->next;
        free(head);
        head = temp;
    }
}