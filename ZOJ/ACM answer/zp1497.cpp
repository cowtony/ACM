//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

int main(int argc, char* argv[])
{
  int n,k,i,c,v,sm,tm,r[33],p[33];
  char ch;
  cin>>n;
  while (n)
  {
    cin>>k;
    for (i=1;i<=n;i++)
    {
      cin>>ch;
      if (ch=='L')
        p[i]=0;
      else
        p[i]=1;
      r[i]=0;
    }
    //r[1]=1;
    c=1;

    r[k]=1;
    tm=1;

    sm=1;
    v=2;

    while (tm<n)
    {
      if (p[k])
      {
        v=c+1;
        if (v>n) v=1;
      }
      else
      {
        v=c-1;
        if (v==0) v=n;
      }

      p[k]=1-p[k];

      if (v==k)
        if (k==1)
          if (c==2)
            v=n;
          else
            v=2;
        else
        if (k==n)
          if (c==1)
            v=n-1;
          else
            v=1;
        else
          v=k-(c-k);

      if (r[v]==0)
      {
        tm++;
        r[v]=1;
      }

      c=k;
      k=v;

      sm++;
    }
    cout<<"Classmate "<<v
        <<" got the ball last after "<<sm
        <<" toss";
    if (sm==1)
      cout<<'.';
    else
      cout<<"es.";
    cout<<endl;
    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
