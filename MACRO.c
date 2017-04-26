#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct macro_name_table
{
int mindex,ptr;
char name[10];
}mnt;
typedef struct macro_definition_table
{
int mdindex,mind,end;
char mdt[10][50][20],op[90];
}mt;
typedef struct argument_list_array
{
int aindex;
char arg[10];
}ala;
typedef struct argument_list_array2
{
int a1index;
char arg1[10];
}ala1;

void main()
{
int mntc=1,mdtc=1,flag,md,m,i=0,val,n,k=1,j,p,y=0,q,c,z,flag1;
char word[10],word1[10],mdt1[10][50][20],mdt2[50][20];

mnt mn[10];
mt mac[50];
ala al[10];
ala1 al1[10];

FILE *f1;
f1=fopen("MAC.C","r");
fscanf(f1,"%s",word);
while(!(feof(f1)))
{
flag=0;
if(strcmp(word,"MACRO")==0)
{
	fscanf(f1,"%s",word);
	strcpy(mn[mntc].name,word); 
	mn[mntc].mindex=mntc; 
	mn[mntc].ptr=mdtc; 
	mntc++;       
	md=1;
	strcpy(mac[mdtc].mdt[mdtc][md],word); 
	md++;  
	while(strcmp(word,"MEND")!=0)
	{
	fscanf(f1,"%s",word);
	if(word[0]!='?')
	{
		if(word[0]=='&')
		{
			for(m=0;m<i;m++)
			{
			if(strcmp(al[m].arg,word)==0)
			{
				flag=1;
				sprintf(word1,"%d",al[m].aindex);
				strcpy(mac[mdtc].mdt[mdtc][md],word1);
				md++;
			}
			}				
			if(flag==0)
			{
				al[i].aindex= i; 
				strcpy(al[i].arg,word); 
				i++;
				sprintf(word1,"%d",al[m].aindex);
				strcpy(mac[mdtc].mdt[mdtc][md],word1);	
				md++;
			}
		}
		else
		{
			strcpy(mac[mdtc].mdt[mdtc][md],word);  
			md++;
		}
	}//End of 1 Line
	else
	{
		mac[mdtc].mdindex=mdtc;
		mac[mdtc].mind=mntc-1;
		mac[mdtc].end=md;
		printf("%d\t",mac[mdtc].mdindex);
		for(m=1;m<md;m++)
			printf("%s\t",mac[mdtc].mdt[mdtc][m]);
		printf("\n");
		mdtc++;
		md=1;
	}
	}//MEND
	mac[mdtc].mdindex=mdtc;
	mac[mdtc].mind= 00;
	strcpy(mac[mdtc].mdt[mdtc][0],"MEND");
	printf("%d\t%s\n",mac[mdtc].mdindex,mac[mdtc].mdt[mdtc][0]);
	mdtc++;
}//MACRO
fscanf(f1,"%s",word);
}//End of File

printf("\nMACRO NAME TABLE\n");
printf("Index\tName\tMdt ptr\n");
for(m=1;m<mntc;m++)
	printf("%d\t%s\t%d\n",mn[m].mindex,mn[m].name,mn[m].ptr);
	
printf("\nARGUMENT LIST ARRAY\n");
printf("Index\tArg\n");
for(m=0;m<i;m++)
	printf("%d\t%s\n",al[m].aindex,al[m].arg);

printf("\nOUTPUT\n");
rewind(f1);
fscanf(f1,"%s",word);
i=0;
for(m=1;m<mdtc;m++)
	for(z=1;z<mac[m].end;z++)
	strcpy(mdt1[m][z],mac[m].mdt[m][z]);
while(!(feof(f1)))
{
flag1=0;
for(m=1;m<mntc;m++)
{
	if(strcmp(mn[m].name,word)==0)
	{
	flag1=1;
	printf("\n");
	val = mn[m].mindex;
	n = mn[m].ptr;
	}
}
if(strcmp(word,"MACRO")==0)
{
	printf("%s\n",word);
	md=1;
	fscanf(f1,"%s",word);
	while(strcmp(word,"MEND")!=0)
	{
	if(word[0]!='?')
	{
		strcpy(mdt2[md],word);
		md++;
	}
	else
	{
		for(m=1;m<md;m++)
		{
		printf("%s\t",mdt2[m]);
		}
		printf("\n");
		md=1;
	}
	fscanf(f1,"%s",word);
	}
	printf("%s\n",word);
}
else if(flag1==1)
{
	c=2; 
	while(c<mac[n].end)
	{
		fscanf(f1,"%s",word);
		al1[i].a1index = atoi(mac[n].mdt[n][c]);
		strcpy(al1[i].arg1,word);
		strcpy(mdt1[n][c],word);
		i++;
		c++;
	}
	for(q =n+1 ; q<mdtc; q++)
	{
		if(mac[q].mind== val)
		{
		for(z=1;z<mac[q].end;z++)
		{
		for(y=0;y<i;y++)
		{
		sprintf(word1,"%d",al1[y].a1index);
		if(strcmp(mac[q].mdt[q][z],word1)==0)
			strcpy(mdt1[q][z],al1[y].arg1);
		}
		printf("%s\t",mdt1[q][z]);
		}
		printf("\n");
		}
	}	
}
else
{
if(word[0]!='?')
	printf("%s\t",word);
}
fscanf(f1,"%s",word);	
}
printf("\n\nIndex\tArgument\n");
for(m=0;m<i;m++)
	printf("%d\t%s\n",al1[m].a1index,al1[m].arg1);
fclose(f1);
}

/*
INPUT FILE: 
MACRO 
INCR ?
A 1, DATA ?
A 1, DATA ?
MEND ?
MACRO
INCR1 &ARG1 &ARG2 ?
A 3, &ARG1 ?
A 4, &ARG2 ?
MEND ?
INCR ?
L 1, 5
INCR1 DATA1 DATA2 ?
L 1, 1 ?

OUTPUT:
1	INCR	
2	A	1,	DATA	
3	A	1,	DATA	
4	MEND
5	INCR1	0	1	
6	A	3,	0	
7	A	4,	1	
8	MEND

MACRO NAME TABLE
Index	Name	Mdt ptr
1	INCR	1
2	INCR1	5

ARGUMENT LIST ARRAY
Index	Arg
0	&ARG1
1	&ARG2

OUTPUT
MACRO
INCR	
A	1,	DATA	
A	1,	DATA	
MEND
MACRO
INCR1	&ARG1	&ARG2	
A	3,	&ARG1	
A	4,	&ARG2	
MEND

A	1,	DATA	
A	1,	DATA	
L	1,	5	
A	3,	DATA1	
A	4,	DATA2	
L	1,	1	

Index	Argument
0	DATA1
1	DATA2
*/	
	
	
	
	
	
	

