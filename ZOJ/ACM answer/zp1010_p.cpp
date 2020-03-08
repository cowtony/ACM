#define cin fin
#include <fstream.h>
#include <iostream.h>
#include <stdio.h>
#include <math.h>

#define eps 1e-8

double x[1001],y[1001];

double area(int n, double x[], double y[])
{
  int i;
  double ans = 0;
  for(i=1; i<=n; i++)
    ans += x[i]*y[i-1]-y[i]*x[i-1];
  return fabs(ans/2);
}
double cross(int a,int b,int c)
{
  return (x[b]-x[a])*(y[c]-y[a])-(y[b]-y[a])*(x[c]-x[a]);
}
double dot(int a,int b,int c)
{
  return (x[b]-x[a])*(x[c]-x[a])+(y[b]-y[a])*(y[c]-y[a]);
}
int dblcmp(double d)
{
  if(fabs(d)<eps)
    return 0;
  return (d>0)?1:-1;
}
int between(int a, int b, int c) //a is between b->c
{
  return dblcmp(dot(a,b,c));
}
int intersect(int s, int t)
{
  int d1,d2,d3,d4;
  d1 = dblcmp(cross(s,s+1,t));
  d2 = dblcmp(cross(s,s+1,t+1));
  d3 = dblcmp(cross(t,t+1,s));
  d4 = dblcmp(cross(t,t+1,s+1));
  if(d1*d2<0 && d3*d4<0)
    return 1;
  if (d1==0 && between(t,s,s+1)<=0 ||
      d2==0 && between(t+1,s,s+1)<=0 ||
      d3==0 && between(s,t,t+1)<=0 ||
      d4==0 && between(s+1,t,t+1)<=0)
    return 2;
  return 0;
}
int main()
{
  fstream fin("d:\in1010.txt");
  int n,i,j,ncase=0;
  while(cin>>n && n)
  {
    for(i=1; i<=n; i++)
      cin>>x[i]>>y[i];
    x[0]=x[n]; y[0]=y[n];
    if (ncase)
      cout<<endl;
    cout<<"Figure "<<++ncase<<": ";
    int flag=1;
    if(n<3 || n==3 && dblcmp(cross(1,2,3))==0)
    {
      flag = 0;
      goto output;
    }
    for(i=n-2; i>1; i--)
      if(intersect(0,i))
      {
        flag = 0;
        goto output;
      }
    for(i=n-3; i>0; i--)
      for(j=i+2; j<n; j++)
        if(intersect(i,j))
          {
            flag = 0;
            goto output;
          }
output:
    {
      if (flag)
        printf("%.2lf\n", area(n,x,y));
      else
        cout<<"Impossible\n";
    }
  }
  return 0;
}
//-------------------------------------------------------
