#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
  $ gcc .\ex-04.c -o ex-04.exe && .\ex-04.exe

  Input/Output:
  Enter the expression: x=a+b*c/d
  mem addr of x : 000001A9876EBA70
  mem addr of a : 000001A9876EBAF0
  mem addr of b : 000001A9876E93A0
  mem addr of c : 000001A9876E9410
  mem addr of d : 000001A9876F3380
  ---------------------------------------------------------
  *     LEXEME    |       ADDRESS        |    TOKEN_TYPE   
  ---------------------------------------------------------
  *       x       *   000001A9876EBA70   *    keyword
  |       =       |                      |    asn_op
  *       a       *   000001A9876EBAF0   *    identifier
  |       +       |                      |    add_op
  *       b       *   000001A9876E93A0   *    identifier
  |       *       |                      |    mul_op
  *       c       *   000001A9876E9410   *    identifier
  |       /       |                      |    div_op
  *       d       *   000001A9876F3380   *    identifier
  ---------------------------------------------------------
*/

int main() {
    char input[20]; // to store the input
    char lexeme[10]; // to have the lexemes
    char tokentype[10][20]; // to store what type of token is it?
    int *address[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // to store the address
    int *mem, i = 0, len;

    printf("Enter the expression: ");
    scanf("%s", input);
    len = strlen(input);

    while (i < len) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            lexeme[i] = input[i];
            if (input[i] != 'x' && input[i] != 'y') {
                strcpy(tokentype[i], "identifier");
            } else {
                strcpy(tokentype[i], "keyword");
            }
            mem = malloc(input[i]);
            printf("mem addr of %c : %p\n", input[i], mem);
            address[i] = mem;
        } else if (input[i] >= '0' && input[i] <= '9') {
            lexeme[i] = input[i];
            strcpy(tokentype[i], "constant");
            mem = malloc(input[i]);
            printf("mem addr of %c : %p\n", input[i], mem);
            address[i] = mem;
        } else {
            lexeme[i] = input[i];
            switch (input[i]) {
                case '+': strcpy(tokentype[i], "add_op"); break;
                case '-': strcpy(tokentype[i], "sub_op"); break;
                case '*': strcpy(tokentype[i], "mul_op"); break;
                case '/': strcpy(tokentype[i], "div_op"); break;
                case '=': strcpy(tokentype[i], "asn_op"); break;
                default: break;
            }
        }
        i++;
    }

    printf("-------------------------------------------------\n");
    printf("*\tLEXEME\t|\tADDRESS\t\t|\tTOKEN_TYPE\n");
    printf("-------------------------------------------------\n");

    for (i = 0; i < len; i++) {
        if (address[i] != 0)
            printf("*\t%c\t*\t%p\t*\t%s\t\n", lexeme[i], address[i], tokentype[i]);
        else
            printf("|\t%c\t|\t\t\t|\t%s\t\t\n", lexeme[i], tokentype[i]);
    }

    printf("-------------------------------------------------\n");

    return 0;
}
