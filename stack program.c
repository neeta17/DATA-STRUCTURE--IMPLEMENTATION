# include<stdio.h>
# include<stdlib.h>
# define stacksize 5
struct stack
{int S[stacksize];
int top;
};

int isempty(struct stack *s)
{
if(s->top==-1)
    return 1;
else
    return 0;
}

int stacktop(struct stack s)
{
return(s.S[s.top]);


}
 int isfull(struct stack *s)
 {
 if(s->top==stacksize-1)
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

int sumtotal(struct stack s)
{int sum=0,i,x;
for(i=s.top;i>-1;i--)
{
sum=sum+stacktop(s);
pop(&s);
}
return sum;


}
 void sortedinsert(struct stack *s,int x)
  {

      if(isempty(s)|| x>s->S[s->top])
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
int max(struct stack s)
{int i,large;
large=stacktop(s);
for(i=(s.top-1);i>-1;i--)
{
 if(s.S[i]>large)
    large=s.S[i];
}
  return large;
}

int min(struct stack s)
{int i,small;
small=stacktop(s);
for(i=(s.top-1);i>-1;i--)
{
 if(s.S[i]<small)
    small=s.S[i];
}
  return small;
}

int main()
  {struct stack s;
  int ch,x,i;
  s.top=-1;
  do
{printf("\n1.push,2.pop,3.sumtotal,4.displaystack ,5.sort in ascending.6.max in stack,7.min in stack,8.exit");
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
              x=stacktop(s);
            printf("%d",x);
               break;
       case 3:x=sumtotal(s);
               printf(" sum:%d",x);
               break;

       case 4:for(i=s.top;i>-1;i--)
              printf("\n%d",s.S[i]);
              break;
        case 5:sortstack(&s);
        break;
        case 6:x=max(s);
               printf(" max:%d",x);
               break;
        case 7:x=min(s);
               printf("min:%d",x);
        case 8:exit;


  }
  }while(ch!=8);
  return 0;

  }

