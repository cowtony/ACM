//139534 2003-05-03 14:52:29 Wrong Answer 1589 C++ 00:00.06 456K just for play 
//139540 2003-05-03 14:58:14 Accepted 1589 C++ 00:00.06 456K just for play 
#include<iostream.h>
#include<vector>
#include<string.h>

using namespace std;

vector<int>success[26];
inline int is_in(vector<int>& tt,int num)
{
	int i;
	for(i=0;i<tt.size ();i++)
		if(tt[i]==num)	return 1;
	return 0;
}

int renew(vector<int>& tt,int num)
{
	int i;
	int changed=0;
	for(i=0;i<success[num].size();i++)
	{
		if(!is_in(tt,success[num][i]))
		{
			tt.push_back (success[num][i]);
			renew(tt,success[num][i]);
			changed=1;
		}
	}

	return changed;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int nn;
	cin>>nn;
	int tt;
	
	int relation[26][26];
		
	for(tt=1;tt<=nn;tt++)
	{
		int n;
		cin>>n;
		int i,j;
		memset(relation,0,sizeof(relation));	
		for(i=0;i<26;i++)
			success[i].clear ();
		for(i=0;i<n;i++)
		{
			char fir,sec,temp;
			cin>>fir>>temp>>sec;
			if(temp=='<')
			{
				relation[fir-'A'][sec-'A']=1;
				if(!is_in(success[fir-'A'],sec-'A'))
					success[fir-'A'].push_back (sec-'A');
			}
			else
			{
				relation[sec-'A'][fir-'A']=1;
				if(!is_in(success[sec-'A'],fir-'A'))
					success[sec-'A'].push_back (fir-'A');
			}
		}
		while(1)
		{
/*
			for(i=0;i<26;i++)
			{
			
				if(success[i].size()>0)	cout<<(char)(i+'A')<<"--->";
				for(j=0;j<success[i].size ();j++)
					cout<<(char)('A'+success[i][j])<<" ";
				if(success[i].size()>0)	cout<<endl;
			}
			
*/
			int changed=0;
			for(i=0;i<26;i++)
			{
				for(j=0;j<success[i].size();j++)
					if(renew(success[i],success[i][j]))	changed=1;
			}
			if(!changed)	break;
		}

		cout<<"Case "<<tt<<":"<<endl;
		int output=0;	
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)
				if(is_in(success[i],j)&&!relation[i][j])
				{
					cout<<(char)(i+'A')<<"<"<<(char)(j+'A')<<endl;
					output=1;
				}
		if(!output)	cout<<"NONE"<<endl;
	}
	return 0;
}



