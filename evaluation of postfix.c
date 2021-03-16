#include<stdio.h>
#include<stdlib.h>
#include<math.h>
# define STACKSIZE 5

struct stack
{
    double s[STACKSIZE];
    int top;
};



void push(struct stack *ps,char data)
{(ps->top)++;
ps->s[ps->top]=data;
}

double pop(struct stack *ps)
{double data;
data=ps->s[ps->top];
(ps->top)--;
return(data);
}
int main()
{ char postfix[100];
  double res;
  printf("enter postfix expression");
  scanf("%s",postfix);
  res=evalpostfix(postfix);
  printf("result=%lf",res);
  return 0;
}

  char evalpostfix(char postfix[])
  { struct stack stk;
  int p;
  double op1,op2,res;
  char inp;
  stk.top=-1;
  for(p=0;(inp=postfix[p])!='\0';p++)
  {
       if(isalpha(inp))
  {
  printf("\n enter value of variable");
  scanf("%lf",&res);
   push(&stk,res);
  }


  else if(isdigit(inp))
  {
  res=(inp)-'0';
  push(&stk,res);
  }
  else
  {
  op2=pop(&stk);
  op1=pop(&stk);
  switch(inp)
  {case '+':res=op1+op2;break;
   case '-':res=op1-op2;break;
   case '/':res=op1/op2;break;
   case '*':res=op1*op2;break;
   case '$':res=pow(op1,op2) ; break;

  }
  }
  push(&stk,res);
  }
  return(res=pop(&stk));

  }





















