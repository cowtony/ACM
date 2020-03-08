#include<iostream.h>
#include<string.h>

char cloth[100][100];
bool visit[100][100];
int Width,Height;
int MinSize,MaxHole;
int left[100],right[100];

void cloth_search(int i,int j,int& tsize)
{
	visit[i][j]=true;
	tsize++;
	if(left[i]<0||left[i]>i)	left[i]=i;
	if(right[i]<0||right[i]<i)	right[i]=i;
	if(j>0&&cloth[i][j-1]=='*'&&!visit[i][j-1])
		cloth_search(i,j-1,tsize);
	if(j<Width-1&&colth[i][j+1]==

int main()
{
	while(cin>>Width>>Height)
	{
		memset(visit,false,sizeof(visit));
		MinSize=0,MaxHole=-1;
		int i,j;
		for(i=0;i<Height;i++)
			for(j=0;j<Width;j++)
				cin>>cloth[i][j];
		for(i=0;i<Height;i++)
			for(j=0;j<Widht;j++)
				if(cloth[i][j]=='*'&&!visit[i][j])
				{
					memset(left,0xff,sizeof(left));
					memset(right,0xff,sizeof(right));
					int tsize=0,t_hole=0;
					cloth_search(i,j,tsize);
					for(i=0;i<Height;i++)
					{
						if(left[i]>0||right[i]>0)
						{
							if(left[i]>0&&right[i]>0)
							{
								if(left[i]<right[i])
									t_hole+=right[i]-left[i]-1;
							}
							else if(left[i]>0)
								t_hole+=Width-left[i];
							else	t_hole+=right[i];
						}
					}
					if(t_hole>MaxHole)
					{
						MaxHole=t_hole;MinSize=tsize;
					}
					else if(t_hole==MaxHole)
					{
						if(Minsize>tsize)	MinSize=tsize;
					}
				}
		cout<<MinSize<<endl;
	}
	return 0;
}

							

					
					




