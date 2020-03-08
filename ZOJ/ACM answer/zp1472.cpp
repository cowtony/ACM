//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int absm(long long x)
{
  if (x>=0)
    return x;
  return -x;
}

int minm(long long x,long long y)
{
  if (x>y)
    return y;
  return x;
}

int maxm(long long x,long long y)
{
  if (x<y)
    return y;
  return x;
}

int betw(long long x1,long long y1d,long long y1u,
         long long x2,long long y2d,long long y2u)
{
  if (x1!=x2)
    return 0;
  if (y1d<=y2d && y2d<=y1u)
    return 1;
  if (y1d<=y2u && y2u<=y1u)
    return 1;
  if (y2d<=y1d && y1d<=y2u)
    return 1;
  if (y2d<=y1u && y1u<=y2u)
    return 1;
  return 0;
}
int det(long long x1,long long y1,
        long long x2,long long y2)
{
  if (x1*y2-x2*y1>0)
    return 1;
  if (x1*y2-x2*y1<0)
    return -1;
  return 0;
}
int cross(long long x1,long long y1d,long long y1u,
          long long x2l,long long x2r,long long y2)
{
  if (det(0,y1u-y1d,x2l-x1,y1u-y1d)*det(0,y1u-y1d,x2r-x1,y1u-y1d)<0
   && det(x2r-x2l,0,x2r-x2l,y1d-y2)*det(x2r-x2l,0,x2r-x2l,y1u-y2)<0)
    return 1;
  return 0;
}
int main(int argc, char* argv[])
{
  long long N,I,d,l1,l2,l3,l4,r1,r2,x1,x2,y1,y2,
            x1u,x1d,x2u,x2d,y1u,y1d,y2u,y2d,x,y,p,q;
  char st1[10],st2[10];
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    scanf("%s",st1);
    if (st1[0]=='c')
      scanf("%Ld%Ld%Ld",&r1,&x1,&y1);
    else
      scanf("%Ld%Ld%Ld%Ld",&x1u,&y1u,&x1d,&y1d);
    scanf("%s",st2);
    if (st2[0]=='c')
      scanf("%Ld%Ld%Ld",&r2,&x2,&y2);
    else
      scanf("%Ld%Ld%Ld%Ld",&x2u,&y2u,&x2d,&y2d);

    if (st1[0]=='c' && st2[0]=='c')
    {
      //two circles;
      d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
      if (d<=(r1+r2)*(r1+r2) && d>=(r1-r2)*(r1-r2))
        printf("yes\n");
      else
        printf("no\n");

    }
    else
    if (st1[0]=='r' && st2[0]=='r')
    {
      //two rectecnic
      if (betw(y1u,x1u,x1d,y2u,x2u,x2d)
       || betw(y1u,x1u,x1d,y2d,x2u,x2d)
       || betw(y1d,x1u,x1d,y2u,x2u,x2d)
       || betw(y1d,x1u,x1d,y2d,x2u,x2d)
       || betw(x1u,y1d,y1u,x2u,y2d,y2u)
       || betw(x1u,y1d,y1u,x2d,y2d,y2u)
       || betw(x1d,y1d,y1u,x2u,y2d,y2u)
       || betw(x1d,y1d,y1u,x2d,y2d,y2u)
       || cross(y1u,x1u,x1d,y2d,y2u,x2u)
       || cross(y1u,x1u,x1d,y2d,y2u,x2d)
       || cross(y1d,x1u,x1d,y2d,y2u,x2u)
       || cross(y1d,x1u,x1d,y2d,y2u,x2d)
       || cross(x1u,y1d,y1u,x2u,x2d,y2u)
       || cross(x1u,y1d,y1u,x2u,x2d,y2d)
       || cross(x1d,y1d,y1u,x2u,x2d,y2u)
       || cross(x1d,y1d,y1u,x2u,x2d,y2d))
        printf("yes\n");
      else
        printf("no\n");
    }
    else
    {
      if (st2[0]=='c')
      {
        r1=r2;    x1=x2;    y1=y2;
        x2u=x1u;  y2u=y1u;  x2d=x1d;  y2d=y1d;
      }
      if (x1>=x2u && x1<=x2d && y1<=y2u && y1>=y2d)
      {
        l1=(x2u-x1)*(x2u-x1)+(y2u-y1)*(y2u-y1);
        l2=(x2u-x1)*(x2u-x1)+(y2d-y1)*(y2d-y1);
        l3=(x2d-x1)*(x2d-x1)+(y2u-y1)*(y2u-y1);
        l4=(x2d-x1)*(x2d-x1)+(y2d-y1)*(y2d-y1);

        l1=maxm(l1,maxm(l2,maxm(l3,l4)));

        if (minm(x1-x2u,minm(x2d-x1,minm(y2u-y1,y1-y2d)))<=r1
          && r1*r1<=l1)
          printf("yes\n");
        else
          printf("no\n");
      }
      else
      if (x1>=x2u && x1<=x2d)
      {
        l3=maxm(absm(y2u-y1),absm(y2d-y1));
        l4=maxm(x2d-x1,x1-x2u);

        l1=l4*l4+l3*l3;

        if (minm(absm(y2u-y1),absm(y2d-y1))<=r1
          && r1*r1<=l1)
          printf("yes\n");
        else
          printf("no\n");
      }
      else
      if (y1<=y2u && y1>=y2d)
      {
        l3=maxm(absm(x2u-x1),absm(x2d-x1));
        l4=maxm(y2u-y1,y1-y2d);

        l1=l4*l4+l3*l3;

        if (minm(absm(x2u-x1),absm(x2d-x1))<=r1
          && r1*r1<=l1)
          printf("yes\n");
        else
          printf("no\n");
      }
      else
      {
        x=minm(absm(x2u-x1),absm(x2d-x1));
        y=minm(absm(y2u-y1),absm(y2d-y1));

        p=maxm(absm(x2u-x1),absm(x2d-x1));
        q=maxm(absm(y2u-y1),absm(y2d-y1));

        if (x*x+y*y<=r1*r1 && p*p+q*q>=r1*r1)
          printf("yes\n");
        else
          printf("no\n");
      }
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
