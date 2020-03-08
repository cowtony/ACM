//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;
string st;
int l;
string muti(string st1, int s)
{
	string str;
	int a[255]={0};
	int len1,i;
	len1 = st1.length();
	for( i = len1 - 1; i >= 0; i-- )
		a[len1-i]= st1[i] - '0';
	for (i=1;i<=len1;i++)
		a[i]*=s;
	for (i=1;i<=len1;i++)
		if (a[i]>9)
		{
			a[i+1]+=a[i]/ 10;
			a[i]%=10;
			if (i==len1 ) len1++;
		}
	str="";
	for (i=0;i<len1;i++)
		str+=a[len1-i]+'0';
	return str;
}
int oki(int n)
{
  int p[70],i,j;
  string str=muti(st,n);
  if (str.length()>l)
    return 1;
  else
  {
    for (i=1;i<=l;i++)
      p[i]=1;
    for (i=1;i<=l;i++)
    {
      for (j=1;j<=l;j++)
        if (p[j] && st[i-1]==str[j-1])
        { p[j]=0; break; }
      if (j>l) break;
    }
    if (i>l)
      return 0;
    else
      return 1;
  }
}
int main(int argc, char* argv[])
{
  int i;
  while (cin>>st)
  {
    l=st.length();
    for (i=2;i<=l;i++)
      if (oki(i)) break;
    cout<<st<<" is ";
    if (i<=l)
      cout<<"not ";
    cout<<"cyclic"<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 