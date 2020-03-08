//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
  int a,b,c,d,e,f,t,s,w;
  cin>>a>>b>>c>>d>>e>>f;
  while (a+b+c+d+e+f)
  {
    if (a*d==e) {w=d;d=c;c=w;}
    else if (a*d==f) {w=a;a=b;b=w;}
    else if (a*c==f) {w=f;f=e;e=w;}
    else if (b*d==e) {w=e;e=f;f=w;}
    else if (b*c==e) {w=a;a=b;b=w;}
    else if (b*c==f) {w=c;c=d;d=w;}

    t=0;s=0;
    if (c*a<=e && d*b<=f) t=1;
    else if (c*a<=f && d*b<=e) {t=1;w=e;e=f;f=w;}
    else if (c*b<=e && d*a<=f) {t=1;w=a;a=b;b=w;}
    else if (c*b<=f && d*a<=e) {t=1;w=a;a=b;b=w;w=e;e=f;f=w;}
    if (t)
      {
        s=a*b-1;
        if (c*a!=e) s++;
        if (b*d!=f) s++;
        cout<<"The minimum number of cuts is "<<s<<"."<<endl;
      }
    else
      cout<<"The paper is too small."<<endl;
    cin>>a>>b>>c>>d>>e>>f;
  }
  return 0;
}
//---------------------------------------------------------------------------
