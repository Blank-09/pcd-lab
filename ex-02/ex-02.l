%{
#include "ex-02.tab.h"
%}

%%
[0-9]{1,2} {
    yylval = atoi(yytext);
    return NUMBER;
}
[0-9]{3,} {
    printf("only 2 digits are allowed\n");
    return 0;
}
[\n] { return 0; }
. { return yytext[0]; }
%%

int yywrap() {
    return 1;
}