

#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10

struct Stack
{
    int s[STACKSIZE];
    int top;
};

int isfull(struct Stack stk)
{
    return(stk.top == (STACKSIZE-1));
}

int isempty(struct Stack stk)
{
    return(stk.top == -1);
}

void push(struct Stack *ps,int data)
{
    ps->s[++(ps->top)] = data;
}

int pop(struct Stack *ps)
{
    return ps->s[(ps->top)--];
}

int stackTop(struct Stack stk)
{
    return stk.s[stk.top];
}

void displayStack(struct Stack stk)
{
    while(!isempty(stk))
    {
        printf(" %d ",pop(&stk));
    }
}


void playGame(struct Stack *ps1,struct Stack *ps2)
{
    int Adata,Bdata;

    while(1)
    {
        if(isempty(*ps1) || isempty(*ps2))
            break;
        else
        {
            Adata = stackTop(*ps1);
            Bdata = stackTop(*ps2);
            if(Adata > Bdata)
            {
                printf("1 ");
                pop(ps2);
            }
            else if(Adata < Bdata)
            {
                printf("2 ");
                pop(ps1);
            }
            else
            {
                printf("0 ");
                pop(ps1);
                pop(ps2);
            }
        }
    }
}


//Main for sorting using recursion
int main()
{
    struct Stack a,b;
    int n,i,data;
    a.top = -1;
    b.top = -1;
    //Read number of elements to push into each stack
    scanf("%d",&n);

    //Read Arjun's stack data
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data);
        push(&a,data);
    }

    //Read Bheem's stack data
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data);
        push(&b,data);
    }

    playGame(&a,&b);


    return 0;
}




