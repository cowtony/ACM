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
  char str[90],mxl[90];
  int ln,i,j,k,mln,p,q,b,c,r[90]={0},t[90]={0};

  cin>>str;
  while (strcmp(str,"0"))
  {
    ln=strlen(str);

    for (i=0;i<=ln;i++)
      mxl[i]=str[i];

    for (j=1;j<=ln+1;j++)
      t[j]=0;

    mln=ln;
    c=0;
    while (str[c]=='0')   c++;
    if (c==ln)
    {
      cout<<str<<endl;
      cin>>str;
      continue;
    }

    for (i=ln/2;i>0;i--)
    {
      for (j=1;j<=ln+1;j++)
        r[j]=0;
      j=i;
      b=c+i;
      while (b+j<=ln)
      {
        p=b-j;
        q=b;
        r[b]=1;
        while (str[p]=='0')   p++;
        while (str[q]=='0')
        {   q++; b++;  }
        if (p==q || q==ln)
        {   break;  }
        while (str[q]==str[p] && q-b<j-1)
        {   p++;  q++;  }
        if (str[p]>=str[q])
          j++;
        b+=j;
      }
      if (b+j<=ln)
        continue;
      if (b>ln)
        continue;
      b-=j;
      j=ln-b;
      if (j>mln)
        continue;
      if (j==mln)
      {
        p=0;
        q=b;
        while (mxl[p]=='0')   p++;
        while (str[q]=='0')   q++;
        while (str[q]==mxl[p] && q<ln)
        {   p++;  q++;  }
        if (q==ln)
          continue;
        if (str[q]>=mxl[q])
          continue;
      }
      mln=j;

      q=b;
      while (str[q]=='0')   q++;
      if (q==ln)  continue;

      for (j=1;j<ln;j++)
        t[j]=r[j];
      for (j=b;j<=ln;j++)
        mxl[j-b]=str[j];
    }
    cout<<str[0];
    for (i=1;i<ln;i++)
    {
      if (t[i])
        cout<<',';
      cout<<str[i];
    }
    cout<<endl;

    cin>>str;
  }
  return 0;
}
//---------------------------------------------------------------------------
