#include<stdio.h>
#include<string.h>
int top=0,n,i,j,k,col=0,row=0;
char ter[10],opt[10][10],stack[20],ip[10];
void main()
{
    printf("Enter the no of terminals\n");
       scanf("%d",&n);
     printf("Enter the terminals\n");
     scanf("%s",&ter);

printf("Enter the value in operator table\n");
        for(i=0;i<n;i++)
           for(j=0;j<n;j++)
             {
                  printf("\nEnter the value for %c%c:-",ter[i],ter[j]);
                  scanf("%s",&opt[i][j]);
               }
              
     for(i=0;i<n;i++)
       printf("\t%c",ter[i]);
           printf("\n");
            
               for(i=0;i<n;i++)
                  { 
                     printf("\n%c",ter[i]);
                    for(j=0;j<n;j++)
                      {
                        printf("\t%c",opt[i][j]);
                      }
                  }
  stack[top]='$';
           printf("Enter the input string\n");
               scanf("%s",&ip);
                 i=0;
              printf("Stack\t\t\tInput String\t\t\tAction\n");
               printf("\n%s\t\t\t%s\t\t\t",stack,ip);
        int n1;
    n1=strlen(ip);
       while(i<=n1)
           {
                for(k=0;k<n;k++)
                  {
                        if(stack[top]==ter[k])
                            col=k;
                        if(ip[i]==ter[k])
                            row=k;
                   }
                       if(stack[top]=='$' && ip[i]=='$')
                           {
                             printf("The string is accepted\n");
                              break;
                            }
                       else if(opt[col][row]=='<' || opt[col][row]=='=')
                         {
                              stack[++top]=opt[col][row];
                               stack[++top]=ip[i];
                                printf("Shift %c",ip[i++]);  
                          }
                        
                      else if(opt[col][row]=='>' )
                         {
                              while(stack[top]!='<')
                                 --top;
                            top=top-1;
                             printf("Reduce");
                          }
                       else
                         {
                                printf("\nString is not accepted");
                                 break;
                         }
              
           
             printf("\n");
             for(k=0;k<=top;k++)
                    {
                         printf("%c",stack[k]);
                     }
                 printf("\t\t\t");
              for(k=i;k<n1;k++)
                    {
                         printf("%c",ip[k]);
                     }
                 printf("\t\t\t");
         }

}











