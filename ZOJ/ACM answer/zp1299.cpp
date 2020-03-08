//program p1299(input,output);
#define cin fin
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

  int n;
  double r,s;
  int ax[10000],ay[10000];
  const double pi=3.1415927;

double dbc(double d)
{
  if (fabs(d)<1e-7)
    return 0;
  else
    return d;
}
double arct(double d)
{
  if (dbc(d)>0)
    return atan(d);
  else
    if (dbc(d)==0)
      return pi;
    else
      return atan(d)+pi;
}

double biang(int i,int w)
{
  if (ax[i]==ax[w])
    return pi/2;
  else
    if (ay[i]==ay[w])
      if (ax[i]>ax[w])
        return pi;
      else
        return 0;
    else
      return arct(double (ay[i]-ay[w])/(ax[i]-ax[w]));
}
void simu(int w,double l,double b)
{
  double bmax,bmin,bi,recr,ri;
  int i,reci,u;

  if (dbc(-ay[w]-l)<0)
  {
    bmax=arct(-ay[w]/sqrt(l*l-ay[w]*ay[w]))+pi;
    bmin=bmax;
    recr=0;
    for (i=1;i<=n;i++)
      if (i!=w)
      {
        bi=biang(i,w);
        cout<<bi<<endl;
        ri=sqrt((ay[i]-ay[w])*(ay[i]-ay[w])+(ax[i]-ax[w])*(ax[i]-ax[w]));
        if ((dbc(bi-b)>0 && dbc(bi-bmin)<0)
           || (dbc(bi-bmin)==0 && dbc(ri-recr)>0))
           {
             reci=i;
             recr=ri;
             bmin=bi;
           }
      }

      s+=l*(bmin-b);
      cout<<s<<endl;
      if (dbc(bmin-bmax)!=0)
        simu(reci,l-recr,bmin);
  }
  else
  {
    u=0;
    bmin=2*pi+b;
    recr=0;
    for (i=1;i<=n;i++)
      if (i!=w)
      {
        ri=sqrt((ay[i]-ay[w])*(ay[i]-ay[w])+(ax[i]-ax[w])*(ax[i]-ax[w]));
        if (dbc(ri-l)<=0)
        {
          u=1;
          bi=biang(i,w);
          if (dbc(bi-bmin)<0 || (dbc(bi-bmin)==0 && dbc(ri-recr)>0))
          {
            reci=i;
            recr=ri;
            bmin=bi;
          }
        }
      }
    if (u==0)
      s=l*pi;
    else
      simu(reci,l-recr,bmin);
  }
}
int main ()
{
  ifstream fin("in1299.txt");
  int ms,j;

  ms=0;
  cin>>n>>r;
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  while (dbc(r))
  {
    for (j=1;j<=n;j++)
      cin>>ax[j]>>ay[j];

    ax[0]=0;ay[0]=0;
    s=0;

    if (n)
      simu(0,r,0);
    else
      s=r*pi;

    s*=2;
    cout<<"Pendulum #"<<++ms<<endl;
    cout<<"Length of periodic orbit = "<<s<<endl<<endl;

    cin>>n>>r;
  }
  return 0;
}
