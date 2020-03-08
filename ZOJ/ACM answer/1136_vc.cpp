//104559 2003-04-02 13:36:49 Runtime Error SIGFPE 1136 C++ 00:00.01 0K Century Ghost 
//104566 2003-04-02 13:45:39 Wrong Answer 1136 C++ 00:00.12 692K Century Ghost 

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct nodetype
{
    int cur;
    int mod_res;
    int father;
};
int visit[5000];
int n;int m;
vector<nodetype>bfs_res;
vector<int>digit;
bool smaller(const int& fir,const int& sec)
{
		return (fir<sec);
}
int bfs_search()
{
    int beg=0;int end=bfs_res.size()-1;
    while(beg<=end)
    {
	
        int tempnum=bfs_res[beg].mod_res;
		int i;
		for(i=0;i<m;i++)
		{
			int ttdig=digit[i];
			int tt=(tempnum*10+ttdig)%n;
			if(!visit[tt])
			{
                nodetype temp;
                temp.cur=ttdig;
                temp.mod_res=tt;
                temp.father=beg;
                bfs_res.push_back(temp);
                visit[tt]=1;
                end++;
                if(tt==0)                return end;
			}
		}
        beg++;
    }
     return -1;
}
  
void print(int num)
{
	
    if(bfs_res[num].father>=0)
        print(bfs_res[num].father);
    cout<<bfs_res[num].cur;
 }                    
int main()
{
   while(cin>>n)
    {
        
		
		cin>>m;int tempdig;
		int i;
		digit.clear();
		for(i=0;i<m;i++)
		{
			cin>>tempdig;
			digit.push_back(tempdig);
		}
		sort(digit.begin(),digit.end(),smaller);
        memset(visit,0,sizeof(visit));
        bfs_res.clear();int cind_fir=0;
		if(n==0)
		{
			int i;
			for(i=0;i<m;i++)
			{
				if(digit[i]==0)	continue;
				cout<<digit[i]<<endl;
				break;
			}
			if(i==m)	cout<<"0"<<endl;
			continue;
		}
		for(i=0;i<m;i++)
		{
			int ttdig=digit[i];
			if(ttdig==0)	continue;
			nodetype temp;
			temp.cur=ttdig;	
			temp.mod_res=ttdig%n;			
			temp.father=-1;
			if(visit[ttdig%n]==1)	continue;
			visit[ttdig%n]=1;
			bfs_res.push_back(temp);
			if(ttdig%n==0)	{cind_fir=1;break;}
			
		}
        int res;
        if(!cind_fir)
			res=bfs_search();
        else res=i;
		
		if(res<0)	cout<<"0";
        else	print(res);
        cout<<endl;
     }
     return 0;
 } 
   
        
        
        
        


