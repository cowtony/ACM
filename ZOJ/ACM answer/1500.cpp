//89895 2003-03-16 14:02:05 Accepted 1500 C++ 00:00.00 444K Century Ghost 
#include<iostream.h>
#include<string.h>
#include<vector>
using namespace std;

struct nodetype
{
	char father;	
	vector<char>son_node;
	int total_son;
	nodetype(){total_son=0;father=-1;}
};
char fir[27],sec[27];
int m;int len;
int posfir[27],possec[27];
nodetype node[27];int head;

int search_father(int firchar,int secchar)
{

	int temp=node[secchar].father;
	if(possec[temp]>possec[firchar])	return temp;
	return search_father(firchar,temp);
}
long cal_c(int m,int k)
{

	long temp=1;
	if(m-k<k)	k=m-k;
	int i;
	for(i=m;i>m-k;i--)
		temp*=i;
	for(i=1;i<=k;i++)
		temp/=i;
	return temp;
}

int main()
{

	while(cin>>m)
	{
		if(m==0)	break;
		cin>>fir>>sec;
		len=strlen(fir);
		memset(posfir,0,sizeof(posfir));
		memset(possec,0,sizeof(possec));
		
		int i;
		for(i=0;i<27;i++){	node[i].total_son=0;node[i].son_node.clear();}
		for(i=0;i<len;i++)
		{	posfir[fir[i]-'a']=i;
			possec[sec[i]-'a']=i;
		}
		head=fir[0]-'a';
		node[fir[0]-'a'].father=-1;
		for(i=1;i<len;i++)
		{
			int firchar=fir[i]-'a';int secchar=fir[i-1]-'a';
			if(possec[firchar]<possec[secchar])
			{	node[firchar].father=secchar;
				node[secchar].son_node.push_back(firchar+'a');
				node[secchar].total_son++;
			}
			else
			{
				int temp=search_father(firchar,secchar);
				node[firchar].father=temp;
				node[temp].son_node.push_back(firchar+'a');
				node[temp].total_son++;
			}
		}

		long count=1;
		for(i=0;i<len;i++)
			count*=cal_c(m,node[fir[i]-'a'].total_son);
		cout<<count<<endl;

	}
	return 0;
}

				


		
	
