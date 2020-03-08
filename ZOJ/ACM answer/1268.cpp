//189098 2003-07-04 15:46:39 Wrong Answer 1268 C++ 00:00.00 460K just for play 
//189120 2003-07-04 15:54:54 Wrong Answer 1268 C++ 00:00.01 460K just for play 
//189149 2003-07-04 16:11:35 Accepted 1268 C++ 00:00.01 464K just for play 
#include<stdio.h>
#include<vector>
using namespace std;

struct NODE
{
	int label,line_in;
	NODE(int t_label,int t_line_in){label=t_label;line_in=t_line_in;}
	
};
vector<NODE> input_node;
vector<int> line[1000];
int tree_root;
int visit[1000];

int find_v(int val)
{
	int i,result=-1;
	for(i=0;i<input_node.size();i++)
		if(input_node[i].label==val){result=i;break;}
	return result;
}

void add(int fir,int sec)
{
	int fir_v=-1,sec_v=-1;
	fir_v=find_v(fir);
	if(fir_v<0)	{NODE temp(fir,0);input_node.push_back(temp);fir_v=input_node.size()-1;}
	sec_v=find_v(sec);
	if(sec_v<0)	{NODE temp(sec,0);input_node.push_back(temp);sec_v=input_node.size()-1;}
	input_node[sec_v].line_in++;
	line[fir_v].push_back(sec_v);
}

int find_root()
{
	int i;
	tree_root=-1;
	for(i=0;i<input_node.size();i++)
		if(input_node[i].line_in==0)
		{
			if(tree_root<0)	tree_root=i;
			else	return -1;
		}
	if(tree_root<0)	return -1;
	return 1;
}

int dfs(int cur_root)
{
	int i;
	for(i=0;i<line[cur_root].size();i++)
	{
		int next_root=line[cur_root][i];
		if(visit[next_root])	return -1;
		visit[next_root]=true;
		if(dfs(next_root)<0)	return -1;
	}
	return 1;
}
	
int main()
{
//	freopen("1268.in","r",stdin);
	int fir,sec;
	int count=1;
	while(scanf("%d %d",&fir,&sec)!=EOF)
	{
		if(fir<0&&sec<0)	break;
		input_node.clear();
		int i;
		for(i=0;i<1000;i++)	line[i].clear();
		if(fir!=0||sec!=0)
		{
			add(fir,sec);
			while(scanf("%d %d",&fir,&sec)!=EOF)
			{
				if(fir==0&&sec==0)	break;
				add(fir,sec);
			}
		}		
		printf("Case %d",count++);
		if(input_node.size()==0){	printf(" is a tree.\n");continue;}
		if(find_root()<0){	printf(" is not a tree.\n");continue;}
		memset(visit,0,sizeof(visit));
		visit[tree_root]=true;
		if(dfs(tree_root)<0){	printf(" is not a tree.\n");continue;}
		for(i=0;i<input_node.size();i++)
			if(visit[i]==0)	break;
		if(i<input_node.size()){	printf(" is not a tree.\n");continue;}
		printf(" is a tree.\n");
	}
	return 0;
}

			

