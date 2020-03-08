//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <iomanip.h>
#include <math.h>

int pl[5],pf[5];
double rex[110],rey[110],dx[110],dy[110];
double sum;
int n,r[110];

int dbcmp(double d)
{
  if (fabs(d)<1e-6)
    return 0;
  if (d>0)
    return 1;
  else
    return -1;
}
double distance(double ax,double ay, double bx,double by)
{
  return sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
}
int intriangle (double ax, double ay, double bx, double by, double cx,double cy, double fx,double fy,int i)
{
  double ux,tx,ly,ry;
  ux=ax>bx?ax:bx;
  tx=ax<bx?ax:bx;

  ry=ay>by?ay:by;
  ly=ay<by?ay:by;

  if (fx>=ux || fx<=tx || fy>=ry || fy<=ly)
    return 0;

  double gx,gy;

    gx=fx*(cy-fy)/(cx-fx)-bx*(ay-by)/(ax-bx)+by-fy;
    gx/=(cy-fy)/(cx-fx)-(ay-by)/(ax-bx);

    gy=(gx-fx)*(cy-fy)/(cx-fx)+fy;


  if ((cx-fx)*(gx-fx)>=0)
    return 0;

  if (cy==by)
  {
    gx=fx*(ay-fy)/(ax-fx)-bx*(cy-by)/(cx-bx)+by-fy;
    gx/=(ay-fy)/(ax-fx)-(cy-by)/(cx-bx);

    gy=(gx-fx)*(ay-fy)/(ax-fx)+fy;
  }
  else
  {
    gy=fy*(ax-fx)/(ay-fy)-by*(cx-bx)/(cy-by)+bx-fx;
    gy/=(ax-fx)/(ay-fy)-(cx-bx)/(cy-by);

    gx=(gy-fy)*(ax-fx)/(ay-fy)+fx;
  }

  rex[i]=gx;
  rey[i]=gy;

  return 1;
}
void cal(double ax,double ay, double bx,double by, double cx,double cy)
{
  int i;
  for (i=1;i<=n;i++)
    if (r[i]==1)
      r[i]=intriangle(ax,ay,bx,by,cx,cy,dx[i],dy[i],i);

  double ds,mx=0;
  int k=0;

  for (i=1;i<=n;i++)
    if (r[i]==1)
    {
      ds=distance(rex[i],rey[i],bx,by);
      if (dbcmp(ds-mx)>0)
      {
        mx=ds;
        k=i;
      }
      else
        if (dbcmp(ds-mx)==0)
          if (distance(dx[k],dy[k],ax,ay)<distance(dx[i],dy[i],ax,ay))
            k=i;
    }

  if (k)
  {
    sum+=distance(ax,ay,dx[k],dy[k]);
    //cout<<ax<<' '<<ay<<' '<<dx[k]<<' '<<dy[k]<<' ';
    r[k]=-1;
    cal(dx[k],dy[k],bx,by,rex[k],rey[k]);
  }
  else
  {
    sum+=distance(ax,ay,bx,by);
    //cout<<ax<<' '<<ay<<' '<<bx<<' '<<by<<' ';
  }
  //cout<<sum<<endl;
}

void justmain()
{
  sum=dx[pf[1]]-dx[pl[2]]+dy[pl[3]]-dy[pf[2]];
  sum+=dx[pl[4]]-dx[pf[3]]+dy[pf[4]]-dy[pl[1]];

  for (int j=1;j<=n;j++)
    if (r[j]>=0)
      r[j]=1;
  cal(dx[pl[1]],dy[pl[1]],dx[pf[1]],dy[pf[1]],dx[pl[1]],dy[pf[1]]);

  for (int j=1;j<=n;j++)
    if (r[j]>=0)
      r[j]=1;
  cal(dx[pl[2]],dy[pl[2]],dx[pf[2]],dy[pf[2]],dx[pf[2]],dy[pl[2]]);

  for (int j=1;j<=n;j++)
    if (r[j]>=0)
      r[j]=1;
  cal(dx[pl[3]],dy[pl[3]],dx[pf[3]],dy[pf[3]],dx[pl[3]],dy[pf[3]]);

  for (int j=1;j<=n;j++)
    if (r[j]>=0)
      r[j]=1;
  cal(dx[pl[4]],dy[pl[4]],dx[pf[4]],dy[pf[4]],dx[pf[4]],dy[pl[4]]);


  cout<<sum<<endl;
}
void readit()
{
  for (int i=1;i<=n;i++)
  {
    cin>>dx[i]>>dy[i];
    r[i]=0;
  }
}

void pretreat()
{
  double mx1,mx2,my1,my2;
  int r0,r1,r2,i;

//Max X
  mx1=dx[1];r0=1;
  for (i=2;i<=n;i++)
    if (dx[i]>mx1)
    {
      mx1=dx[i];
      r0=i;
    }
  my1=dy[r0];
  my2=my1;
  r1=r0;
  r2=r0;
  r[r0]=-1;
  for (i=r0+1;i<=n;i++)
    if (dx[i]==mx1)
    {
      r[i]=-1;
      if (dy[i]>my1)
      {
        my1=dy[i];
        r1=i;
      }
      if (dy[i]<my2)
      {
        my2=dy[i];
        r2=i;
      }
    }
  pl[1]=r2;
  pf[4]=r1;

//Min X
  mx1=dx[1];r0=1;
  for (i=2;i<=n;i++)
    if (dx[i]<mx1)
    {
      mx1=dx[i];
      r0=i;
    }
  my1=dy[r0];
  my2=my1;
  r1=r0;
  r2=r0;
  r[r0]=-1;
  for (i=r0+1;i<=n;i++)
    if (dx[i]==mx1)
    {
      r[i]=-1;
      if (dy[i]>my1)
      {
        my1=dy[i];
        r1=i;
      }
      if (dy[i]<my2)
      {
        my2=dy[i];
        r2=i;
      }
    }
  pf[2]=r2;
  pl[3]=r1;

//Max Y
  my1=dy[1];r0=1;
  for (i=2;i<=n;i++)
    if (dy[i]>my1)
    {
      my1=dy[i];
      r0=i;
    }
  mx1=dx[r0];
  mx2=mx1;
  r1=r0;
  r2=r0;
  r[r0]=-1;
  for (i=r0+1;i<=n;i++)
    if (dy[i]==my1)
    {
      r[i]=-1;
      if (dx[i]>mx1)
      {
        mx1=dx[i];
        r1=i;
      }
      if (dx[i]<mx2)
      {
        mx2=dx[i];
        r2=i;
      }
    }
  pf[3]=r2;
  pl[4]=r1;

//Min Y
  my1=dy[1];r0=1;
  for (i=2;i<=n;i++)
    if (dy[i]<my1)
    {
      my1=dy[i];
      r0=i;
    }
  mx1=dx[r0];
  mx2=mx1;
  r1=r0;
  r2=r0;
  r[r0]=-1;
  for (i=r0+1;i<=n;i++)
    if (dy[i]==my1)
    {
      r[i]=-1;
      if (dx[i]>mx1)
      {
        mx1=dx[i];
        r1=i;
      }
      if (dx[i]<mx2)
      {
        mx2=dx[i];
        r2=i;
      }
    }
  pl[2]=r2;
  pf[1]=r1;
}

int main(int argc, char* argv[])
{
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  cin>>n;
  while (n)
  {
    readit();
    pretreat();
    justmain();

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
