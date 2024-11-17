#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    $ gcc .\ex-07.c -o ex-07.exe && .\ex-07.exe

    Input/Output:
    Enter input (end with '$'): abb$

    Input Length: 4
    +----------------+----------------+----------------+
    | Stack          | Input          | Action         |
    +----------------+----------------+----------------+
    | 0a3            |  bb$           | S3             |
    +----------------+----------------+----------------+
    | 0a3b4          |   b$           | S4             |
    +----------------+----------------+----------------+
    | 0a3A6          |   b$           | 6              |
    +----------------+----------------+----------------+
    | 0A2            |   b$           | 2              |
    +----------------+----------------+----------------+
    | 0A2b4          |    $           | S4             |
    +----------------+----------------+----------------+
    | 0A2A5          |    $           | 5              |
    +----------------+----------------+----------------+
    | 0S1            |    $           | 1              |
    +----------------+----------------+----------------+
    | 0S1            |    $           | accept         |
    +----------------+----------------+----------------+
    Parsing Successful
*/

char ptable[7][5][20] = {
    {"S3", "S4", "", "1", "2"},
    {"", "", "accept", "", ""},
    {"S3", "S4", "", "", "5"},
    {"S3", "S4", "", "", "6"},
    {"R3", "R3", "R3", "", ""},
    {"", "", "R1", "", ""},
    {"R2", "R2", "R2", "", ""}
};

char stack[20];
char input[20];
char action[20];
int i = -1;

void push(char ch) {
    i++;
    stack[i] = ch;
}

void pop() {
    stack[i] = ' ';
    i--;
}

int getrow(char ch) {
    switch (ch) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
    }
    return -1;
}

int getcol(char ch) {
    switch (ch) {
        case 'a': return 0;
        case 'b': return 1;
        case '$': return 2;
        case 'S': return 3;
        case 'A': return 4;
    }
    return -1;
}

void printTableRow(char *stack, char *input, char *action) {
    printf("| %-14s | %-14s | %-14s |\n", stack, input, action);
    printf("+----------------+----------------+----------------+\n");
}

int main() {
    int k = 0;
    printf("Enter input (end with '$'): ");
    scanf("%s", input);

    int n = strlen(input);
    printf("\nInput Length: %d\n", n);
    push('0');

    printf("+----------------+----------------+----------------+\n");
    printf("| Stack          | Input          | Action         |\n");
    printf("+----------------+----------------+----------------+\n");

    int row, col;
    while (input[k] != '\0') {
        row = getrow(stack[i]);
        col = getcol(input[k]);
        strcpy(action, ptable[row][col]);
        if (strcmp(action, "S3") == 0) {
            push(input[k]);
            push('3');
            input[k] = ' ';
            printTableRow(stack, input, action);
            k++;
        } else if (strcmp(action, "S4") == 0) {
            push(input[k]);
            push('4');
            input[k] = ' ';
            printTableRow(stack, input, action);
            k++;
        } else if (strcmp(action, "R1") == 0) {
            pop(); pop(); pop(); pop();
            row = getrow(stack[i]);
            push('S');
            col = getcol('S');
            strcpy(action, ptable[row][col]);
            push(action[0]);
            printTableRow(stack, input, action);
        } else if (strcmp(action, "R2") == 0) {
            pop(); pop(); pop(); pop();
            row = getrow(stack[i]);
            push('A');
            col = getcol('A');
            strcpy(action, ptable[row][col]);
            push(action[0]);
            printTableRow(stack, input, action);
        } else if (strcmp(action, "R3") == 0) {
            pop(); pop();
            row = getrow(stack[i]);
            push('A');
            col = getcol('A');
            strcpy(action, ptable[row][col]);
            push(action[0]);
            printTableRow(stack, input, action);
        } else if (strcmp(action, "accept") == 0) {
            printTableRow(stack, input, action);
            printf("Parsing Successful\n");
            break;
        } else if (strcmp(action, "") == 0) {
            printTableRow(stack, input, action);
            printf("Parsing Error\n");
            break;
        }
    }

    return 0;
}