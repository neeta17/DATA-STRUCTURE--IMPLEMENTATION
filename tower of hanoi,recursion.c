# include <stdio.h>

int main()
{
    int n;
    printf("\nenter no of discs;");
    scanf("\n%d",&n);
    TOH(n,'A','B','C');

}

void TOH(int n,char p1,char p2,char p3)
{
    if(n==1)

     printf("\nmove disc 1 from %c to %c ",p1,p3)   ;

    5else
      {
        TOH(n-1,p1,p3,p2)  ;
        printf("\nmove disc %d from %c to %c ",n,p1,p3);
        TOH(n-1,p2,p1,p3);
      }








}
