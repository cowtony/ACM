#include<iostream.h>
#include<string.h>

char word[101][101];
int input;
char temp[100];

void search(int& begx,int& begy,int& endx,int& endy)
{
	int len=strlen(temp);
	int i,j;
}
	
int main()
{
	int n;int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		if(i)	cout<<endl;
		cin>>input;
		int  j,t;
		for(j=1;j<=input;j++)
			for(t=1;t<=input;t++)
				cin>>word[j][t];

		while(cin>>temp)
		{
			if(strcmp(temp,"0")==0)	break;
			int begx=-1,begy,endx,endy;
			search(begx,begy,endx,endy);
			if(begx==-)	cout<<"Not found"<<endl;
			else cout<<begx<<","<<begy<<" "<<endx<<","<<endy<<endl;
		}
	}
	return 0;
}

