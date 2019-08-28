%{
#include <stdio.h>          
%}
a [a,A] 

%%
a {printf("4"); }
%%

int main()
{
	yylex();
	return 0;
}