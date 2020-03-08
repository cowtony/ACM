//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>

using namespace std;
string mx,str;
int ln,r[82],p[82];

int stcm(string st1,string st2)
{
  int j,i,s1=st1.length(),s2=st2.length();
  string stt;

  i=0;
  while (st1[i]=='0' && i<s1)
    i++;
  if (i==s1)
    i--;
  stt="";
  for (j=i;j<=s1;j++)
    stt+=st1[j];
  s1-=i;
  st1=stt;

  i=0;
  while (st2[i]=='0' && i<s2)
    i++;
  if (i==s2)
    i--;
  stt="";
  for (j=i;j<=s2;j++)
    stt+=st2[j];
  s2-=i;
  st2=stt;

  //cout<<st1<<' '<<st2<<endl;

  if (s1==s2)
    if (st1>st2)
      return 1;
    else
      if (st1==st2)
        return 0;
      else
        return -1;
  else
    if (s1>s2)
      return 1;
    else
      return -1;
}
void idol(int sp, string stq)
{
  if (sp==0)
  {
    if (stcm(stq,mx)>0)
    {
      for (int i=0;i<ln;i++)
        p[i]=r[i];
      mx=stq;
    }
  }
  else
  {
    string st1;
    int i;
    st1="";
    st1=str[sp-1];
    for (i=sp;i>0;i--)
    {
      if (stcm(st1,stq)<0)
      {
        r[i-1]=1;
        idol(i-1,st1);
        if ( sp==ln && mx!=""
          && stcm(mx,"0") && str[i-2]!='0')
          break;
        r[i-1]=0;
      }
      else
        break;
      //if (i>1 && str[i-2]!='0')
        st1=str[i-2]+st1;
    }
  }
}
int main(int argc, char* argv[])
{
  int i;
  string st1,st2;

/*
  while (cin>>st1>>st2)
    if (stcm(st1,st2)>0)
      cout<<'>'<<endl;
    else
      if (stcm(st1,st2)<0)
        cout<<'<'<<endl;
      else
        cout<<'='<<endl;
*/
  cin>>str;
  while (str!="0")
  {
    ln=str.length();
    r[0]=1;
    for (i=1;i<ln;i++)
      r[i]=0;

    mx="";

    idol(ln,str+"1");

    cout<<str[0];
    for (i=1;i<ln;i++)
    {
      if (p[i])
        cout<<',';
      cout<<str[i];
    }
    cout<<endl;

    cin>>str;
  }
  return 0;
}
//---------------------------------------------------------------------------
