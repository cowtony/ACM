//92832 2003-03-19 23:16:43 Wrong Answer 1197 C++ 00:00.01 448K Century Ghost 
//92840 2003-03-19 23:22:18 Wrong Answer 1197 C++ 00:00.00 448K Century Ghost 
//93055 2003-03-20 12:42:46 Wrong Answer 1197 C++ 00:00.00 448K Century Ghost 
//93618 2003-03-20 22:18:24 Accepted 1197 C++ 00:00.00 452K Century Ghost 
#include<stdio.h>
#include<vector>
//#include<iostream.h>
using namespace std;

struct rect
{
	int minx,maxx,miny,maxy;
};

struct point
{
	int x,y;
};

rect slide[27];
point coord[27];
int n;
vector<int>match[27];
vector<int>pointset[27];

int in_rect(int j,int k)
{
	if(coord[j].x>slide[k].minx&&coord[j].x<slide[k].maxx
		&&coord[j].y>slide[k].miny&&coord[j].y<slide[k].maxy)
			return 1;
	return 0;
}
void erase(int rect,int pot)
{
	match[rect].clear();
	pointset[pot].clear ();
	int i,j;
	for(i=0;i<n;i++)
	{
		int len=match[i].size();
		for(j=0;j<len;j++)
			if(match[i][j]==pot)	break;
		if(j<len)
		{
			
			match[i][j]=match[i][len-1];
			match[i].pop_back ();
			
		}
	}
	for(i=0;i<n;i++)
	{
		int len=pointset[i].size();
		for(j=0;j<len;j++)
			if(pointset[i][j]==rect)	break;
		if(j<len)
		{
			
			pointset[i][j]=pointset[i][len-1];
			pointset[i].pop_back ();
			
		}
	}
}

int same(vector<int>& fir,vector<int>& sec)
{
	if(fir.size()!=sec.size())	return 0;
	int i,j;int len=fir.size ();
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
			if(fir[i]==sec[j])	break;
		if(j==len)	return 0;
	}
	return 1;
}
int main()
{

	int count=0;
	while(scanf("%d",&n))
	{
		if(n==0)	break;
		count++;
		int i,j;

		for(i=0;i<n;i++)
			scanf("%d%d%d%d",&slide[i].minx,&slide[i].maxx,&slide[i].miny,&slide[i].maxy);
		for(i=0;i<n;i++)
			scanf("%d%d",&coord[i].x,&coord[i].y);


		for(i=0;i<n;i++){	match[i].clear();pointset[i].clear();}

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(in_rect(j,i))
				{
					match[i].push_back(j);
					pointset[j].push_back(i);
				}
			}
/*
		for(i=0;i<n;i++)
		{
			int temp;
			while(scanf("%d",&temp))
			{
				if(temp<0)	break;
				match[i].push_back (temp-1);
				pointset[temp-1].push_back (i);
			}
		}
*/
			/*
		for(i=0;i<n;i++)
		{	
			cout<<char(i+'A')<<"-------"<<endl;
			for(j=0;j<match[i].size();j++)
				cout<<match[i][j]<<" ";
			cout<<endl;
		}
*/
		int fixed[27];
		for(i=0;i<n;i++)	fixed[i]=-1;
		while(1)
		{
			int changed=0;
			for(i=0;i<n;i++)			
				if(match[i].size()==1)
				{
					fixed[i]=match[i][0];
			
					changed=1;
					erase(i,fixed[i]);
				}
			for(i=0;i<n;i++)
				if(pointset[i].size()==1)
				{
					fixed[pointset[i][0]]=i;
			
					changed=1;
					erase(pointset[i][0],i);
				}
			
			if(changed)	continue;
			int flag_rect[27];int flag_pot[27];
			int total=0;
			for(i=0;i<n;i++)
			{
				if(match[i].size()>1)
				{
					int len=match[i].size ();
					flag_rect[0]=i;
					total=1;
					for(j=i+1;j<n;j++)					
						if(same(match[i],match[j]))							
							flag_rect[total++]=j;
					if(total==len)
					{
						
						int pt=0;
						changed=1;
						for(j=0;j<len;j++)
							flag_pot[pt++]=match[i][j];
/*
						for(j=0;j<len;j++)
							cout<<flag_rect[j]<<"===  ";
						cout<<endl;
						for(j=0;j<len;j++)
							cout<<flag_pot[j]<<"====   ";
						cout<<endl;
*/
						for(j=0;j<len;j++)
							erase(flag_rect[j],flag_pot[j]);
					}
				}
			}
			if(changed)	continue;
			for(i=0;i<n;i++)
			{
				if(pointset[i].size()>1)
				{
					int len=pointset[i].size ();
					flag_pot[0]=i;
					total=1;
					for(j=i+1;j<n;j++)					
						if(same(pointset[i],pointset[j]))						
							flag_pot[total++]=j;
					if(total==len)
					{
						int pt=0;
						changed=1;
						for(j=0;j<len;j++)
							flag_rect[pt++]=pointset[i][j];

/*
						for(j=0;j<len;j++)
							cout<<flag_rect[j]<<"  ";
						cout<<endl;
						for(j=0;j<len;j++)
							cout<<flag_pot[j]<<"   ";
						cout<<endl;
*/
						for(j=0;j<len;j++)
							erase(flag_rect[j],flag_pot[j]);
					}
				}
			}
			
			if(!changed)	break;
		}

			
/*
			for(i=0;i<n;i++)
			{	
				fout<<char(i+'A')<<"=========="<<endl;
				for(j=0;j<match[i].size();j++)
					fout<<match[i][j]<<" ";
				fout<<endl;
			}
*/
		
		int output=0;
		printf("Heap %d\n",count);
		int first=1;
		for(i=0;i<n;i++)
		{
			if(fixed[i]!=-1)
			{
				if(!first)	printf(" ");
				printf("(%c,%d)",i+'A',fixed[i]+1);
				first=0;output=1;
			}
		}
		if(!output)	printf("none");
		printf("\n\n");
	}
	return 0;
}



		

