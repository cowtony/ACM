//315882 2003-10-17 21:08:43 Runtime Error SIGSEGV 1642 C++ 00:00.09 4340K just for play 
//315908 2003-10-17 21:26:44 Accepted 1642 C++ 00:00.29 532K just for play 
#include<stdio.h>
#include<string.h>
#include<iostream.h>

struct TTT
{
	char ch;
	int val;
};
TTT input[100];
int n;
int num[2][10000];

int get_val(char tch)
{
	int i;
	for(i=0;i<n;i++)
		if(tch==input[i].ch)	return input[i].val ;
}

int main()
{
	freopen("1642.in","r",stdin);
	while(cin>>n)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			cin>>input[i].ch>>input[i].val;
			
		}
		char str1[10000],str2[10000];
		cin>>str1>>str2;
		
		
		int len1=strlen(str1),len2=strlen(str2);
//		for(i=0;i<=len1;i++)	num[i][0]=0;
		for(i=0;i<=len2;i++)	num[0][i]=0;
		int pt=1;
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				num[pt][j]=num[1-pt][j];
				if(num[pt][j-1]>num[pt][j])	num[pt][j]=num[pt][j-1];
				if(str1[i-1]==str2[j-1])
				{
					int tt=get_val(str1[i-1]);
					if(num[1-pt][j-1]+tt>num[pt][j])	num[pt][j]=num[1-pt][j-1]+tt;
				}
			}
			pt=1-pt;
		}
		cout<<num[1-pt][len2]<<endl;
	}
	return 0;
}



		