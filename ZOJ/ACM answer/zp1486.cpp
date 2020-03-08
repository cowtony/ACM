//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;

string mlpt(string st1, int s)
{
	string st;
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
			if (i==len1) len1++;
		}
	st="";
	for (i=0;i<len1;i++)
		st+=a[len1-i]+'0';
	return st;
}
int main(int argc, char* argv[])
{
  int n,m,x,i;
  string s;
  cin>>n>>m;
  while (n+m)
  {
    s="1";
    s=mlpt(s,m);
    for (i=1;i<n;i++)
      cin>>x>>x;
    for (i=1;i<n;i++)
      s=mlpt(s,m-1);
    cout<<s<<endl;
    cin>>n>>m;
  }
  return 0;
}
//---------------------------------------------------------------------------
 