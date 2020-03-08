//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
struct StrQs
{
  int v[2],cost;
} q[499500];
int Cmp(void const *a, void const *b)
{
  StrQs p1=*(StrQs*)a,p2=*(StrQs*)b;
  if (p1.cost<p2.cost)
    return -1;
  if (p1.cost>p2.cost)
    return 1;
  return 0;
}

int main(int argc, char* argv[])
{
  int N,mcost,m,n,t,i,j,x,s,r,ad[1000],p[1000];
  scanf("%d",&N);
  while (N--)
  {
    scanf("%d",&n);
    for (i=0;i<n;i++)
      scanf("%d",ad+i);
    s=0;
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
      {
        scanf("%d",&x);
        if (j>i)
        {
          q[s].v[0]=i;
          q[s].v[1]=j;
          q[s].cost=x+ad[i]+ad[j];
          s++;
        }
      }

    qsort(q,s,sizeof(StrQs),Cmp);


    r=0;
    mcost=0;
    m=0;
    for(i=0;i<n;i++)
      p[i]=i;

    while (m<n-1)
    {
      if (p[q[r].v[0]]!=p[q[r].v[1]])
      {
        mcost+=q[r].cost;
        j=p[q[r].v[1]];
        for(i=0;i<n;i++)
        {
          if(p[i]==j)
            p[i]=p[q[r].v[0]];
        }
        m++;
      }
      r++;
    }
    printf("%d\n",mcost);
  }
  return 0;
}
//---------------------------------------------------------------------------
/*
    //r=0;x=1;m=n;
    p[q[0].v[0]]=p[q[0].v[1]]=1;
    mcost=q[0].cost;
    while (n-->2)
    {
      //kruskal;
      if (p[q[r].v[0]]==0 && p[q[r].v[1]]==0)
        p[q[r].v[0]]=p[q[r].v[1]]=x++;
      else
      if (p[q[r].v[0]]==0)
        p[q[r].v[0]]=p[q[r].v[1]];
      else
      if (p[q[r].v[1]]==0)
        p[q[r].v[1]]=p[q[r].v[0]];
      else
      {
        t=p[q[r].v[1]];
        for (j=0;j<m;j++)
          if (p[j]==t)
            p[j]=p[q[r].v[0]];
      }

      while (p[q[r].v[0]]==p[q[r].v[1]]
        && p[q[r].v[0]])
          r++;
      mcost+=q[r].cost;

      //prim
      t=1;
      while (t<s)
      {
        if (p[q[t].v[0]]+p[q[t].v[1]]==1)
        {
          mcost+=q[t].cost;
          p[q[t].v[0]]=p[q[t].v[1]]=1;
          break;
        }
        t++;
      }
    }
*/

