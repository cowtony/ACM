//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  int n,ln,i,j,k,l,q,f,sm,p[23];
  char st[23],ch;
  cin>>n>>st;
  while (n || strcmp(st,"END"))
  {
    ln=strlen(st);
    for (i=0;i<ln-1;i++)
      for (j=i+1;j<ln;j++)
        if (st[i]<st[j])
        { ch=st[i];st[i]=st[j];st[j]=ch; }

    for (i=0;i<ln;i++)
      p[i]=0;
    f=0;
    sm=0;
    for (i=0;i<ln;i++)
    {
      p[i]=1;
      sm+=st[i]-'A'+1;
      for (j=0;j<ln;j++)
        if (p[j]==0)
        {
          p[j]=1;
          sm-=(st[j]-'A'+1)*(st[j]-'A'+1);
          for (k=0;k<ln;k++)
            if (p[k]==0)
            {
            p[k]=1;
            sm+=(st[k]-'A'+1)*(st[k]-'A'+1)*(st[k]-'A'+1);
            for (q=0;q<ln;q++)
              if (p[q]==0)
              {
                p[q]=1;
                sm-=(st[q]-'A'+1)*(st[q]-'A'+1)*(st[q]-'A'+1)*(st[q]-'A'+1);
                for (l=0;l<ln;l++)
                  if (p[l]==0)
                  {
                    if (sm+(st[l]-'A'+1)*(st[l]-'A'+1)*(st[l]-'A'+1)*(st[l]-'A'+1)*(st[l]-'A'+1)==n)
                    {
                      f=1;
                      break;
                    }
                  }
                if (f) break;
                p[q]=0;
                sm+=(st[q]-'A'+1)*(st[q]-'A'+1)*(st[q]-'A'+1)*(st[q]-'A'+1);
              }
            if (f) break;
            p[k]=0;
            sm-=(st[k]-'A'+1)*(st[k]-'A'+1)*(st[k]-'A'+1);
            }
          if (f) break;
          p[j]=0;
          sm+=(st[j]-'A'+1)*(st[j]-'A'+1);
        }
      if (f) break;
      p[i]=0;
      sm-=st[i]-'A'+1;
    }


    if (f)
      cout<<st[i]<<st[j]<<st[k]<<st[q]<<st[l]<<endl;
    else
      cout<<"no solution"<<endl;
    cin>>n>>st;
  }
  return 0;
}
//---------------------------------------------------------------------------
 