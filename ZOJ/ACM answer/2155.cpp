#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str="CDSH";
	string haha="23456789TJQKA";
	string si;
	int i,j,k,te,ta;
	int p=0;
	while(cin>>si)
	{
		if(si=="#") break;
		if(si=="N") te=2;
		else if(si=="S") te=0;
		else if(si=="W") te=1;
		else te=3;//te表示此时发牌的对象
		te+=1;
		if(te>3) te=0;
		int ta=te;
		string s[4];
		int a[4][13];
		int now=0;//now 表示此人的第now个发牌
		string temp;
		if(!p) p=1;
		else printf("\n");
		for(j=0; j<2; j++)
		{
			cin>>temp;
			for(i=0; i<temp.length(); i+=2)
			{
				int t=str.find(temp[i]);
				a[te][now]=t;
				s[te]+=temp[i+1];
				te+=1;
				if(te>3) te=0;
				if(te==ta) now+=1;
			}
		}
		for(i=0; i<4; i++)
		{
			for(j=0; j<s[i].length(); j++)
			{
				for(k=j+1; k<s[i].length(); k++)
				{
					if(a[i][j]>a[i][k])
					{
						swap(a[i][j],a[i][k]);
						swap(s[i][j],s[i][k]);
					}
					else if(a[i][j]==a[i][k])
					{
						if(haha.find(s[i][j])>haha.find(s[i][k]))
						{
							swap(a[i][j],a[i][k]);
							swap(s[i][j],s[i][k]);
						}
					}
				}
			}
		}
		for(i=0; i<4; i++)
		{
			if(i==0) printf("South player:\n");
			else if(i==1) printf("West player:\n");
			else if(i==2) printf("North player:\n");
			else printf("East player:\n");
			printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
			for(j=0; j<13; j++)
			{
				printf("|%c %c",s[i][j],s[i][j]);
			}
			printf("|\n");
			for(j=0; j<13; j++)
			{
				printf("| ");
				if(a[i][j]==0) printf("C ");
				else if(a[i][j]==1) printf("D ");
				else if(a[i][j]==2) printf("S ");
				else printf("H ");
			}
			printf("|\n");
			for(j=0; j<13; j++)
			{
				printf("|%c %c",s[i][j],s[i][j]);
			}
			printf("|\n");
			printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
		}
	}
	return 0;
}
