//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>

using namespace std;
char mx[82],str[82],stq[82],st1[82],st2[82];
int ln,r[82],p[82];

int stcm()
{
  int j,i,s1=strlen(st1),s2=strlen(st2);
  char stt[82];

  i=0;
  while (st1[i]=='0' && i<s1)
    i++;
  if (i==s1)
    i--;
  stt[0]='\0';
  for (j=i;j<=s1;j++)
  {
    stt[j-i]=st1[j];
    stt[j-i+1]='\0';
  }
  s1-=i;
  strcpy(st1,stt);

  i=0;
  while (st2[i]=='0' && i<s2)
    i++;
  if (i==s2)
    i--;
  stt[0]='\0';
  for (j=i;j<=s2;j++)
  {
    stt[j-i]=st2[j];
    stt[j-i+1]='\0';
  }
  s2-=i;
  strcpy(st2,stt);

  if (s1==s2)
    if (strcmp(st1,st2)>0)
      return 1;
    else
      if (strcmp(st1,st2)==0)
        return 0;
      else
        return -1;
  else
    if (s1>s2)
      return 1;
    else
      return -1;
}
void idol(int sp)
{
  if (sp==0)
  {
    strcpy(st1,stq);
    strcpy(st2,mx);
    if (stcm()>0)
    {
      for (int i=0;i<ln;i++)
        p[i]=r[i];
      strcpy(mx,stq);
    }
  }
  else
  {
    char st[82],sty[82];
    strcpy(sty,stq);
    int i,j;
    st[0]=str[sp-1];
    st[1]='\0';
    for (i=sp;i>0;i--)
    {
      strcpy(st1,st);
      strcpy(st2,sty);
      if (stcm()<0)
      {
        r[i-1]=1;
        strcpy(stq,st);
        idol(i-1);
        strcpy(st1,mx);
        strcpy(st2,"0");
        if ( sp==ln && mx!=""
          && stcm() && str[i-2]!='0')
          break;
        r[i-1]=0;
      }
      else
        break;

      for (j=sp-i+1;j>=0;j--)
        st[j+1]=st[j];
      st[0]=str[i-2];
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
    ln=strlen(str);
    r[0]=1;
    for (i=1;i<ln;i++)
      r[i]=0;

    mx[0]='\0';

    strcpy(stq,str);
    stq[ln]='1';
    stq[ln+1]='\0';

    idol(ln);

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
