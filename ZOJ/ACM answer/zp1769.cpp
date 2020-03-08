#include <iostream.h>
#include <math.h>

int dbc(double d1)
{
  if (fabs(d1)<1e-4)
    return 0;
  else
    if (d1>0)
      return 1;
    else
      return -1;
}
int main(int argc, char* argv[])
{
  double x1,y1,x2,y2,x3,y3,t,d[5];
  int i,j;
  cin>>x1;
  while (x1!=-1)
  {
    cin>>y1>>x2>>y2>>x3>>y3;
    d[0]=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    d[1]=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    d[2]=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    for (i=0;i<2;i++)
      for (j=i+1;j<3;j++)
        if (d[i]>d[j])
        { t=d[i];d[i]=d[j];d[j]=t; }

    if (dbc(d[2]-d[1]-d[0])==0
       || dbc(d[0])==0 || dbc(d[1])==0 || dbc(d[2])==0)
      cout<<"Not a Triangle"<<endl;
    else
    {
      if (!dbc(d[0]-d[1]) || !dbc(d[1]-d[2]) || !dbc(d[0]-d[2]))
        if (!dbc(d[0]-d[1]) && !dbc(d[0]-d[2]))
          cout<<"Equilateral ";
        else
          cout<<"Isosceles ";
      else
        cout<<"Scalene ";
      if (dbc((d[1]*d[1]+d[0]*d[0]-d[2]*d[2])/(2*d[1]*d[0]))==0)
        cout<<"Right";
      else
        if ((d[1]*d[1]+d[0]*d[0]-d[2]*d[2])/(2*d[1]*d[0])>0)
          cout<<"Acute";
        else
          cout<<"Obtuse";
      cout<<endl;
    }
    cin>>x1;
  }
  cout<<"End of Output"<<endl;
  return 0;
}
//---------------------------------------------------------------------------
 