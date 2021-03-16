#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
# define QSIZE 100
typedef struct
{int ID,capacity;
 char destcount[30];
}plane;
typedef struct
{
    plane MQ[3][QSIZE];
    int front[3],rear[3];

}MultipleQueue;


int isempty(MultipleQueue *mq,int r)
{if((mq->front[r])>(mq->rear[r]))
{
return 1;

}
 else
     return 0;
}
void enqueue(MultipleQueue *pq,plane info,int r)
{pq->rear[r]=(pq->rear[r])+1;
 pq->MQ[r][pq->rear[r]]=info;
}

plane dequeue(MultipleQueue *pq,int r)
{plane infor;
 infor=pq->MQ[r][pq->front[r]];
 pq->front[r]=(pq->front[r])+1;
 return(infor);

}
 MultipleQueue *divideQueue(MultipleQueue *pq,int n)
 {plane info;
  int firstcnt,secondcnt;
  firstcnt=secondcnt=0;
  char CName[20];
   while(!isempty(pq,0))
      {
          scanf("%s",CName);
       info=dequeue(pq,0);
       if(strcmp(info.destcount,CName)==0)
        {firstcnt++;
         enqueue(pq,info,1);
        }
      else
       {
        secondcnt++;
        enqueue(pq,info,2);

       }

      }
   printf("\n%d\n%d\n",firstcnt,secondcnt)  ;

   return(pq);

 }

plane peek(MultipleQueue mq,int r)
{  if(!isempty(&mq,2))
{
    return(mq.MQ[r][mq.front[r]]);
}
}

int main()
{
    MultipleQueue mq;
    int i,n;

 plane info,infor;
 for(i=0;i<2;i++)
 {
     mq.front[i]=0;
     mq.rear[i]=-1;
 }
   scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
     scanf("%d %s %d",&info.ID,info.destcount,&info.capacity);

     enqueue(&mq,info,0);
 }
     divideQueue(&mq,n);

  if(isempty(&mq,2))
 {
     printf("\n 0");
 }
 else
 {
    while(!isempty(&mq,2))
    {
    info=dequeue(&mq,2);
    printf("%d %s %d",info.ID,info.destcount,info.capacity);
    printf("\n");
    }
 }
  while(!isempty(&mq,2))
 {
     info=dequeue(&mq,2);
     if(info.capacity>(peek(mq,2)).capacity)
     infor=info;
 }
 printf("\n %d %s %d",infor.ID,infor.destcount,infor.capacity);

    return 0;
}
