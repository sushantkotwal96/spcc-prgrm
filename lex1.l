%{
	int id=0,key=0,op=0,relop=0;
%}
letter [a-zA-Z]
digit [0-9]
%%
(if|else|while|do|for)         {key++; printf("keywords %s\n",yytext); }
("+"|"="|"-"|"/"|"*")          {op++; printf("operands %s\n",yytext); }
("<"|"<="|">"|">=")            {relop++; printf("relational oprators %s\n",yytext); }
{letter}({letter}|{digit})*    {id++; printf("identifiers %s\n",yytext); }
%%
main()
{
	yylex();
	printf("no of operators %d\n",op);
	printf("no of keywords %d\n",key);
	printf("no of relational oprators %d\n",relop);
	printf("no of identifiers %d\n",id);
}
