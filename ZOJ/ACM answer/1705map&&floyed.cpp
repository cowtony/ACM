#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
map<string,int>item;	
int que;
int Assertion;
struct rate
{
	int x,y;
};
int gcb(int a, int b)
{
	int r,temp;
	if(a<b)
	{
		temp = a;
		a = b ;
		b = temp;
	}
	while(b)
	{
		r = a % b;
		a = b;
		b = r ;
	}
	return a ;
}
rate question[101];
rate a[101][101];

void Floyed()
{
	int i=0 , j=0 , k=0;
 
	for( i = 1 ; i <= Assertion ; i++)
			for( j = 1 ; j <= Assertion ; j++) 	
				for (k = 1 ; k <= Assertion ; k++)
				{
					if( i!=j&&j!=k&&i!=k&&a[i][j].x != 0 && a[k][i].x != 0)
					{
						int a1,a2;
						a1 = a[i][j].x * a[k][i].x;
						a2 = a[i][j].y * a[k][i].y;
						a[k][j].x = a1 / gcb(a1,a2);
						a[k][j].y = a2 / gcb(a1,a2);

					}
				}

}

int main()
{
	memset(a,0,sizeof(a));
	char signal,equal;
	Assertion = 1;
	int flag = 0;
	que = 0;
	//freopen("1.txt","r",stdin);
	while(scanf("%c",&signal) != EOF && signal != '.')
	{
		switch(signal)
		{
		case '!':
			{
				int n1,n2;
				string s1,s2;
				cin >> n1 >> s1;
				cin >> equal;
				cin>>n2>>s2;
				getchar();
				if(item[s1] ==0)
					item[s1] = Assertion++;//map映射时最好 从 1开始 ！！！不会出错 ！切记切记
				if(item[s2] == 0)
					item[s2] = Assertion++;
				 int a1 = n1 ;
				 int b1 = n2 ; 
				n1 = a1 / gcb(a1,b1);
				n2 = b1 / gcb(a1,b1);
				a[item[s1]][item[s2]].x = n2;
				a[item[s1]][item[s2]].y = n1;
				a[item[s2]][item[s1]].x = n1;
				a[item[s2]][item[s1]].y = n2;
				flag = 0; 
				break;
				
			}
		case '?':
			{
				if(flag == 0)
					Floyed();
				string temp1,temp2 ;
				cin>>temp1>>equal>>temp2;
				getchar();
				if(a[item[temp1]][item[temp2]].x == 0)
						cout<<"? "<<temp1<<" = ? "<<temp2<<endl;
				else 
					cout<<a[item[temp1]][item[temp2]].y<<" "<<temp1<<" = "<<a[item[temp1]][item[temp2]].x<<" "<<temp2<<endl;			
				flag = 1;
				break;
			}

		}

		

	}

	return 0 ;
}