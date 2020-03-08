//106991 2003-04-04 22:45:39 Wrong Answer 1301 C++ 00:00.00 736K Century Ghost 
//107015 2003-04-04 22:57:56 Accepted 1301 C++ 00:00.05 736K Century Ghost 
#include<iostream.h>
#include<string.h>
#include<vector>
#include<stdio.h>

using namespace std;

const int maxnum=11;
int r,d,s;
int door[maxnum][maxnum],light[maxnum][maxnum];
int visit[1025][11];
int mark[11]={1,2,4,8,16,32,64,128,256,512,1024};
int lightoff[11]={2046,2045,2043,2039,2031,2015,1983,1919,1791,1535,1023};

struct node
{
	int state;
	int father;
	int move;
	int person;
	node()
	{
		move=0;
	}
};

node room[10250];

int node_heap[10250];
int node_total;
int org_pos[10250];

void get_head()
{
	int tt=1;	
	node_heap[1]=node_heap[node_total];
	org_pos[node_heap[1]]=1;
	node_total--;	
	while(1)
	{
		int large=2*tt;
		if(large>node_total)	break;
		if(large<node_total&&room[node_heap[large+1]].move<room[node_heap[large]].move)
			large=large+1;
		if(room[node_heap[large]].move<room[node_heap[tt]].move)
		{
			int temp=node_heap[tt];
			node_heap[tt]=node_heap[large];
			node_heap[large]=temp;
			org_pos[node_heap[tt]]=tt;
			org_pos[node_heap[large]]=large;
			tt=large;
		}
		else	break;
	}
	
}
void add_tail(int position)
{
	int tt=position;
	while(1)
	{
		int father=tt/2;
		if(father<=0)	break;
		if(room[node_heap[tt]].move<room[node_heap[father]].move)
		{
			int temp=node_heap[tt];
			node_heap[tt]=node_heap[father];
			node_heap[father]=temp;
			org_pos[node_heap[tt]]=tt;
			org_pos[node_heap[father]]=father;
			tt=father;
		}		
		else	break;
	}
}
struct temnode
{
	int state;
	int move;
};
int light_is_on(int curstate,int k)
{
	return (curstate&mark[k-1]);
}
void get_state(vector<temnode>& gen_state,temnode& temp,int curper,int tt)
{
	int i;
	for(i=tt;i<=r;i++)
	{
		if(i==curper)	continue;
		if(light[curper][i])
		{
			temnode curtemp;
			curtemp.move=temp.move+1;
			if(light_is_on(temp.state,i))			
				curtemp.state=temp.state&lightoff[i-1];							
			else	curtemp.state=temp.state|mark[i-1];
			
			gen_state.push_back(curtemp);
			get_state(gen_state,curtemp,curper,i+1);
		
		}
	}
}

int search()
{
	node_total=1;
	room[1].father=-1;
	room[1].move=0;
	room[1].person=1;
	node_heap[1]=1;
	room[1].state=1;
	visit[1][1]=1;
	org_pos[1]=1;
	int total=1;
	while(node_total>0)
	{

		int tt=node_heap[1];
//		cout<<tt<<"  from ----------"<<endl;
//		cout<<"father:   "<<room[tt].father<<" move  "<<room[tt].move<<" in room  "<<room[tt].person<<"  state  "<<room[tt].state<<endl;
		if(room[node_heap[1]].person==r&&room[node_heap[1]].state==mark[r-1])	return node_heap[1];
		get_head();
		vector<temnode>gen_state;
		temnode temp;
		
		temp.move=0;temp.state=room[tt].state;
		gen_state.push_back (temp);
		get_state(gen_state,temp,room[tt].person,1);
		int i;
		for(i=0;i<gen_state.size();i++)
		{
/*
			if(light_is_on(gen_state[i].state,room[tt].person))
			{
			total++;
			room[total].father=tt;
			room[total].move=room[tt].move+gen_state[i].move;
			room[total].state=gen_state[i].state;
			room[total].person=room[tt].person;
//			cout<<"------->";
//			cout<<"father:   "<<room[total].father<<" move  "<<room[total].move<<" in room  "<<room[total].person<<"  state  "<<room[total].state<<endl;
			if(visit[room[total].state][room[total].person])
			{
//				cout<<"=====add"<<endl;
				int temppt=visit[room[total].state][room[total].person];
				if(room[temppt].move>room[total].move)
				{
					room[temppt].move=room[total].move;
					add_tail(org_pos[temppt]);
//					cout<<"<<<<<<<<<<<<renew"<<endl;
				}
				total--;
			}
			else
			{				
//				cout<<"=======new"<<endl;
				visit[room[total].state][room[total].person]=total;
				node_heap[++node_total]=total;
				org_pos[total]=node_total;
				add_tail(node_total);
			}
			}	
*/
			int j;
			for(j=1;j<=r;j++)
			{
				if(j==room[tt].person)	continue;
				if(door[room[tt].person][j]&&light_is_on(gen_state[i].state,j))
				{
					total++;
					room[total].father=tt;
					room[total].move=room[tt].move+gen_state[i].move+1;
					room[total].state=gen_state[i].state;
					room[total].person=j;
//					cout<<"------->";
//					cout<<"father:   "<<room[total].father<<" move  "<<room[total].move<<" in room  "<<room[total].person<<"  state  "<<room[total].state<<endl;
					if(visit[room[total].state][room[total].person])
					{
//						cout<<"===add"<<endl;
						int temppt=visit[room[total].state][room[total].person];
						if(room[temppt].move>room[total].move)
						{
//							cout<<"======renew"<<endl;
							room[temppt].move=room[total].move;
							add_tail(org_pos[temppt]);
						}
						total--;
					}
					else
					{
//						cout<<"======new"<<endl;
						visit[room[total].state][room[total].person]=total;
						node_heap[++node_total]=total;
						org_pos[total]=node_total;
						add_tail(node_total);
					}
				}
			}
		}
	}
	return -1;
}
				

void print(node& fir,node& sec)
{
	int i;
	for(i=1;i<=r;i++)
	{
		if(light_is_on(fir.state,i))
		{
			if(!light_is_on(sec.state,i))
				cout<<"- Switch off light in room "<<i<<"."<<endl;
		}
		else if(light_is_on(sec.state,i))
			cout<<"- Switch on light in room "<<i<<"."<<endl;
	}
	if(fir.person!=sec.person)	
		cout<<"- Move to room "<<sec.person<<"."<<endl;	
}


void output(int pt)
{
	if(room[pt].father==-1)	return;
	output(room[pt].father);
	print(room[room[pt].father],room[pt]);
}

	


int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int count=0;
	while(cin>>r>>d>>s)
	{
		if(r==0&&d==0&&s==0)	break;
		count++;
		int i;
		memset(visit,0,sizeof(visit));
		memset(door,0,sizeof(door));
		memset(light,0,sizeof(light));
		int fir,sec;
		for(i=0;i<d;i++)
		{
			cin>>fir>>sec;
			door[fir][sec]=1;
			door[sec][fir]=1;
		}
		for(i=0;i<s;i++)
		{
			cin>>fir>>sec;
			light[fir][sec]=1;
		}
		
		int res=search();
		
		cout<<"Villa #"<<count<<endl;
		if(res==-1)	cout<<"The problem cannot be solved."<<endl;
		else
		{
			cout<<"The problem can be solved in "<<room[res].move<<" steps:"<<endl;
			output(res);
		}
		cout<<endl;
	}
	return 0;
}





		