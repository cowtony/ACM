#include <stdio.h>
struct square
{
  int right,left,up,down;
} ppt[100];
int maxn(int a,int b)
{
  return (a>b)?a:b;
}
int minn(int a,int b)
{
  return (a<b)?a:b;
}
int overlap(int i,int j)
{
/*  if ( ((ppt[i].right<=ppt[j].right && ppt[i].right>=ppt[j].left)
    ||  (ppt[i].left<=ppt[j].right  && ppt[i].left>=ppt[j].left))
    && ((ppt[i].up<=ppt[j].up       && ppt[i].up>=ppt[j].down)
    ||  (ppt[i].down<=ppt[j].up     && ppt[i].down>=ppt[j].down)))
    return 1;
  if ( ((ppt[j].right<=ppt[i].right && ppt[j].right>=ppt[i].left)
    ||  (ppt[j].left<=ppt[i].right  && ppt[j].left>=ppt[i].left))
    && ((ppt[j].up<=ppt[i].up       && ppt[j].up>=ppt[i].down)
    ||  (ppt[j].down<=ppt[i].up     && ppt[j].down>=ppt[i].down)))
    return 1;

  return 0;
*/
	if (ppt[i].left>ppt[j].right || ppt[i].right<ppt[j].left ||
      ppt[i].down>ppt[j].up	|| ppt[i].up<ppt[j].down)
		return 0;
	else
		return 1;
}
int main(int argc, char* argv[])
{
  int p[100],n,x,y,area,r,i,j,t;
  while (scanf("%d%d",&x,&y)>0)
  {
    area=x*y;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
      scanf("%d%d%d",&x,&y,&r);
      ppt[i].right=x+r;
      ppt[i].left =x-r;
      ppt[i].up   =y+r;
      ppt[i].down =y-r;
      p[i]=1;
    }
    t=1;
    while (t)
    {
      t=0;
      for (i=0;i<n;i++)  if (p[i])
        for (j=i+1;j<n;j++)  if (p[j])
          if (overlap(i,j))
          {
            t=1;
            p[j]=0;
            ppt[i].right=maxn(ppt[i].right,ppt[j].right);
            ppt[i].left=minn(ppt[i].left,ppt[j].left);
            ppt[i].up=maxn(ppt[i].up,ppt[j].up);
            ppt[i].down=minn(ppt[i].down,ppt[j].down);
            break;
          }
    }
    for (i=0;i<n;i++)
      if (p[i])
        area-=(ppt[i].right-ppt[i].left)*
              (ppt[i].up-ppt[i].down);
    printf("%d\n",area);
  }
  return 0;
}
//---------------------------------------------------------------------------
