//105303 2003-04-03 11:42:30 Accepted 1192 C++ 00:01.17 16820K Century Ghost 
#include<iostream.h>
#include<string.h>
//#include<stdio.h>

struct change
{
	long time;
	long in_add;
	long in_sub;
	long out_add;
	long out_sub;
};


int bug,num;
change from_to[101];
long value[1048576];
int visit[1048576];
long cinal;
long node_heap[1048577];
long node_total;
long org_pos[1048576];

void get_head()
{
	long tt=1;	
	node_heap[1]=node_heap[node_total];
	org_pos[node_heap[1]]=1;
	node_total--;	
	while(1)
	{
		int large=2*tt;
		if(large>node_total)	break;
		if(large<node_total&&value[node_heap[large+1]]<value[node_heap[large]])
			large=large+1;
		if(value[node_heap[large]]<value[node_heap[tt]])
		{
			long temp=node_heap[tt];
			node_heap[tt]=node_heap[large];
			node_heap[large]=temp;
			org_pos[node_heap[tt]]=tt;
			org_pos[node_heap[large]]=large;
			tt=large;
		}
		else	break;
	}
	
}
void add_tail(long position)
{
	long tt=position;
	while(1)
	{
		long father=tt/2;
		if(father<=0)	break;
		if(value[node_heap[tt]]<value[node_heap[father]])
		{
			long temp=node_heap[tt];
			node_heap[tt]=node_heap[father];
			node_heap[father]=temp;
			org_pos[node_heap[tt]]=tt;
			org_pos[node_heap[father]]=father;
			tt=father;
		}		
		else	break;
	}
}

void shortway()
{
	node_total=1;
	node_heap[1]=cinal;
	visit[cinal]=1;
	value[cinal]=0;
	org_pos[cinal]=1;
	while(1)
	{

		if(node_total<1)	break;
		long tt=node_heap[1];
		int i;
		if(tt==0)	return;

		get_head();
		
		
		for(i=0;i<num;i++)
		{

			if((from_to[i].in_add|tt)==cinal&&(from_to[i].in_sub&tt)==0)
			{
				long res=tt|from_to[i].out_add;
				res&=from_to[i].out_sub;

				if(visit[res])
				{
					if(value[res]>value[tt]+from_to[i].time)
					{

						value[res]=value[tt]+from_to[i].time;
						add_tail(org_pos[res]);
					}
					
				}
				else
				{
					
					value[res]=value[tt]+from_to[i].time ;

					visit[res]=1;
					node_heap[++node_total]=res;
					org_pos[res]=node_total;
					add_tail(node_total);
	
				}
			}
		}
	}
	return;
}



int main()
{
//	freopen("bugs.in","r",stdin);
//	freopen("out.txt","w",stdout);
	int count=0;
	while(cin>>bug>>num)
	{
	
		if(bug==0&&num==0)	break;
		int i;
		count++;
	
		char from[21],to[21];
		int j;
		for(j=0;j<num;j++)
		{
			cin>>from_to[j].time>>from>>to;
			
			long in_temp=0;
			for(i=0;i<bug;i++)
			{
				if(from[i]!='+')	in_temp=in_temp*2+1;
				else	in_temp=in_temp*2;
			}
			from_to[j].in_add=in_temp;
			in_temp=0;
			for(i=0;i<bug;i++)
			{
				if(from[i]=='-')	in_temp=in_temp*2+1;
				else	in_temp*=2;
			}
			from_to[j].in_sub=in_temp;
			in_temp=0;
			for(i=0;i<bug;i++)
			{
				if(to[i]=='+')	in_temp=in_temp*2+1;
				else	in_temp*=2;
			}
			from_to[j].out_add=in_temp;
			in_temp=0;
			for(i=0;i<bug;i++)
			{
				if(to[i]=='-')	in_temp*=2;
				else	in_temp=in_temp*2+1;
			}
			from_to[j].out_sub=in_temp;
		}
		cinal=1;
		for(i=0;i<bug;i++)
			cinal*=2;
		cinal--;
		
		memset(value,0,sizeof(value));
		memset(visit,0,sizeof(visit));
		memset(org_pos,0,sizeof(org_pos));
		shortway();
		cout<<"Product "<<count<<endl;
		if(!visit[0])	cout<<"Bugs cannot be fixed."<<endl;
		else	cout<<"Fastest sequence takes "<<value[0]<<" seconds."<<endl;
		cout<<endl;
	}
	return 0;
}

		


