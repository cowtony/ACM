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
			if (i==len1 ) len1++;
		}
	st="";
	for (i=0;i<len1;i++)
		st+=a[len1-i]+'0';
	return st;
}
string addi(string st1, string st2)
{
	string st;
	int a[255]={0},b[255]={0};
	int len1,len2,len,i;
	len1=st1.length();
	len2=st2.length();
	for(i=len1-1;i>=0;i--)
		a[len1-i]=st1[i]-'0';
	for(i=len2-1;i>=0;i--)
		b[len2-i]=st2[i]-'0';
	len=(len1>len2)?len1:len2;
	for (i=1;i<=len;i++)
		a[i]=a[i]+b[i];
	for (i=1;i<=len;i++)
		if (a[i]>9)
		{
			a[i+1]+=a[i]/ 10;
			a[i]%=10;
			if (i==len ) len++;
		}
	st="";
	for (i=0;i<len;i++)
		st+=a[len-i]+'0';
	return st;
}
int main()
{
	string sp[55][55];
	sp[2][0]="2";
	sp[2][1]="5";
	sp[3][1]="10";
	sp[4][1]="17";
	sp[5][1]="26";
	sp[6][1]="37";
	sp[7][1]="50";
	sp[8][1]="65";
	sp[9][1]="82";
	sp[10][1]="101";
	sp[11][1]="122";
	sp[12][1]="145";
	sp[13][1]="170";
	sp[14][1]="197";
	sp[15][1]="226";
	sp[16][1]="257";
	sp[17][1]="290";
	sp[18][1]="325";
	sp[19][1]="362";
	sp[20][1]="401";
	sp[21][1]="442";
	sp[22][1]="485";
	sp[23][1]="530";
	sp[24][1]="577";
	sp[25][1]="626";
	sp[26][1]="677";
	sp[27][1]="730";
	sp[28][1]="785";
	sp[29][1]="842";
	sp[30][1]="901";
	sp[31][1]="962";
	sp[32][1]="1025";
	sp[33][1]="1090";
	sp[34][1]="1157";
	sp[35][1]="1226";
	sp[36][1]="1297";
	sp[37][1]="1370";
	sp[38][1]="1445";
	sp[39][1]="1522";
	sp[40][1]="1601";
	sp[41][1]="1682";
	sp[42][1]="1765";
	sp[43][1]="1850";
	sp[44][1]="1937";
	sp[45][1]="2026";
	sp[46][1]="2117";
	sp[47][1]="2210";
	sp[48][1]="2305";
	sp[49][1]="2402";
	sp[50][1]="2501";

	int i,j;
	string stp;
	for (i=2;i<=48;i++)
		for (j=2;j<=50-i;j++)
		{
			stp=sp[j][i-1];
			stp=mlpt(stp,j-1);
			stp=addi(stp,sp[j+1][i-1]);
			sp[j][i]=stp;
		}

	int n;
	cin>>n;
	while (n)
	{
		cout<<n<<' ';
		if (n==1)
			cout<<1<<endl;
		else
			cout<<sp[2][n-2]<<endl;
		cin>>n;
	}
	return 0;
}
