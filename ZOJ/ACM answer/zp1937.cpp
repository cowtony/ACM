#include <stdio.h>
#include <memory.h>

struct typ
{
  int num,suf,dip;
}que[55000];

int main(int argc, char* argv[])
{
  int t,s,pf,sf,ps[110];
  s=1;
  pf=0;
  sf=1;
  que[0].suf=-1;
  que[0].num=1;
  que[0].dip=1;

  memset(ps,0,sizeof(ps));

  while (1)
  {
    t=pf;
    while (t>=0)
    {
      que[sf].suf=pf;
      que[sf].num=que[t].num+que[pf].num;
      que[sf].dip=que[pf].dip+1;
      if (que[sf].num<=100 && ps[que[sf].num]==0)
      {
        s++;
        //printf("%d %d %d\n",s,que[sf].num,sf);
        ps[que[sf].num]=sf;
        if (s==100)
          break;
      }
      sf++;
      t=que[t].suf;
    }
    if (s==100)
      break;
    pf++;
  }
  //printf("%d\n",sf);

  int i,a[110][12];

  for (i=1;i<=100;i++)
  {
    t=ps[i];
    //printf("%d ",i);
    s=0;
    while (t>=0)
    {
      a[i][++s]=que[t].num;
      //printf("%d ",que[t].num);
      t=que[t].suf;
    }
    a[i][0]=s;
    //printf("\n");
  }
  while (scanf("%d",&s) && s)
  {
    printf("1");
    for (i=a[s][0]-1;i>0;i--)
      printf(" %d",a[s][i]);
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
