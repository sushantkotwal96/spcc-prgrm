#include<stdio.h>
#include<string.h>

struct mdt
{
char s1[10],s2[10],s3[10],s4[10];
};

struct mnt
{
int pointer;
char name[20];
};

struct ala
{
char index[10];
char arg[7];
};

void main()
{
int n,i,mntc=1,mdtc=1,mdtp=0,j;
char str1[10], str2[10], str3[10],str4[10],st1[10],st2[10],st3[10],st4[10];
struct ala a[3];
struct mnt mn[4];
struct mdt md[10];
strcpy( a[0].arg, "ARG1");
strcpy( a[1].arg, "ARG2");
strcpy( a[0].index, "#0");
strcpy( a[1].index, "#1");
n=2;
printf("Pass 1 \n");
printf("\n");
printf("ALA table\n");
printf("Name \t \t Index no\n");


for(i=0;i<n;i++)
{
printf("%s \t \t %s",a[i].arg,a[i].index);
printf("\n");
}
strcpy(mn[0].name,"INCR");
mn[0].pointer=1;
printf("\n\n");
printf("MNT table\n");
printf("Name \t \t Pointer\n");
for(i=0;i<1;i++)
{
printf("%s \t \t %d",mn[i].name,mn[i].pointer);
printf("\n");
}

FILE *fp,*ft,*fr;
fp = fopen("macro1.txt", "r");
char ch;
int k=0;
printf("\n");

while(!feof(fp))

{
    fscanf(fp, "%s %s %s %s", str1, str2, str3, str4);
   
   if(!strcmp(str1,"MACRO"))
     {
     }
    
   else
  {
    

    strcpy( md[k].s1,str1);
    strcpy( md[k].s2,str2);
    strcpy( md[k].s3,str3);
    strcpy( md[k].s4,str4);
    k++;

}
if(!strcmp(str1,"MEND"))
     {
      break;
     }
}

printf("MDT table");

printf("\n");

strcpy(md[0].s2,a[0].index);
strcpy(md[0].s3,a[1].index);
strcpy(md[1].s3,a[0].index);
strcpy(md[2].s3,a[1].index);
printf("\n");
for(i=0;i<k;i++)
{

printf("%s \t %s \t %s \t %s",md[i].s1,md[i].s2,md[i].s3,md[i].s4);
printf("\n");
}
printf("\n\n");

printf("pass 2 output\n\n");

printf("\n");
printf("ALA table\n");
printf("Name \t \t Index no\n");
int i1=0;

for(i=0;i<n;i++)
{
i1++;
printf(" DATA%d \t  \t %s",i1,a[i].index);
printf("\n");
}

strcpy(md[0].s2,"DATA1");
strcpy(md[0].s3,"DATA2");
strcpy(md[1].s3,"DATA1");
strcpy(md[2].s3,"DATA2");
printf("\n");
printf("\n");
for(i=0;i<k-1;i++)
{
printf("%s \t %s \t %s \t %s",md[i].s1,md[i].s2,md[i].s3,md[i].s4);
printf("\n");
}
rewind(fp);
while(!feof(fp))
{
fscanf(fp, "%s %s %s %s", str1, str2, str3, str4);
if(!strcmp(str1,"MACRO"))
{
while(!strcmp(str1,"MEND"))
{
fscanf(fp, "%s %s %s %s", str1, str2, str3, str4);
}
if(!strcmp(str1,mn[0].name))
{
mdtp=mn[0].pointer;
mdtp++;
printf("%s %s %s %s",md[mdtp].s1,md[mdtp].s2,md[mdtp].s3,md[mdtp].s4);
}

}
if(!strcmp(str1,"DATA1"))
{
printf("%s\t %s\t %s\t %s",str1, str2, str3, str4);
printf("\n");
}
}
if(!strcmp(str1,"DATA2"))
{
printf("%s\t %s\t %s\t %s\n",str1, str2, str3, str4);
printf("\n");
printf("\n");
}
}
