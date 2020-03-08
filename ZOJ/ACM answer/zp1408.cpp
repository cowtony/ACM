//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int N,I,i,ln,r[70];
  char st[70];
  long long tg;
  cin>>N;
  for (I=0;I<N;I++)
  {

    cin>>ln>>st>>tg;
    for (i=ln-1;i>=0;i--)
    {
      if (tg%2==0)
        r[i]=0;
      else
      {
        r[i]=1;
        if (st[i]=='n')
          tg+=1;
        else
          tg-=1;
      }
      tg/=2;
      //cout<<tg<<endl;
    }

    if (tg)
      cout<<"Impossible";
    else
      for (i=0;i<ln;i++)
        cout<<r[i];
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 