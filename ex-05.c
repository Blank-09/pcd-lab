#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
  $ gcc .\ex-05.c -o ex-05.exe && .\ex-05.exe

  Input/Output:
  Enter the input: 12321
  *----------------*----------------*----------------*
  | Stack          | Input          | Action         |
  *----------------*----------------*----------------*
  | 1              |  2321          | shift          |
  *----------------*----------------*----------------*
  | 12             |   321          | shift          |
  *----------------*----------------*----------------*
  | 123            |    21          | shift          |
  *----------------*----------------*----------------*
  | 12S            |    21          | reduce         |
  *----------------*----------------*----------------*
  | 12S2           |     1          | shift          |
  *----------------*----------------*----------------*
  | 1S             |     1          | reduce         |
  *----------------*----------------*----------------*
  | 1S1            |                | shift          |
  *----------------*----------------*----------------*
  | S              |                | reduce         |
  *----------------*----------------*----------------*
  |                Parsing Successful!               |
  *--------------------------------------------------*
*/

char stack[20], input[20], action[20];
int i = 0, j = 0, k = 0, n = 0;

void printTableRow(char *stack, char *input, char *action) {
    printf("| %-14s | %-14s | %-14s |\n", stack, input, action);
    printf("*----------------*----------------*----------------*\n");
}

void reduce() {
    strcpy(action, "reduce");
    for (k = 0; k < n; k++) {
        if (stack[k] == '3') {
            stack[k] = 'S';
            stack[k + 1] = '\0';
            printTableRow(stack, input, action);
        }
    }
    for (k = 0; k < n - 2; k++) {
        if (stack[k] == '1' && stack[k + 1] == 'S' && stack[k + 2] == '1') {
            stack[k] = 'S';
            stack[k + 1] = '\0';
            stack[k + 2] = '\0';
            i -= 2;
            printTableRow(stack, input, action);
        }
    }
    for (k = 0; k < n - 2; k++) {
        if (stack[k] == '2' && stack[k + 1] == 'S' && stack[k + 2] == '2') {
            stack[k] = 'S';
            stack[k + 1] = '\0';
            stack[k + 2] = '\0';
            i -= 2;
            printTableRow(stack, input, action);
        }
    }
}

int main() {
    printf("Enter the input: ");
    scanf("%s", input);
    input[strcspn(input, "\n")] = '\0';
    n = strlen(input);
    printf("*----------------*----------------*----------------*\n");
    printf("| Stack          | Input          | Action         |\n");
    printf("*----------------*----------------*----------------*\n");
    for (i = 0; j < n; i++, j++) {
        strcpy(action, "shift");
        stack[i] = input[j];
        stack[i + 1] = '\0';
        input[j] = ' ';
        printTableRow(stack, input, action);
        reduce();
    }
    if (stack[0] == 'S' && stack[1] == '\0')
        printf("|                Parsing Successful!               |\n");
    else
        printf("|                  Parsing Error!                  |\n");

    printf("*--------------------------------------------------*\n");
    return 0;
}
