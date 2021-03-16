#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;

struct Node *next;

};

void display(struct Node *head)
{
struct Node *cur;
for(cur=head;cur!=NULL;cur=cur->next)
  {
   printf("\n%d",cur->data);
   printf("\n");

  }


}



struct Node* reverse(struct Node *head)
{struct Node *t1,*t2,*t3;
if(head==NULL||head->next==NULL)
    return(head);
t1=head;
t2=t1->next;
t3=t2->next;
while(t2!=NULL)
{
t2->next=t1;
t1=t2;
t2=t3;
if(t3!=NULL)
{
t3=t3->next;

}
}
head->next=NULL;
return(t1);

}

void *checkpalindrome(struct Node *head,struct Node *t1)
{int flag=0;
struct Node *cur1,*cur2;

for(cur1=head,cur2=t1;cur1!=NULL && cur2!=NULL;cur1=cur1->next,cur2=cur2->next)
{
 if(cur1->data!=cur2->data)
 {
 flag=1;
 break;
 }

}

if(flag==0)
printf("it is a palindrome");
else
printf("not a palindrome");

}

void *middleNode(struct Node *head)
{
struct Node *t1,*t2;
int c1=1,c2=1;

t1=head;
t2=t1->next->next;
while(t2!=NULL)
{
t1=t1->next;
c1++;
t2=t1->next->next;
if(t2!=NULL)
c2++;

}
if(c1>c2)
printf("%d is data in %d middle node",t1->data,c1);
else
printf("even nodes in the list");
}

struct Node *delenend(struct Node *head ,int n)
{
struct Node *t1,*cur,*prev;
int k=1;
t1=reverse(head);
for(prev=t1,cur=prev->next;k<n-1;k++,prev=prev->next,cur=cur->next);

prev->next=cur->next;
display(cur);
free(cur);


}
struct Node* creatlist(struct Node *head)
{
struct Node *first,*prev,*nw;
nw=prev=NULL;
first = head;
int data ;
char ch;
do{prev=nw;
   nw=(struct Node*)malloc(sizeof(struct Node));
   printf("enter data to be entered in new node");
   scanf("%d",&data);
   nw->data=data;

   if(first==NULL)
   {
    first=nw;
   }
   else
   {
   prev->next=nw;
   }
   printf("anymore Nodes 1/0");
   scanf("%d",&ch);


}while(ch==1);

 nw->next=NULL;

return(first);
}
int main()
{  struct Node *head,*t1;
  head=NULL;
  head=creatlist(head);
  int ch,n;
do
{printf("enter choice");
 printf("\n 1.checkpalindrome,2.reverse,3.middlenode,4.delete nth node from end,5->display6.exit");
 scanf("%d",&ch);
 switch(ch)
 {case 1:t1=reverse(head);
        checkpalindrome(head,t1);
        break;
  case 2:t1=reverse(head);
          display(t1);

        break;
  case 3:middleNode(head);
         break;
  case 4:printf("enter n")  ;
         scanf("%d",&n);
         delenend(head,n);
         display(head);
         break;
  case 5:display(head);
         break;


    case 6:exit(0);
 }

}
while(ch!=6);






}











