//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#define cin fin
#include <fstream.h>
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
float ax[1100],ay[1100];
inline int cmp(float d)
{
  if(fabs(d)<1e-8)
    return 0;
  return (d>0)?1:-1;
}
inline int fc(int i,int j)
{
  float x1,x2,x3,x4,y1,y2,y3,y4;
  int k1,k2;
  x1=ax[i+1]-ax[i];y1=ay[i+1]-ay[i];
  x2=ax[j]-ax[i];y2=ay[j]-ay[i];
  x3=ax[j+1]-ax[i];y3=ay[j+1]-ay[i];
  k1=cmp(x1*y2-x2*y1);
  k2=cmp(x1*y3-x3*y1);
  if (k1*k2>0)
    return 0;
  else
    if (k1*k2<0) return 1;
    else
    {
      if (cmp(ax[i]-ax[i+1])==1)
        { x1=ax[i]; x2=ax[i+1]; }
      else
        { x2=ax[i]; x1=ax[i+1]; }
      if (cmp(ax[j]-ax[j+1])==1)
        { x3=ax[j]; x4=ax[j+1]; }
      else
        { x4=ax[j]; x3=ax[j+1]; }

      if (cmp(ay[i]-ay[i+1])==1)
        { y1=ay[i]; y2=ay[i+1]; }
      else
        { y2=ay[i]; y1=ay[i+1]; }
      if (cmp(ay[j]-ay[j+1])==1)
        { y3=ay[j]; y4=ay[j+1]; }
      else
        { y4=ay[j]; y3=ay[j+1]; }

      if (cmp(x1-x2)==0)
        { x1=y1; x2=y2; x3=y3; x4=y4; }
      if (cmp(y1-y2)==0)
        { y1=x1; y2=x2; y3=x3; y4=x4; }

      if (k1==0 && k2!=0)
        if ((cmp(ax[j]-x2)>=0 && cmp(ax[j]-x1)<=0) ||
            (cmp(ay[j]-y2)>=0 && cmp(ay[j]-y1)<=0))
          return 1;
        else
          return 0;
      else
        if (k1!=0 && k2==0)
          if ((cmp(ax[j+1]-x2)>=0 &&
               cmp(ax[j+1]-x1)<=0) ||
              (cmp(ay[j+1]-y2)>=0 &&
               cmp(ay[j+1]-y1)<=0))
            return 1;
          else
            return 0;
        else
          if (((cmp(x3-x2)>=0 && cmp(x3-x1)<=0) ||
               (cmp(x4-x2)>=0 && cmp(x4-x1)<=0))||
              ((cmp(y3-y2)>=0 && cmp(y3-y1)<=0) ||
               (cmp(y4-y2)>=0 && cmp(y4-y1)<=0)))
            return 1;
          else
            return 0;
    }
}
int main(int argc, char* argv[])
{
  ifstream fin("d:\in1010.txt");
  float s;
  int n,nt,i,j,t;
  cin>>n;
  nt=1;
  while (n)
  {
    if (nt-1) cout<<endl;
    for (i=1;i<=n;i++)
      cin>>ax[i]>>ay[i];
    ax[0]=ax[n];ay[0]=ay[n];
    t=0;
    if (n<3) t=1;
    if (!t)
      for (j=2;j<n-1;j++)
        if (fc(0,j) && fc(j,0))
          { t=1; break; }
    if (!t)
      for (i=1;i<n-1;i++)
      {
        for (j=i+2;j<n;j++)
          if (fc(i,j) && fc(j,i)) { t=1; break; }
        if (t) break;
      }
    cout<<"Figure "<<nt<<": ";
    if (t) cout<<"Impossible"<<endl;
    else
    {
      s=0;
      for (i=1;i<=n;i++)
        //s+=ax[i]-ax[i-1])*(ay[i]+ay[i-1];
        s+=ax[i]*ay[i-1]-ay[i]*ax[i-1];
      s=fabs(s/2);
      if (cmp(s)==0)
        cout<<"Impossible"<<endl;
      else
        cout<<setiosflags(ios::fixed)<<setprecision(2)
          <<s<<endl;
    }
    cin>>n;nt++;
  }
  return 0;
}
//---------------------------------------------------------------------------
