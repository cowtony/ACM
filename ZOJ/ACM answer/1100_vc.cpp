
/*
int flag[12][12];
long count;
struct link
{
	int rr;int cc;
	link* next;
};

link* add(link* changed,int x,int y)
{
	link* temp=new link;
	temp->rr=x;
	temp->cc=y;
	temp->next=NULL;
	link* move=changed;
	if(changed==NULL)	changed=temp;
	else
	{
		while(move->next!=NULL)
			move=move->next;
		move->next=temp;
	}
	return changed;
}

void recover(link* changed)
{
	link* move=changed;
	while(move!=NULL)
	{	flag[move->rr][move->cc]=1;
		move=move->next;
	}
}
void calnext(int x,int y,int& nextx,int& nexty)
{
	while(1)
	{
		y++;
		if(y>=col)	
		{	x++;
			if(x>=row){nextx=-1;nexty=-1;return;}
			y=0;
		}
		if(!flag[x][y])
		{
			nextx=x;nexty=y;return;
		}
	}
}


		
void search(int x,int y)
{
	int i,j;
	if(y+1<col&&flag[x][y]==0)
	{	link* changed=NULL;
		changed=add(changed,x,y);
		changed=add(changed,x,y+1);
		flag[x][y]=1;flag[x][y+1]=1;
		int canextend=1;
		for(i=x;i<row;i++)
		{	int chflag=0;
			for(j=0;j<col;j++)
			{
				if(flag[i][j]){	chflag=1;continue;}
				if((j==0&&j+1<col&&flag[i][j+1])||(j==col-1&&j-1>=0&&flag[i][j-1])||
					(j+1<col&&j-1>=0&&flag[i][j+1]&&flag[i][j-1]))	
				{	
					if(i+1>=row){	canextend=0;break;}
					changed=add(changed,i,j);
					changed=add(changed,i+1,j);
					flag[i][j]=1;flag[i+1][j]=1;
				}
			}
			if(!chflag||canextend==0)	break;
		}
		if(!canextend)	recover(changed);
		else
		{
			int nextx,nexty;
			calnext(x,y,nextx,nexty);
			if(nextx==-1&&nexty==-1)	count++;
			else search(nextx,nexty);
			recover(changed);
		}
	}
	if(x+1<row&&!flag[x+1][y])
	{
		link* changed=NULL;
		changed=add(changed,x,y);
		changed=add(changed,x+1,y);
		flag[x][y]=1;flag[x+1][y]=1;
		int canextend=1;
		for(i=x;i<row;i++)
		{	int chflag=0;
			for(j=0;j<col;j++)
			{
				if(flag[i][j]){	chflag=1;continue;}
				if((j==0&&j+1<col&&flag[i][j+1])||(j==col-1&&j-1>=0&&flag[i][j-1])||
					(j+1<col&&j-1>=0&&flag[i][j+1]&&flag[i][j-1]))	
				{	
					if(i+1>=row){	canextend=0;break;}
					changed=add(changed,i,j);
					changed=add(changed,i+1,j);
					flag[i][j]=1;flag[i+1][j]=1;
				}
			}
			if(!chflag||canextend==0)	break;
		}
		if(!canextend)	recover(changed);
		else
		{
			int nextx,nexty;
			calnext(x,y,nextx,nexty);
			if(nextx==-1&&nexty==-1)	count++;
			else search(nextx,nexty);
			recover(changed);
		}
	}
}

				


		
*/

#include<iostream.h>
int row,col;
long total;

int cangonext(int flag[])
{
	int i;
	if(flag[1]&&!flag[0])	return 0;
	if(flag[col-2]&&!flag[col-1])	return 0;
	for(i=1;i<col-1;i++)	
		if(!flag[i]&&flag[i-1]&&flag[i+1])	return 0;
	return 1;
}
int canput(int flag[],int put[],int lev,int n)
{
	if(lev==n)
	{
		int tempflag[11];int i;
		for(i=0;i<col;i++)	tempflag[i]=flag[i];
		for(i=0;i<n;i++)	tempflag[put[i]]=1;		
		if(cangonext(tempflag)){put[lev-1]++;	return 1;}
		return 0;
	}
	int i,j;
	if(lev>0&&beg[lev]<=put[lev-1])	beg[lev]=put[lev-1]+1;
	for(put[lev]=beg[lev];put[lev]<col;put[lev]++)
	{		
		if(!flag[put[lev]])	
			if(canput(flag,put,lev+1,n))	return 1;		
	}
	return 0;
}


void search(int flag[],int lev)
{
		int i;
		cout<<lev<<"======";
		for(i=0;i<col;i++)	cout<<flag[i]<<" ";
		cout<<endl;
		cin.get();
		if(lev==row)
		{	
			if(cangonext(flag))	total++;
			return ;
		}
		int nextflag[11];
		int left=col;int j;
		for(i=0;i<col;i++)	left-=flag[i];
		for(i=0;i<=left;i++)
		{
			int put[11];
			for(j=0;j<i;j++)	put[i]=0;			
			while(canput(flag,put,0,i))
			{	for(j=0;j<col;j++)	nextflag[j]=0;
				cout<<lev<<"====";
				for(j=0;j<i;j++)	cout<<put[j]<<" ";
				cout<<endl;
				for(j=0;j<i;j++)	nextflag[put[j]]=1;
				search(nextflag,lev+1);
			}
		}
}


			

		
int main()
{
	while(cin>>row>>col)
	{
		if(row==0&&col==0)	break;
		if(col<row)	{int temp=row;row=col;col=temp;}
		if(row*col%2==1)	{cout<<"0"<<endl;continue;}
		int flag[11];
		for(int i=0;i<col;i++)	flag[i]=0;
		total=0;
		search(flag,1);		
		cout<<total<<endl;
	}
	return 0;
}
