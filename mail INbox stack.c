#  include<stdio.h>
# include<stdlib.h>

# define stacksize 10

struct info
{
char name[20],recipient[20],mailID[30],subject[200];

};

struct inbox
{
struct info information[stacksize];
int top;
};

int isfull(struct inbox mail)
{
if(mail.top==stacksize-1)
return 1;
else
return 0;
}
int isempty(struct inbox mail)
{
if(mail.top==-1)
return 1;
else
return 0;
}

struct info mailtop(struct inbox mail)
{printf("\n%s %s %s %s",mail.information[mail.top].name,mail.information[mail.top].recipient,mail.information[mail.top].mailID,mail.information[mail.top].subject);

}
void delet(struct inbox *mail,char receiver[])
{  struct info data;
int i,j;
    for(i=mail->top;i>-1;i--)
        if(receiver==mail->information[i].recipient)
    {
    break;
    }
    else
        i--;

    for(j=i;j;)
    data=mail->information[i];


}
void maillist(struct inbox *mail)
{int i;
for(i=mail->top;i>-1;i--)
{
printf("\n%s",mail->information[mail->top].recipient);
}

}
void pushinfo(struct inbox *mail)
{
mail->top=mail->top+1;
printf("enter name ,recipient,mail ID ,subject");
scanf("%s%s%s%s",mail->information[mail->top].name,mail->information[mail->top].recipient,mail->information[mail->top].mailID,mail->information[mail->top].subject);

}
 void displaymail( struct inbox *mail )
{int i;
 for(i=mail->top;i>-1;i--)
 {
 printf("\n%s %s %s %s",mail->information[mail->top].name,mail->information[mail->top].recipient,mail->information[mail->top].mailID,mail->information[mail->top].subject);
 }
}
int main()
{struct inbox mail;
mail.top=-1;
int ch;
struct info data;
char receiver[30];
do{
   printf("\nenter 1. enter information 2.list of mails,3.display content of recent mails,4.delete mail,5.display all mail,6.exit");
   scanf("%d",&ch);
   switch(ch)
   { case 1:if(isfull(mail))
            printf("low space");
            else
           pushinfo(&mail);
           break;
     case 2:maillist(&mail);
           break;
     case 3:mailtop(mail);
           break;
     case 4:printf("\nenter the name of the recipient to be deleted");
           scanf("%s",receiver);
           delet(&mail,receiver);
           printf("\n%s %s %s %s",mail.information[mail.top].name,mail.information[mail.top].recipient,mail.information[mail.top].mailID,mail.information[mail.top].subject);
           break;

     case 5:if(isempty(mail))
               printf("\ninbox empty");
               else
              displaymail(&mail);
           break;
     case 6:exit(0);
   }
   }while(ch!=6);
   }







