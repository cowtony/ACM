//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
  struct stt
  { int x,y; } a[100000];
  int n,i,j,s,w;
  cin>>n;
  while (n)
  {
    s=0;
    for (i=1;i<=n;i++)
      cin>>a[i].x>>a[i].y;
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        if (a[i].x>a[j].x)
        { w=a[i].x;a[i].x=a[j].x;a[j].x=w;
          w=a[i].y;a[i].y=a[j].y;a[j].y=w; }
        else
          if (a[i].x==a[j].x && a[i].y>a[j].y)
          { w=a[i].x;a[i].x=a[j].x;a[j].x=w;
            w=a[i].y;a[i].y=a[j].y;a[j].y=w; }
    i=1;
    while (i<n)
    { s+=a[i+1].y-a[i].y;i+=2;}

    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        if (a[i].y>a[j].y)
        { w=a[i].x;a[i].x=a[j].x;a[j].x=w;
          w=a[i].y;a[i].y=a[j].y;a[j].y=w; }
        else
          if (a[i].y==a[j].y && a[i].x>a[j].x)
          { w=a[i].x;a[i].x=a[j].x;a[j].x=w;
            w=a[i].y;a[i].y=a[j].y;a[j].y=w; }
    i=1;
    while (i<n)
    { s+=a[i+1].x-a[i].x; i+=2;}
    cout<<"The length of the fence will be "
        <<s<<" units."<<endl;

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
