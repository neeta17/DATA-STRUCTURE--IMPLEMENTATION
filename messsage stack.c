#include<stdio.h>
# define STACKSIZE 5


 struct message
 {
    char messg[250];
    char phone[15];

 };
 struct stack
 {
    struct message s[STACKSIZE];
    int top;

 };

  int main()
  {struct stack stk;
   struct message data;
    int ch;
    stk.top=-1;


    do
    {printf("enter choice");
     printf("1.push,2.pop,3.stacktop,4.display,5.exit");
     scanf("%d",&ch);
     switch(ch)
     { case 1:if(isFull(stk))
              printf("stack overf




  int isFull(struct stack stk)
  {
    if(stk.top==(STACKSIZE-1))
        return 1;

    else
        return 0;
  }


  int isEmpty(struct stack stk)
  {if(stk.top==-1)
        return 1;
   else
        return 0;
  }

  void readdata(struct message *data)
  { printf("enter phone and message");
  scanf("phone=%s,%s=message",data->phone,data->messg);

  }

  void push(struct stack *stk,struct message data)
  {(stk->top)++;
   stk->s[stk->top]=data;
  }
  struct message pop(struct stack *stk,struct message data)
  {
      data=stk->s[stk->top];
  stk->top--;
return data;
  }

  void displaydata(struct message data)
  {
      printf("\n%s %s",&data.phone,&data.messg);

  }
   struct message stacktop(struct stack stk)
  {
     return(stk.s[stk.top]);
  }

  void displaystack(struct stack stk)
  {int i;
  for(i=stk.top;i>=0;i--)
  {
   displaydata(stk.s[i]);

  }

  }
  int main()
  {struct stack stk;
   struct message data;
    int ch;
    stk.top=-1;


    do
    {printf("enter choice");
     printf("1.push,2.pop,3.stacktop,4.display,5.exit");
     scanf("%d",&ch);
     switch(ch)
     { case 1:if(isFull(stk))
              printf("stack overflow");
              else
              {
                readdata(&data);
                push(&stk,data);
              }
              break;
      case 2:if(isEmpty(stk))
             printf("stack underflow");
             else
             {
             data=pop(&stk,data);
            displaydata(data);
             }
             break;
    case 3:if(isEmpty(stk))
             printf("stack underflow");
             else
           data= stacktop(stk);
           displaydata(data);
            break;

    case 4:if(isEmpty(stk))
             printf("stack underflow");
             else
            displaystack(stk);
            break;

    case 5:break;

     }
    }
      while(ch!=5);

  }

