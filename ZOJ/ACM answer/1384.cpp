#include<iostream.h>
#include<vector>
#include<string.h>
#include<stdio.h>

using namespace std;

const int maxnum=10010;
vector<int>success[maxnum];
//int flag[maxnum][maxnum];
int n,m;
int temp[maxnum];

int visit(int fir,int sec)
{
	int i;
	for(i=0;i<success[fir].size();i++)
		if(success[fir][i]==sec)	return 1;
	return 0;
}
void exchange(int& fir,int& sec)
{
	int temp=fir;
	fir=sec;
	sec=temp;
}
void select(int k)
{
	int fir=-1,sec=-1;
	int i,j;
	
	
	int len=success[k].size();
	for(i=0;i<len;i++)	temp[i]=0;
	for(i=0;i<len;i++)	
	{
		for(j=i+1;j<len;j++)
		{
			if(visit(success[k][i],success[k][j]))
			{	temp[i]++;temp[j]++;
//				cout<<i<<" === "<<j<<endl;
			}
		}
		
		if(temp[i]<=1)
		{
			if(fir==-1)	fir=i;
			else{	sec=i;break;}
		}
	}
//	cout<<fir<<"  "<<sec<<endl;
	if(success[k][fir]>success[k][sec])	exchange(fir,sec);
	exchange(success[k][0],success[k][fir]);
	exchange(success[k][len-1],success[k][sec]);
}





int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int nn;
	cin>>nn;
	
	while(nn--)
	{
		
		cin>>n>>m;
		
		int i,j;int fir,sec;
		/*for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				flag[i][j]=0;
		*/
		for(i=1;i<=n;i++)	success[i].clear();
		
		for(i=0;i<(m+n);i++)
		{
		
			cin>>fir>>sec;
		
			//flag[fir][sec]=1;flag[sec][fir]=1;
			success[fir].push_back (sec);
			success[sec].push_back (fir);
		}
/*		for(i=1;i<=n;i++)
		{
			for(j=0;j<success[i].size();j++)
				cout<<success[i][j]<<" ";
			cout<<endl;
		}
*/
		for(i=1;i<=n;i++)
		{
			select(i);
			int pt;
			int len=success[i].size();
			for(pt=0;pt<len-1;pt++)
			{
				for(j=pt+1;j<len;j++)	
				{
					if(visit(success[i][pt],success[i][j]))	break;
				}
				if(j<len)	exchange(success[i][pt+1],success[i][j]);
			}
		}
		cout<<"1";
		cout<<" "<<success[1][0];
		memset(temp,0,sizeof(temp));
		temp[1]=1;temp[success[1][0]]=1;
		int pt=success[1][0];
		for(i=2;i<n;i++)
		{
			cout<<" ";
			if(!temp[success[pt][0]]){	cout<<success[pt][0];temp[success[pt][0]]=1;pt=success[pt][0];}
			else{	cout<<success[pt][success[pt].size()-1];temp[success[pt][success[pt].size()-1]]=1;pt=success[pt][success[pt].size()-1];}
		}
		cout<<endl;
	}
	return 0;
}


						




