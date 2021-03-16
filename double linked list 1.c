#include<stdio.h>
#include<stdlib.h>



struct Node
{struct Node *previous;
int roll;
struct Node *next;
};



void display(struct Node *head)
{
struct Node *cur;
for(cur=head;cur!=NULL;cur=cur->next)
  {
   printf("\n%d",cur->roll);
   printf("\n");

  }


}

 struct Node *createDlistright( struct Node *first)
 {int data;
 struct Node *prev,*nw;
 char ch;
 do
{prev=nw;
nw=(struct Node*)malloc(sizeof(struct Node));
printf("enter data");
scanf("%d",&data);
nw->roll=data;
nw->next=prev;
if(prev!=NULL)
{
    prev->next=nw;
    nw->previous=prev;
    printf("anymore nodes 1/0");
    scanf("%d",&ch);
}
else
  {
    prev=nw;
    prev->next=NULL;
    prev->previous=NULL;
  }
}while(ch!=0);
nw->next=NULL;
return (nw);

 }
int main()
{struct Node *first;
first=NULL;
first=createDlistright(first);

 int ch=1;
do
{printf("enter choice");
 printf("\n 1.display ,2.exit");
 scanf("%d",&ch);
 switch(ch)
 {
    case 1:display(first) ;
           break;
    case 2:exit;


 }

}
while(ch!=0);
}
