#include<stdio.h>
#include<stdlib.h>

# define STACKSIZE 5

struct stack
{char s[STACKSIZE];
int top;
};

int isempty(struct stack stk)
{return(stk.top==-1);

}

void push(struct stack *ps,char data)
{(ps->top)++;
ps->s[ps->top]=data;
}

char pop(struct stack *ps)
{char data;
data=ps->s[ps->top];
(ps->top)--;
return(data);
}
char stacktop(struct stack stk)
{
return(stk.s[stk.top]);

}
int isoperand(char inp)
{return(isalpha(inp)||isdigit(inp));
}
 char isopLR(char inp)
{
return(inp=='+'||inp=='-'||inp=='/'||inp=='*');
}
int isopRL(char inp)
{
return(inp=='$');

}

int precedence(char inp)
{
    if(inp=='+'||inp=='-')
    return 1;
 else if(inp=='/'|| inp=='*')
    return 2;
 else if(inp=='$')
    return 3;
}

void convert(char inf[],char postf[])
{struct  stack stk;
 int i,p;
 char inp;
 stk.top=-1;
 for(i=p=0;(inp=inf[i])!='\0';i++)
 {
 if(isoperand(inp))
 postf[p++]=inf[i];
 else if(inp==')')
 {
 while((stacktop(stk))!='(')
 {postf[p++]=pop(&stk);

 }
  pop(&stk);
 }
 else
 {
     do
 {if(isempty(stk)||inp=='('||stacktop(stk)=='(')
    break;
  else if((isopLR(inp))&& precedence(inp)>precedence(stacktop(stk)))
    break;
  else if((isopRL(inp))&&precedence(inp)>=precedence(stacktop(stk)))
  break;
  else
    postf[p++]=pop(&stk);
 }while(1);
 push(&stk,inp);
 }
}
while(!isempty(stk))
{
postf[p++]=pop(&stk);
}
postf[p]='\0' ;

}

int main()
{   char infix[100],postfix[100];
    printf("enter infix expression");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("%s",postfix);
    return 0;

}















