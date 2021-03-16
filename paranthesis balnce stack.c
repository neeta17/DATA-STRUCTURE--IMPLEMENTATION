# include <stdio.h>
# define  stacksize 10

struct stack
{
char x[10];
int top;

};
char stacktop(struct stack *stk)
{
return(stk->x[stk->top]);
}
void pop(struct stack *stk)
{char x;
x=stk->x[stk->top];
stk->top=stk->top-1;
}
void push(struct stack *stk,char x)
{stk->top=stk->top+1;
 stk->x[stk->top]=x;
}
int ismatchedpair(struct stack *stk,char x)
{
    if(stk->x[stk->top]==x)
        return 1;
    else
        return 0;
}

int isbalanced( char exp[])
{int i=0;
struct stack *stk;
while(exp[i])
    {
        if(exp[i]== '(' || exp[i]== '[' || exp[i]=='{')
           push(stk,exp[i]);

        if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
      {
          if(stk==NULL)
           return 0;
          else if((ismatchedpair((pop(stk)),exp[i])))
          return 1;
      }
i++;

}

if(stk==NULL)
return 1;
else
return 0;
}


int main()
{int x;
char exp[20];
printf("enter string");
scanf("%s",exp);
printf("%s",exp);
x=isbalanced(exp);
if(x==0)
    printf("no");
else
    printf("balanced");
return 0;

}
