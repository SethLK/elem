
//main.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "tokenType.h"
#include "tokenList.h"

int main(int argc, char const *argv[])
{
    Token *tokens = NULL;

    FILE *fptr;
    fptr = fopen("./app.elem", "r");

    char String[1024];
    int line = 1;
    while (fgets(String, 1024, fptr))
    {
        printf("%d %s", line, String);

        char token[1024];
        int tokenIndex = 0;
        bool inString = false;
        for (int i = 0; String[i]; i++)
        {
            char currentChar = String[i];
            // if (
            //     isspace(currentChar) || (currentChar == '=' ||
            //     currentChar == ':' || currentChar == ';' ||
            //     currentChar == '.') ||
            //     (currentChar == '{' || currentChar == '}' ||
            //     currentChar == '(' || currentChar == ')')
            //     )

            if (currentChar == '"')
            {
                inString = !inString;

                if (!inString)
                {
                    token[tokenIndex++] = currentChar;
                    token[tokenIndex] = '\0';
                    processToken(&tokens, token);
                    tokenIndex = 0;
                }
                else
                {
                    token[tokenIndex++] = currentChar;
                }
            }
            else if (inString)
            {
                // Inside a string, simply add characters to the token
                token[tokenIndex++] = currentChar;
            }

            else if (
                isspace(currentChar) || strchr("=;:(){}", currentChar))
            {
                if (tokenIndex > 0)
                {
                    token[tokenIndex] = '\0';
                    processToken(&tokens, token);
                    tokenIndex = 0;
                }
                if (strchr("=;:(){}", currentChar))
                {
                    char specialToken[2] = {currentChar, '\0'};
                    processToken(&tokens, specialToken);
                }
            }
            else if (currentChar == '.' && tokenIndex > 0 && isdigit(String[i + 1]))
            {
                token[tokenIndex++] = currentChar;
            }
            else if (isdigit(currentChar) || (currentChar == '.' && isdigit(String[i + 1])))
            {
                token[tokenIndex++] = currentChar;
            }
            else
            {
                token[tokenIndex++] = currentChar;
            }
        }

        if (tokenIndex > 0)
        {
            token[tokenIndex] = '\0';
            processToken(&tokens, token);
        }
        line++;
    }

    fclose(fptr);

    deleteTokenList(tokens);
    return 0;
}
