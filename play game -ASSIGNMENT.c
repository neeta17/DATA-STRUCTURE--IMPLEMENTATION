#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10

struct Stack
{
    int S[STACKSIZE];
    int top;
};

int isempty(struct Stack *stk)
{
    if(stk->top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *ps,int data)
{
    ps->top = ps->top + 1;
    ps->S[ps->top] = data;
}

int pop(struct Stack *ps)
{
    int data;
    data = ps->S[ps->top];
    ps->top = ps->top - 1;
    return data;
}

void fillStack(struct Stack *ps)
{int i,r;

      if(isempty(ps))
  {
    ps->top = -1;
    for(i=1;i<=STACKSIZE;i++)
    {
        r = rand() % 100;
        push(ps,r);
    }

}
}
void displaystack(struct Stack stk)
{
    int i;
    printf("\n Stack elements : ");
    for(i=0;i<=stk.top;i++)
        printf(" \n %d  ",stk.S[i]);
}




int primenumber(int N)
{
    int i;
    for(i=2;i<N;i++)
    {
        if(N%i == 0)
            return 0;
    }
    return 1;
}

int playGame(struct Stack *psa,struct Stack *psb)
{
    int score,data,ch;
    score=0;
    while(1)
   {
       if(isempty (psa)  && (isempty(psb)))
    break;
    if(!isempty(psa) && !isempty(psb))
    {
      printf("want to pop from A->1,B->2")  ;
      scanf("%d",&ch);
      if(ch==1)
        data=pop(psa);
      else
        data=pop(psb);
    }

    else if(!isempty(psa))
    {
         data=pop(psa);
    }
         else
         {
            data=pop(psb);
         if(primenumber(data))
            break;
         }
   }
         score=score+data;
        return score;
}
int main()
{
    struct Stack A,B;
    int score,ch;
    do
    {
      printf("enter 1.fillstack,2.display stack 3.break;")  ;
      scanf("%d",&ch);
      switch(ch)
    {
    case 1:fillStack(&A);
           //fillStack(&B);
           break;
    case 2:displaystack(A);
          //  displaystack(B);
            break;
    }
   }while(ch!=2);

   // score = playGame(&A,&B);
   // printf("\nScore of nick is : %d",score);

    return 0;
}
