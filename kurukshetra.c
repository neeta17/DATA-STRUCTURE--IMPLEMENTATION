#include<stdio.h>
#include<stdlib.h>

struct stage
{
  int code;
  struct stage *next;
};

  struct stage* createlist(head)
  {  int c,code;
    struct stage *prev,*nw,*first;
    prev=first=nw=NULL;
    do
    {
      prev=nw;
      nw=(struct stage*)malloc(sizeof(struct stage));
      nw->next=NULL;
      printf("enter code to be entered in the new node");
      scanf("%d",&code);
      nw->code=code;
      if(first==NULL)
      {
          first=nw;
      }
      else
      {prev->next=nw;
      }

      printf("anymore nodes 1/0") ;
      scanf("%d",&c);


    }while(c==1);
     nw->next=NULL;
     return(head);
  }

  struct stage* reverse(struct stage *head)
  { struct stage *t1,*t2,*t3;
  t1=head;
  t2=t1->next;
  t3=t2->next;
  while(t2!=NULL)
  {
    t2->next=t1;
    t1=t2;
    t2=t3;
    if(t3!=NULL)
        t3=t3->next;
  }
  head->next=NULL;
  head=t1;
  return(head);

  }




  void enterstage(struct stage *head)
  {struct stage *cur,*t1,*first;
  int skey,found;
  for(cur=head;cur!=NULL;cur=cur->next)
  {
      printf("enter skey");
      scanf("%d",&skey);
      if(cur->code==skey)
  {
     continue;
  }
  found=1;
  }
    /*if(found!=1)
    {
        found=0;
    }*/

   if(found==1)
 {
        first=reverse(head);
        for(cur=head,t1=first;cur!=NULL;cur=cur->next,t1=t1->next);
        {
         if(cur==NULL)
            printf("return successful");
        }
   /*{
        if(cur->code!=t1->code)
    {    found=0;
        break;
    }

   }}*/
       /* if(found==0)
        printf("entry not successful");
        else
        printf("entry successful");*/

  }

}

 int main()
 {struct stage *head=NULL;

 head=createlist(head);
 int ch;
 do{
    printf("enter choice");
    printf("1.enter stage,2.exit");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:enterstage(head);
              break;
      case 2:exit(0);
    }

 }while(ch!=2);
   return 0;
 }



















































