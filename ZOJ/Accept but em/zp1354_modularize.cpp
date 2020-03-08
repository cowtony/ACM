//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//#define cin fin
//#include <fstream>
#include <iostream>
using namespace std;

//  ifstream fin("in1354.txt");

const int ln=5;
const int lm=6;
int a[ln+2][lm+2],b[ln+2][lm+2],c[ln+2][lm+2];

void gis()
{
  for (int i=1;i<=ln;i++)
    for (int j=1;j<=lm;j++)
      cin>>a[i][j];
}
void gos()
{
  for (int i=1;i<=ln;i++)
  {
    for (int j=1;j<lm;j++)
      cout<<b[i][j]<<' ';
    cout<<b[i][lm]<<endl;
  }
}
int aloff()
{
  int t=0;
  for (int i=1;i<=ln;i++)
    if (c[i][lm])
    { t=1; break;}
  return 1-t;
}
void trunsc(int nn)
{
  for (int i=1;i<=ln;i++)
    if (b[i][nn])
    {
      c[i][nn]  =1-c[i][nn]  ;
      c[i][nn-1]=1-c[i][nn-1];
      c[i][nn+1]=1-c[i][nn+1];
      c[i+1][nn]=1-c[i+1][nn];
      c[i-1][nn]=1-c[i-1][nn];
    }
}
void calsb(int nn)
{
  for (int i=1;i<=ln;i++)
    b[i][nn]=c[i][nn-1];
}
void copyac()
{
  for (int i=1;i<=ln;i++)
    for (int j=1;j<=lm;j++)
      c[i][j]=a[i][j];
}
void seki()
{
  for (b[1][1]=0;b[1][1]<2;b[1][1]++)
    for (b[2][1]=0;b[2][1]<2;b[2][1]++)
      for (b[3][1]=0;b[3][1]<2;b[3][1]++)
        for (b[4][1]=0;b[4][1]<2;b[4][1]++)
          for (b[5][1]=0;b[5][1]<2;b[5][1]++)
          {
            copyac();
            trunsc(1);
            for (int i=2;i<=lm;i++)
            {
              calsb(i);
              trunsc(i);
            }
            if (aloff())
              return;
          }
}
int main(int argc, char* argv[])
{
  int N;
  cin>>N;
  for (int I=1;I<=N;I++)
  {
    gis();

    seki();

    cout<<"PUZZLE #"<<I<<endl;
    gos();
  }
  return 0;
}
//---------------------------------------------------------------------------
