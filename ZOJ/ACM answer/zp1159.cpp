//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>

struct basty
{
  int num,sum;
  struct basty* point;
} *pr[1000];

int transf(char st[])
{
  int rs=0;
  for (int i=0;st[i]!='\0';i++)
    if (st[i]!='-')
      if (st[i]>='0' && st[i]<='9')
      {
        rs*=10;
        rs+=st[i]-'0';
      }
      else
      {
        rs*=10;
        if (st[i]>'Q')
          st[i]--;
        rs+=(st[i]-'A')/3+2;
      }
//  printf("%d\n",rs);
  return rs;
}

void addto(int x,struct basty* cur)
{
  if (cur->point)
  {
    if (cur->point->num==x)
      cur->point->sum++;
    else
    if (cur->point->num<x)
      addto(x,cur->point);
    else
    {
      struct basty* q;
      q=new(struct basty);
      q->num=x;
      q->sum=0;
      q->point=cur->point;
      cur->point=q;
    }
  }
  else
  {
    struct basty* q;
    q=new(struct basty);
    q->num=x;
    q->sum=0;
    q->point=NULL;
    cur->point=q;
  }
}
void trav(struct basty* cur,int &t,int x)
{
  if (cur->point)
  {
    if (cur->point->sum)
    {
      if (x<10) printf("00%d-",x);
      else
      if (x<100)  printf("0%d-",x);
      else
                 printf("%d-",x);

      int y=cur->point->num;

      if (y<10)   printf("000%d",y);
      else
      if (y<100)  printf("00%d",y);
      else
      if (y<1000) printf("0%d",y);
      else
                  printf("%d",y);
      printf(" %d\n",cur->point->sum+1);
      t=0;
    }
    trav(cur->point,t,x);
    delete(cur);
  }
}
int output()
{
  int t=1;
  for (int i=0;i<1000;i++)
    trav(pr[i],t,i);
  return t;
}
int main(int argc, char* argv[])
{
  int N,I,i,n,x;
  char st[20];
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    if (I)
      printf("\n");
    for (i=0;i<1000;i++)
    {
      pr[i]=new(struct basty);
      pr[i]->num=-1;
      pr[i]->sum=0;
      pr[i]->point=NULL;
    }
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
      scanf("%s",st);
      x=transf(st);
      addto(x%10000,pr[x/10000]);
    }
    if (output())
      printf("No duplicates.\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
