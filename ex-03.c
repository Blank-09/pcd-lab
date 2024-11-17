#include <stdio.h>
#include <string.h>

/*
  $ gcc .\ex-03.c -o ex-03.exe && .\ex-03.exe

    Input       Output
  - (baaa)      parsing successful
  - (ab)        error in parsing
  - (ba)        parsing successful
*/

char input[50];
int i = 0;

void Tdash() {
    if (input[i] == 'a') {
        i++;
        Tdash();
    } else {
        return;
    }
}

void T() {
    if (input[i] == 'b') {
        i++;
        Tdash();
    }
}

void E() {
    if (input[i] == '(') {
        i++;
        T();
        i++;
        if (input[i] == ')') {
            return;
        }
    }
}

void main() {
    printf("Enter the input: ");
    scanf("%s", input);
    E();
    if (strlen(input) == i)
        printf("parsing successful.\n");
    else
        printf("error in parsing.\n");
}
