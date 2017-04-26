%{
int key=0,op=0,id=0,relop=0,arop=0;
%}
LETTER [a-zA-Z]
DIGIT[0-9]
%%
("begin"|"if"|"else"|"while"|"do"|"then") {key++; printf("Keyword: %s\n",yytext);}

("+"|"*"|"-"|"/"|"=") {arop++; printf("Arithmetic operator: %s\n",yytext);}

("<="|">="|"!="|"<"|">") {relop++; printf("Relational operator: %s\n",yytext);}
			
{LETTER}({LETTER}|{DIGIT})* {id++; printf("Identifier: %s\n",yytext);}
			   
%%
main()
{
yylex();
printf("No. of id's=%d\nkeyword=%d\nNo. of arithmetic operation:%d\nNo. of relop=%d\n",id,key,arop,relop);
}


/*
INPUT FILE:
begin
>
else
<=
=
*
abcdefg128

OUTPUT:
Keyword: begin

Relational operator: >

Keyword: else

Relational operator: <=

Arithmetic operator: =

Arithmetic operator: *

Identifier: abcdefg128

No. of id's=1
keyword=2
No. of arithmetic operation:2
No. of relop=2
*/
