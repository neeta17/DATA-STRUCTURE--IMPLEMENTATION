
# include<stdio.h>
# include<stdlib.h>
# define size 5
struct stack
{int S[size];
int top;
};

int isempty(struct stack *s)
{
if(s->top==-1)
    return 1;
else
    return 0;
}
 int isfull(struct stack *s)
 {
 if(s->top==size-1)
    return 1;
 else
    return 0;
 }

void push(struct stack *s,int x)
  { (s->top)=(s->top)+1;
  s->S[s->top]=x;
  }
  int pop(struct stack *s)
  {int x;
  x=s->S[s->top];
  s->top=s->top-1;
  return x;
  }

 void sortedinsert(struct stack *s,int x)
  {

      if(isempty(s)|| s->top!=size)
  {
    push(s,x);
    return;
   }
    int temp=pop(s) ;
    sortedinsert(s,x);
    push(s,temp);

  }
 void sortstack(struct stack *s)
  {int x;
      if(!isempty(s))
  {int x=pop(s);
   sortstack(s);


   sortedinsert(s,x);
   printf("\n%d",x);
  }

  }

int main()
  {struct stack s;
  int ch,x,i;
  s.top=-1;
  do
  {printf("\n1.push,2.pop,3.sortstack,4.display 5.exit");
   printf("enter choice");
   scanf("%d",&ch);
    switch(ch)
    {
       case 1:if(isfull(&s))
       printf("stack overfull");
              else
                printf("enter value");
                scanf("%d",&x);
                push(&s,x);
              break;

       case 2:if(isempty(&s))
              printf("stack underflow");
              else
               x=pop(&s);
            printf("%d",x);
               break;
       case 3: sortstack(&s);
               break;

       case 4:for(i=s.top;i>-1;i--)
              printf("\n%d",s.S[i]);
              break;
        case 5:exit;
    }
  }
  while(ch!=5);
  }
