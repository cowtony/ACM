#include<stdio.h>
#include<iostream.h>
#include<math.h>

int f[100010][3];
int gcd(int i,int j)
{
  if(j==0) return i;
  else return gcd(j,i%j);
}
void run()
{
  int i,j,u,v,x,y;
  int count;
  count=0;
  for(i=3; count<=100000;i++)
  {
    if(i%2==1)
    {
      j=(int )sqrt(i);
      for( ;j>=1;j--)
      if(i %j==0)
      {
        u=(i/j +j )/2;
        v=u-j;
        if((u-v) % 2==0) continue;
        if(gcd(u,v )!=1) continue;
        x=i;
        y=2*u*v;
        if(y>x && gcd(y,x)==1)
        {
          count++;
          f[count][0]=i;
          f[count][1]=y;
          f[count][2]=u*u+v*v;
        }
      }
    }
    else
    {
      int t=i/2;
      if(t%2) continue;
      j=(int) sqrt(t);
      for(;j>=1;j--)
      if(t%j==0)
      {
        u=t/j;
        v=j;
        if((u-v ) %2==0) continue;
        if(gcd(u,v)!=1 ) continue;
        x=2*u*v;
        y=u*u-v*v;
        if(gcd(x,y)==1 && x<y )
        {
          count++;
          f[count][0]=x;
          f[count][1]=y;
          f[count][2]=u*u+v*v;
        }
      }
    }
  }
}

int main()
{
// freopen("1574.out","w",stdout);

  int n;
  run();
  while(cin>>n)
  {
    cout<<f[n][0]<<' '<<f[n][1]<<' '<<f[n][2]<<endl;
  }

// fclose(stdout);
  return 0;
}
