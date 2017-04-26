#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
FILE *fp;
char oneword[100];
char c;
int i,k=0,d=0,h=0,o=0,b=0,f1,f2,f3,f4,f5,j;

char *key[]={"int","void","include","if","else","while","printf","do","scanf","clrscr","getch"};
char *deli[]={"#",";",","};
char *brac[]={"(",")","{","}","[","]"};
char *header[]={"<stdio.h>","<conio.h>","<string.h>","<ctype.h>"};
char *operator[]={"=","+","-","%","&","*","<",">"};
char *constant[]={"0","1","2","3","4","5","6","7","8","9"};
char key1[10][10],deli1[10][2],header1[10][15],operator1[10][2],brac1[10][2];
fp=fopen("lex.c","r");
do
{
f1=0;f2=0;f3=0;f4=0;f5=0;
c=fscanf(fp,"%s",oneword);
for(i=0;i<11;i++)
{
	if(strcmp(oneword,key[i])==0)
	{
	printf("\n%s\tkeyword",oneword);
	strcpy(key1[k],oneword);
	k++;
	f1=1;
	break;
	}
}

for(i=0;i<3;i++)
{
	if(strcmp(oneword,deli[i])==0)
	{
	printf("\n%s\tpunctuation",oneword);
	strcpy(deli1[d],oneword);
	d++;
	f2=1;
	break;
	}
}

for(i=0;i<4;i++)
{
	if(strcmp(oneword,header[i])==0)
	{
	printf("\n%s\theader",oneword);
	strcpy(header1[h],oneword);
	h++;
	f3=1;
	break;
	}
}

for(i=0;i<8;i++)
{
	if(strcmp(oneword,operator[i])==0)
	{
	printf("\n%s\toperator",oneword);
	strcpy(operator1[o],oneword);
	o++;
	f4=1;
	break;
	}
}

for(i=0;i<6;i++)
{
	if(strcmp(oneword,brac[i])==0)
	{
	printf("\n%s\tbracket",oneword);
	strcpy(brac1[b],oneword);
	b++;
	f5=1;
	break;
	}
}

if(f1==0 && f2==0 && f3==0 && f4==0 && f5==0)
{
i=0;
if(oneword[i]!='\0')
{
if(isdigit(oneword[i]) && isalpha(oneword[i+1]))
	{
	printf("\n%s\tInvalid identifier",oneword);
	}
else if(strspn(oneword, "0123456789") == strlen(oneword))
	{
	printf("\n%s\tConstant",oneword);
	}
else 
	{
	printf("\n%s\tValid identifier",oneword);
	}
}
}


}while(c!=EOF);

printf("\nKeywords\n");
for(i=0;i<k;i++)
{
	printf("%s\t",key1[i]);
}
printf("\n");	
printf("\nHeaders\n");
for(i=0;i<h;i++)
{
	printf("%s\t",header1[i]);
}
printf("\n");	
printf("\nPunctuations\n");
for(i=0;i<d;i++)
{
	printf("%s\t",deli1[i]);
}
printf("\n");	
printf("\nOperators\n");
for(i=0;i<o;i++)
{
	printf("%s\t",operator1[i]);
}
printf("\n");
printf("\nBrackets\n");
for(i=0;i<b;i++)
{
printf("%s\t",brac1[i]);
}
printf("\n");
fclose(fp);
}

/*OUTPUT
#	punctuation
include	keyword
<stdio.h>	header
void	keyword
main	Valid identifier
(	bracket
)	bracket
{	bracket
int	keyword
i	Valid identifier
,	punctuation
4j	Invalid identifier
,	punctuation
k	Valid identifier
;	punctuation
i	Valid identifier
=	operator
10	Constant
;	punctuation
j	Valid identifier
=	operator
20	Constant
;	punctuation
if	keyword
(	bracket
i	Valid identifier
<	operator
j	Valid identifier
)	bracket
{	bracket
k	Valid identifier
=	operator
i	Valid identifier
+	operator
j	Valid identifier
;	punctuation
}	bracket
else	keyword
{	bracket
k	Valid identifier
=	operator
j	Valid identifier
*	operator
i	Valid identifier
;	punctuation
}	bracket
}	bracket
}	bracket
Keywords
include	void	int	if	else	

Headers
<stdio.h>	

Punctuations
#	,	,	;	;	;	;	;	

Operators
=	=	<	=	+	=	*	

Brackets
(	)	{	(	)	{	}	{	}	}	}	*/

