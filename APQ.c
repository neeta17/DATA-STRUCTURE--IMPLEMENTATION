# include <stdio.h>
 # include <stdlib.h>



# define qsize 5
struct APQ{
int front ;
int APQueue[qsize];


};
int isfull (struct APQ *pq)
{if(qsize-1==pq->front)
return 1;
else return 0;

}
int isempty (struct APQ pq)
{if(pq.front==-1)
  return 1;
  else
    return 0;


}
void enqueue(struct APQ *pq,int data)
{int i;
i=pq->front;
if(!isfull(pq))
{
while(pq->APQueue[i]>data && i>-1)
 {
  pq->APQueue[i+1] =pq->APQueue[i];
   i++;


 }
 pq->APQueue[i+1] =data;
 pq->front=pq->front+1;
}
else
    printf("queue is full");

}

int dequeue(struct APQ pq)
{
    int data;
    if(!isempty(pq))
    {
    data=pq.front;
    pq.front=pq.front-1;
     return (data);

    }
    else
        printf("list is empty");






}
void display(struct APQ *pq)
{int i;
for(i=pq->front;i>-1;i--)
 {
    printf("%d",pq->APQueue[i]) ;
    printf("\n");


 }



}







int main()
{
struct APQ q;
int ch,data;
q.front=-1;
do
{printf("1.insert ,2.delete ,3.display ,4.exit");
printf("\n enter choice");
scanf(" %d",&ch);

  switch(ch)
  {case 1:printf("enter data");
          scanf("%d",&data);
          enqueue(&q,data);
           break;
 case 2:data=dequeue(q);
        printf("%d",data);
        break;
case 3:display(&q);
break;
case 4:exit(0);

  }






} while(ch!=4) ;
return 0;
}










