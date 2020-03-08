//145569 2003-05-09 23:11:51 Time Limit Exceeded 1102 C++ 00:10.00 1784K just for play 
#include<iostream.h>
#include<string.h>
#include<vector>
//#include<stdio.h>
using namespace std;

int is_in(vector<char>& tt,char ch)
{
	int i;
	for(i=0;i<tt.size ();i++)
		if(tt[i]==ch)	return 1;
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char input[1025][1001];
	int n,len;
	while(cin>>n>>len)
	{
		if(n==0&&len==0)	break;
		int i,j,t;
		for(i=0;i<n;i++)
			cin>>input[i];
		char result[1001];
		vector<char>poss_ch[12][1025];
		vector<int>val_ch[12][1025];
		int high=0;int tt=n;
		while(tt){tt=tt>>1;high++;}
		int total=0;
		for(i=0;i<len;i++)
		{
			tt=1;
			for(j=0;j<high;j++)	
			{
				for(t=0;t<tt;t++)
				{
					poss_ch[j][t].clear();
					val_ch[j][t].clear();
				}
				tt*=2;
			}
			for(j=0;j<n;j++)
			{
				poss_ch[high-1][j].push_back(input[j][i]);
				val_ch[high-1][j].push_back(0);
			}
			tt=n/2;
			for(j=high-2;j>=0;j--)
			{
				for(t=0;t<tt;t++)
				{
					int len_1=poss_ch[j+1][2*t].size();
					int len_2=poss_ch[j+1][2*t+1].size();
					int kt;int pt_1,pt_2;
					int up_pt=0;
					for(kt=0;kt<len_1;kt++)
					{
						poss_ch[j][t].push_back(poss_ch[j+1][2*t][kt]);
						int min=-1;
						for(pt_1=0;pt_1<len_1;pt_1++)
							for(pt_2=0;pt_2<len_2;pt_2++)
							{
								int t_val=val_ch[j+1][2*t][pt_1]+val_ch[j+1][2*t+1][pt_2];
								if(poss_ch[j][t][up_pt]!=poss_ch[j+1][2*t][pt_1])	t_val++;
								if(poss_ch[j][t][up_pt]!=poss_ch[j+1][2*t+1][pt_2])	t_val++;
								if(min==-1||min>t_val)	min=t_val;
							}
						val_ch[j][t].push_back(min);
						up_pt++;
					}
					for(kt=0;kt<len_2;kt++)
					{
						if(is_in(poss_ch[j][t],poss_ch[j+1][2*t+1][kt]))	continue;
						poss_ch[j][t].push_back(poss_ch[j+1][2*t+1][kt]);
						int min=-1;
						for(pt_1=0;pt_1<len_1;pt_1++)
							for(pt_2=0;pt_2<len_2;pt_2++)
							{
								int t_val=val_ch[j+1][2*t][pt_1]+val_ch[j+1][2*t+1][pt_2];
								if(poss_ch[j][t][up_pt]!=poss_ch[j+1][2*t][pt_1])	t_val++;
								if(poss_ch[j][t][up_pt]!=poss_ch[j+1][2*t+1][pt_2])	t_val++;
								if(min==-1||min>t_val)	min=t_val;
							}
						val_ch[j][t].push_back(min);
						up_pt++;
					}
				}
				tt/=2;
			}
			int min=val_ch[0][0][0];int pt=0;
			for(j=1;j<poss_ch[0][0].size();j++)
				if(val_ch[0][0][j]<min){	min=val_ch[0][0][j];pt=j;}
			result[i]=poss_ch[0][0][pt];
			total+=min;
		}
		result[len]='\0';
		cout<<result<<" "<<total<<endl;
	}
	return 0;
}

			



			
			
			
