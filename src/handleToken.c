//handleToken.c

#include <tokenType.h>
#include <stdlib.h>
#include <ctype.h>

const char *keywords[] = {"void", "int", "return", "if", "else", "while", "for", "break", "continue", NULL};


int isInt(const char *token){
    for (int i = 0; token[i] != '\0'; i++){
        if (!isdigit(token[i])) {
            return 0; 
        }
    }
    return 1;
}

int isFloat(const char *token) {
    int dotCount = 0, digitCount = 0;

    for (int i = 0; token[i] != '\0'; i++) {
        if (isdigit(token[i])) {
            digitCount++;
        } else if (token[i] == '.') {
            dotCount++;
            if (dotCount > 1) {
                return 0; // More than one decimal point
            }
        } else {
            return 0; // Invalid character
        }
    }

    return dotCount == 1 && digitCount > 0; // Must have one dot and digits
}
int isKeyword(const char *token)
{
    for (int i = 0; keywords[i] != NULL; i++)
    {
        if (strcmp(token, keywords[i]) == 0)
        {
            return 1; // It's a keyword
        }
    }
    return 0; // Not a keyword
}

int isIdentifier(const char *token)
{
    if (isalpha(token[0]) || token[0] == '_') // Starts with letter or _
    {
        for (int i = 1; token[i] != '\0'; i++)
        {
            if (!isalnum(token[i]) && token[i] != '_') // Must be alphanumeric or _
            {
                return 0;
            }
        }
        return 1; // Valid identifier
    }
    return 0; // Invalid identifier
}

void processToken(char *token)
{
    if (isKeyword(token))
    {
        printf("Keyword Found -> %s\n", token);
    }
    else if (isIdentifier(token))
    {
        printf("Identifier Found -> %s\n", token);
    }
    else if (isFloat(token))
    {
        printf("Float Found -> %s\n", token);
    }
    else if (isInt(token))
    {
        printf("Integer Found -> %s\n", token);
    }
    else if (strlen(token) == 1 && strchr("+-*/=;", token[0]))
    {
        printf("Operator Found -> %s\n", token);
    }
    else
    {
        printf("Unknown Token -> %s\n", token);
    }
}