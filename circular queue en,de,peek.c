
#include<stdio.h>
# define qsize  5

    struct queue
{   int cq[qsize];
    int front,rear;

} cqu;

int isfull(struct queue *cqu)
{  if((cqu->rear+1)==cqu->front)
      return 1;
   else
      return 0;
}
int isempty(struct queue *cqu)
{if(cqu->rear==cqu->front)
    return 1;
else
    return 0;
}
void display(struct queue cqu)
{int i;
if(cqu.rear==qsize-1)
    printf("queue empty");
else
for(i=0;i<=cqu.rear;i++)
{
  printf("\n%d",cqu.cq[i])  ;

}


}

void encqueue(struct queue *cqu,int data)
{if(!(isfull(cqu)))
{   cqu->rear=(cqu->rear+1)%qsize ;
    cqu->cq[cqu->rear]=data ;
}
else
    printf("full queue");
}
int decqueue(struct queue *cqu)
{   int data;
    if(!(isempty(cqu)))
{   cqu->front=(cqu->front+1)%qsize;
    data=cqu->cq[cqu->front];


return(data);
}
  else
    printf("empty queue");
}

int peekcq(struct queue cqu)
{   cqu.front=(cqu.front+1)%qsize;
    return(cqu.cq[cqu.front]);
}

int main()
{
    int ch,data=0;
    cqu.front=cqu.rear=qsize-1;

 do
 {  printf("\n1.encqueue,2.decqueue,3.peekcq,4.display,5.exit");
    printf("\nenter choice");
    scanf(" %d",&ch);
    switch(ch)
    {
        case 1: printf("enter data");
                scanf("%d",&data);
                encqueue(&cqu,data);
                break;
        case 2: data=decqueue(&cqu);
                printf(" deleted data is %d",data);
                break;
        case 3: data=peekcq(cqu);
                printf("%d is peek",data);
                break;

        case 4: display(cqu);
        break;
        case 5: break;

 }
 }
        while(ch!=5);

}
