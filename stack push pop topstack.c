

#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 5

struct stack
{
 int s[30],top;
};
int isfull(struct stack stk)
{
if(stk.top==(STACKSIZE-1))
    return 1;
    else
    return 0;
}

int isempty(struct stack stk)
{if(stk.top==-1)
return 1;
else
return 0;
}
void push(struct stack *stk)
{int data;
printf("enter to be pushed");
scanf("%d",&data);
(stk->top)++;
stk->s[stk->top]=data;
}
int pop(struct stack *stk)
{int data;
data=stk->s[stk->top];
(stk->top)--;
 return(data);

}
int stacktop(struct stack stk)
{
return(stk.s[stk.top]);

}
void displaystack(struct stack stk)
{
int i;
for(i=stk.top;i>=0;i--)
{
  printf("\n%d",stk.s[i]);
}

}

int main()
{
struct stack stk;
int ch,inp;
stk.top=-1;
do{printf("\nenter choice");
  printf("\n1.push,2.pop,3.stacktop,4.displaystack,5.exit");
  scanf("%d",&ch);
  switch(ch)
{


case 1:if(!isfull(stk))
        push(&stk);
        break;
case 2:if(!isempty(stk))
       inp=pop(&stk);
       printf("%d",inp);
       break;
case 3:inp=stacktop(stk);
       printf("%d",inp);
       break;
case 4:displaystack(stk);
       break;
case 5:exit(0);
 }
}while(ch!=5);

return 0;
}
