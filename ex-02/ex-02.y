%{
#include <stdio.h>
#include <stdlib.h>

// Declare the yylex function
int yylex(void);

// Declare the yyerror function
int yyerror(const char *s);
%}

%token NUMBER
%left '*'
%left '/'
%left '+' '-'

%%
input: E {
    printf("result: %d\n", $$);
    return 0;
};

E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '/' E { $$ = $1 / $3; }
 | E '*' E { $$ = $1 * $3; }
 | NUMBER { $$ = $1; }
;
%%

int main() {
    printf("Enter the expression: ");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}