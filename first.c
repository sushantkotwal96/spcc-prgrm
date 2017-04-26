#include<stdio.h>
#include<ctype.h>
#include<string.h>
char prod[50][50],ch;
int p;
void First(char[],char);
void add(char[],char);
void main()
{
	int i,j,m;
	char result[50];
	printf("Enter the Number of productions: ");
	scanf("%d",&p);
	printf("Enter the Productions:\n");
	for(i=0;i<p;i++)
		scanf("%s",prod[i]);
	for(i=0;i<p;i++)	
	{	
	if(prod[i][0]!=prod[i+1][0])
		{
		First(result,prod[i][0]);
		
			printf("FIRST(%c)={ ",prod[i][0]);
			for(m=0;result[m]!='\0';m++)
				printf("  %c  ",result[m]);
			printf(" }\n");
		}
	}
}
void First(char first[], char ch)
{
	char first1[20];
	int n=0,i,j,k,epsilon;
	first1[0]='\0';
    	first[0]='\0';
	for(i=0;i<p;i++)
	{
	if(prod[i][0]==ch)
	{
		for(j=3;j<strlen(prod[i]);j++)
		{
		if(prod[i][j]=='#') 
			add(first,'#');
		else if(islower(prod[i][j]))
		{
			add(first,prod[i][j]);
			break;
		}
		else
		{
			epsilon=0;
			First(first1,prod[i][j]);
			for(k=0 ;first1[k]!='\0';k++)
				add(first,first1[k]);
			for(k=0;first1[k]!='\0';k++)
			        if(first1[k]=='#')
			        {
			         epsilon=1;
			         break;
			        }
		        if(epsilon == 0)
		             break;	
		}
		}
		
	}
	}
}
void add(char first[],char sym)
{
	int k;
	for(k=0 ;first[k]!='\0';k++)
		if(first[k]==sym)
			return;
	first[k]=sym;
	first[k+1]='\0';
}

	
