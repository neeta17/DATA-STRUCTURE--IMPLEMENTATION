#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

# define stacksize 5
struct stack
{int str[stacksize];
 int top;
};

int isfull(struct stack *stk)
{if(stk->top==(stacksize-1))
    return 1;
 else
     return 0;
}

int isempty(struct stack *stk)
{if(stk->top==-1)
    return 1;
 else
     return 0;
}

int stacktop(struct stack *stk)
{   if(!(isempty(stk)))
    return(stk->str[stk->top]);
    else
        printf("stack underflow");
}
 void push(struct stack *stk,int data)
 {stk->top=(stk->top)+1;
  stk->str[stk->top]=data;

 }

int pop(struct stack *stk)
{int data;
 data=stk->str[stk->top];
 stk->top=(stk->top)-1;
 return (data);

}


 void Game(struct stack *Arj,struct stack *Bhe)
 {
    int a,b,c;
     while(!isempty(Arj) && !isempty(Bhe))
  { a=stacktop(Arj);
      b=stacktop(Bhe);
      if(a>b)
      {pop(Bhe);
       c=1;
       printf(" %d",c);
      }
      else if(b>a)
      {pop(Arj);
       c=2;
       printf(" %d",c);
      }
       else if(a==b)
      {c=0;
        printf(" %d",c);
      }
  }
 }

int main()
{
 struct stack Arj;
 struct stack Bhe;
 Arj.top=-1;
 Bhe.top=-1;
 int data;
           while(!(isfull(&Arj)))
          { printf("enter data to be pushed in arjun's stack");
            scanf("%d",&data);
            push(&Arj,data);
          }

          while(!(isfull(&Bhe)))
          {printf("enter data to be pushed in Bheem's stack");
            scanf("%d",&data);
            push(&Bhe,data);
          }

     Game(&Arj,&Bhe);



}
