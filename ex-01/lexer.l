%{
#include <stdio.h>
%}

%%

break | do | for | foreach | case | if | while { printf("%s is a keyword\n", yytext); }
[a-z][a-z0-9]{1,12}@(yahoo|gmail)\.(com|in|us) { printf("%s is valid email\n", yytext); }
[xyz][a-zA-Z]{4} { printf("%s is a variable\n", yytext); }
www\.[a-z]+\.(in|us|com) { printf("%s is a valid web address\n", yytext); }
[6789][0-9]{9} { printf("%s is a valid mobile number\n", yytext); }
[a-zA-Z] { printf("%s is an alphabet\n", yytext); }
\n { return 0; }
. { printf("%s is a non-alphabetic character found\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the lexeme:\n");
    yylex();
    return 0;
}