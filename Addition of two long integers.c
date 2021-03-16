

//addition of two long integers
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct node
{

int data;
struct node *next;

};
typedef struct node node;
 node* INSERT( node *head,int num)
{

 node *newnode,*temp;

 newnode=(node*)malloc(sizeof(node));
 newnode->data=num;
 if(head==NULL)
 {
   temp=(node*)malloc(sizeof(node));
   temp->data=-1;
   temp->next=newnode;
   newnode->next=temp;
   head=temp;
   return(head);
 }

 newnode->next=head->next;
 head->next=newnode;
 return(head);



/*else
{temp=head;
while(temp->next->data!=-1)
{temp=temp->next;
}

 newnode->next=temp->next;
 temp->next=newnode;
}*/




}
node* ADD_LONG(node *head1,node *head2)
{node *head3=NULL;
int total,num,carry=0;
int d=10;
head1=head1->next;
head2=head2->next;
 while(head1->data!=-1 && head2->data!=-1)
 {total=(head1->data)+head2->data+carry;
 num=total%d;
 head3=INSERT(head3,num);
 head1=head1->next;
 head2=head2->next;
 carry=total/10;
 }
while(head1->data!=-1)
{
 total=(head1->data)+carry;
 num=total%d;
 head3=INSERT(head3,num);
 head1=head1->next;
 carry=total/10;

}
  while(head2->data!=-1)
{
total=(head2->data)+carry;
carry=total/10;
 num=total%d;
 head3=INSERT(head3,num);
 head2=head2->next;

} if(carry)
    {
     head3=INSERT(head3,carry);
    }


  return(head3) ;



}


void display1(node *head)
{   node *cur,*temp;

    if(head==NULL)
    {
     printf("list is empty") ;
     return;
    }

    cur=head->next;
    while(cur->data!=-1)
    {
 printf("%d",cur->data);
 cur=cur->next;
    }

}
void display2(node *head)
{

 node *cur=head->next;
 while(cur->data!=-1)
 {

     printf("%d",cur->data);
     cur=cur->next;
 }

}

int main()
{
    node *head1=NULL,*head2=NULL,*head3;
    int digit,i;
    char n1[30],n2[30];
    printf("enter the first number");
    scanf("%s",n1);
    printf("first number is");
    for(i=0;i<(strlen(n1));i++)
    {
       digit=n1[i]-'0';
       head1=INSERT(head1,digit);
       display1(head1);
    }
    printf("\n enter second number");
    scanf("%s",n2);
    printf("\nsecond number is");
    for(i=0;i<(strlen(n2));i++)
    {
     digit=n2[i] -'0';
     head2=INSERT(head2,digit) ;
     display1(head2);
    }
    printf("\naddition of two integers is...");
    head3=ADD_LONG(head1,head2);
    display2(head3);
     return 0;

}





