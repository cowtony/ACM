//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>

long double xx[100010],xy[100010],
            tx[100010],ty[100010];
int n;

int qslist(int l,int h,long double x[],long double y[])
{
  int i,j;
  long double w,t;
  i=l;
  w=x[l];

  for (j=l+1;j<=h;j++)
    if (x[j]<w)
    {
      i++;
      if (i!=j)
      {
        t=x[i];
        x[i]=x[j];
        x[j]=t;
        t=y[i];
        y[i]=y[j];
        y[j]=t;
      }
    }
  t=x[i];
  x[i]=x[l];
  x[l]=t;

  t=y[i];
  y[i]=y[l];
  y[l]=t;
  return i;
}
void qst(int l,int h,long double x[],long double y[])
{
  if (l<h)
  {
    int p=qslist(l,h,x,y);
    qst(l,p-1,x,y);
    qst(p+1,h,x,y);
  }
}
long double dis(int i,int j,long double x[],long double y[])
{
  return (x[i]-x[j])*(x[i]-x[j])+
         (y[i]-y[j])*(y[i]-y[j]);
}
long double closestpair(int low,int high)
{
  if (high-low==1)
    return dis(low,high,xx,xy);
  else
  if (high-low==2)
  {
    long double d1=dis(low,high,xx,xy),
                d2=dis(low,low+1,xx,xy),
                d3=dis(low+1,high,xx,xy);
    if (d1<=d2 && d1<=d3)
      return d1;
    if (d2<=d1 && d2<=d3)
      return d2;
    if (d3<=d1 && d3<=d2)
      return d3;
  }
  else
  {
    int i,j,mid=(low+high)/2;
    long double r0,r1=closestpair(low,mid),
                r2=closestpair(mid+1,high);
    if (r2<r1)
      r1=r2;
    int s=1;
    tx[0]=xx[mid];
    ty[0]=xy[mid];

    for (i=mid+1;i<=high;i++)
      if (xx[i]-xx[mid]<r1)
      {
        tx[s]=xx[i];
        ty[s++]=xy[i];
      }
      else
        break;

    for (i=mid-1;i>=low;i--)
      if (xx[mid]-xx[i]<r1)
      {
        tx[s]=xx[i];
        ty[s++]=xy[i];
      }
      else
        break;

    qst(0,s-1,tx,ty);

    r2=r1;
    for (i=0;i<s-1;i++)
      for (j=i+1;j<s;j++)
        if (ty[j]<=ty[i]+r2)
        {
          r0=dis(i,j,tx,ty);
          if (r0<r2)
            r2=r0;
        }
        else
          break;
    return r2;
  }
}
int main(int argc, char* argv[])
{
  int i,j;
  long double r;

  while (scanf("%d",&n) && n)
  {
    for (i=0;i<n;i++)
      scanf("%Lf%Lf",xx+i,xy+i);

    qst(0,n-1,xx,xy);

    r=closestpair(0,n-1);
    r=(sqrt(r))/2;
    printf("%.2Lf\n",r);
  }
  return 0;
}
//---------------------------------------------------------------------------
