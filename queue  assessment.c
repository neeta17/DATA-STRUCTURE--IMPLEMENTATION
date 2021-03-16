#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
# define qsize 10
struct Q
{char CQ[qsize];
 int front ,rear;
};
int isfull(struct Q q)
{
    if(((q.rear+1)%qsize)==q.front)
    return 1;
 else
     return 0;
}

int isempty(struct Q q)
{
    if(q.rear==q.front)
  return 1;
 else
     return 0;

}
void enqueue(struct Q *q,char x)
{
    q->rear=(q->rear+1)%qsize;
    q->CQ[q->rear]=x;
}

char dequeue(struct Q *q)
{char x;
 q->front=(q->front+1)%qsize;
 x=q->CQ[q->front];
 return(x);
}


int changecolor(struct Q *q)
{int i,c=0;
 for(i=q->front;i<=q->rear;)
 {while(q->CQ[q->front]!='G')
 {
     for(i=q->front;i<=q->rear;i++)
     {if(q->CQ[i]!='G')
     {
         q->CQ[i]=q->CQ[i+1];
         c++;
     }
     }

 }

  i=q->front;
 }


    return c;

}


int main()
{
    struct Q q;
 int ch,c,n;
 printf("enter n");
 scanf("%d",&n);
q.front=q.rear=n-1;
 char x;
 do{
     printf("\nenter choice");
  printf("\n1.enqueue,2.dequeue,3.changecolor,4.exit");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:if(!isfull(q))

              {
              scanf("%c",&x);
              enqueue(&q,x);
              }
              else
                {
               printf("\nqueue full");

                }
              break;
      case 2:if(isempty(q))
              printf("\nqueue empty");
             else
            {
                x=dequeue(&q);
               printf("%c",x);
            }
            break;
        case 3:c=changecolor(&q);
               printf(" %d",c);
            break;
        case 4:break;

    }

   }while(ch!=4)  ;
 return 0;
}
