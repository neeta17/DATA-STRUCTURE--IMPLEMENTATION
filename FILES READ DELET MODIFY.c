typedef struct
{
 int rollno;
 char name[20]   ;
 float per;



}student;
#include<stdio.h>
void read(student *sp)
{
 printf("\n enter student details")   ;
 scanf("%d%d %f",&sp->rollno,sp->name,&sp->per);

}
void save(char fnm[],student s)
{FILE *fp;
fp=fopen(fnm,"w");
fprintf("%d %s %f\n",s.rollno,s.name,s.per);
fclose(fp);
}
void display(char fnm[])
{FILE *fp;
student s;
fp=fopen(fnm,"r");
while(1)
{fscanf(fnm,"%d %s %f",&s.rollno,s.name,&s.per);
if(feof(fp))
break;
printf("\n%d %s %f",s.rollno,s.name,s.per);

}
fclose(fp);


}
void search(char fnm[],int rno)
{
  FILE *fp;
student s;
  int flag=0;
  while(1)
  {
    fscanf(fp,"%d %s %f",&s.rollno,s.name,&s.per)  ;
    if(feof(fp))
        break;
    if(rno==s.rollno)
    {flag++;
    printf("\n%d %s %f",s.rollno,s.name,s.per);

     break;
    }

  }
   if(flag==0)
        printf("record not found");
   fclose(fp);



}
void delet(char fnm[],int rno)
{

   int flag=0;
   student s;
   FILE *fps,*fpd;
   fps=fopen(fnm,"r");
   fpd=fopen("temp.txt","w");
   while(1)
   {
      fscanf(fps,"%d%s%f",s.rollno,s.name,s.per) ;
      if(feof(fps))
        break;
      if(s.rollno==rno)
      {printf("data to be deleted is %d %s %f",s.rollno,s.name,s.per);
      flag++;

      }
       else{

        fprintf(fpd,"%d%s %f",s.rollno,s.name,s.per);

       }

    }
       fclose(fps);
       fclose(fpd);



       if(flag==0)
       {
         printf("record not found")  ;
         remove("temp.txt");

       }
       else{

    remove(fnm);
    rename("temp.txt",fnm);


       }


   }

void modify(char fnm[],int rno)
{
    int flag=0;
   FILE *fps,*fpd;
   fps=fopen(fnm,"r") ;
   fpd=fopen("temp.txt","w");
student s;
   while(1)
    {
        fscanf(fps,"%d%s%f",&s.rollno,s.name,&s.per);

        if(feof(fps));
        break;
        if(s.rollno==rno)
        {
          flag++;
          printf("\n existing data is %d%s%f",s.rollno,s.name,s.per)  ;
          printf("\nenter name and per");
          scanf("%s%f",s.name,s.per);


        }

        fprintf(fpd,"%d%s %f",s.rollno,s.name,s.per);





    }
    fclose(fps);

fclose(fpd);
if(flag==0)
    {
    printf("record not found");
remove("temp.txt");

}
  else
  {
   printf("\n no of records modified is %d",flag)   ;

      remove(fnm);
      rename("temp.txt",fnm);
  }


}








int main()

{ student s;
int rno;
char ch,filename;
printf("enter filename");
scanf("%s",&filename);
printf("1.read and save,2.display,3.search,4.delet,5.modify,6.exit");
printf("enter choice");
getch();
switch(ch)
{
case 1: read(&s);
        save(filename,s);
         break;
case 2:display(filename);
       break;
case 3:
case 4:
case 5:printf("enter roll no to be searched");
       scanf("%d",&rno);
       if(ch=='3')
     search(filename,rno);
     else if(ch=='4')
        modify(filename,rno);
     else (ch=='5')
        delet(filename,rno);
       break;
case 6:
       break;



}
  while(ch!='6');


}
