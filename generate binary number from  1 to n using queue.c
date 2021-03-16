#include <stdio.h>
#include <stdlib.h>
#define QSIZE 100

struct Queue
{
    char Q[QSIZE][50];
    int front, rear;
};

void enqueue(struct Queue *pq, char data[])
{
    pq->rear = pq->rear + 1;
    strcpy(pq->Q[pq->rear],data);
}

char *dequeue(struct Queue *pq)
{
    char *data = (char *)malloc(sizeof(char)*50);
    strcpy(data,pq->Q[pq->front]);
    pq->front = pq->front + 1;
    return data;
}

void generateBinary(int N)
{
    int i;
    struct Queue q;
    char *data,tmp[50];
    q.front = 0;
    q.rear = -1;
    enqueue(&q,"1");
    for(i=1;i<=N;i++)
    {
        data = dequeue(&q);
        printf("\n %d  =>  %s",i,data);

        strcpy(tmp,data);
        strcat(tmp,"0");
        enqueue(&q,tmp);

        strcpy(tmp,data);
        strcat(tmp,"1");
        enqueue(&q,tmp);
    }
}

int main()
{
    generateBinary(10);
    return 0;
}
