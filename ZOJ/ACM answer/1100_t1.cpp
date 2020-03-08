#include<iostream.h>
int row,col;
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
	{	flag[move->rr][move->cc]=0;
		link* temp=move;
		move=move->next;
		delete temp;
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
link* extend(link* changed,int x,int y,int& canextend)
{
//	if((y==col-2&&!flag[x][y+1])||(y<col-2&&!flag[x][y+1]&&flag[x][y+2]))
  //	{
    //		if(x==row-1){	canextend=0;return changed;}
      //		changed=add(changed,x,y+1);
	//	changed=add(changed,x+1,y+1);
	  //	flag[x][y+1]=1;flag[x+1][y+1]=1;
	    //	changed=extend(changed,x+1,y+1,canextend);
	      //	if(!canextend)	return changed;
//	}
	if((y==1&&!flag[x][y-1])||(y>1&&!flag[x][y-1]&&flag[x][y-1]))
	{
		if(x==row-1){canextend=0;return changed;}
		changed=add(changed,x,y-1);
		changed=add(changed,x+1,y-1);
		flag[x][y-1]=1;flag[x+1][y-1]=1;
		changed=extend(changed,x+1,y-1,canextend);
		if(!canextend)	return changed;
	}
	return changed;
}





void search(int x,int y,int lev)
{
//	cout<<x<<"=="<<y<<"===="<<lev<<endl;
	int i,j;
	if(y+1<col&&flag[x][y+1]==0)
	{	link* changed=NULL;
		changed=add(changed,x,y);
		changed=add(changed,x,y+1);
		flag[x][y]=1;flag[x][y+1]=1;
		int canextend=1;
		if((y+1==col-2&&!flag[x][y+2])||(y+1<col-2&&flag[x][y+3]&&!flag[x][y+2]))
		{
			if(x+1>=row)	canextend=0;
			else
			{
				changed=add(changed,x,y+2);
				changed=add(changed,x+1,y+2);
				flag[x][y+2]=1;flag[x+1][y+2]=1;
			}
		}
		if(canextend)	changed=extend(changed,x+1,y+2,canextend);

  //		link* move=changed;
    //		while(move!=NULL)
      //		{
	      //		cout<<move->rr<<"  "<<move->cc<<"------";
	//		move=move->next;
	  //	}
	    //	cout<<endl;
		if(!canextend)	recover(changed);
		else
		{
			int nextx,nexty;
			calnext(x,y,nextx,nexty);
			if(nextx==-1&&nexty==-1)	count++;
			else search(nextx,nexty,lev+1);
			recover(changed);
		}
	}
//	cout<<x<<"------>>>"<<y<<"--->"<<lev<<endl;
  //	for(i=0;i<row;i++)
    //		for( j=0;j<col;j++)	cout<<flag[i][j]<<" ";
      //	cout<<endl;

	if(x+1<row&&!flag[x+1][y])
	{
		link* changed=NULL;
		changed=add(changed,x,y);
		changed=add(changed,x+1,y);
		flag[x][y]=1;flag[x+1][y]=1;
		int canextend=1;
		if((y==col-2&&!flag[x][y+1])||(y<col-2&&flag[x][y+2]&&!flag[x][y+1]))
		{
			if(x+1>=row)	canextend=0;
			else
			{
				changed=add(changed,x,y+1);
				changed=add(changed,x+1,y+1);
				flag[x][y+1]=1;flag[x+1][y+1]=1;
			}
		}

		changed=extend(changed,x+1,y,canextend);

	//	link* move=changed;
	  //	while(move!=NULL)
	    //	{
	      //		cout<<move->rr<<"  "<<move->cc<<"------";
		//	move=move->next;
	       //	}
	       //	cout<<endl;

		if(!canextend)	recover(changed);
		else
		{
			int nextx,nexty;
			calnext(x,y,nextx,nexty);
			if(nextx==-1&&nexty==-1)	count++;
			else search(nextx,nexty,lev+1);
			recover(changed);
		}
	}
}








int main()
{
	while(cin>>row>>col)
	{
		if(row==0&&col==0)	break;
		if(row*col%2==1)	{cout<<"0"<<endl;continue;}
		int i,j;count=0;
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)	flag[i][j]=0;
		search(0,0,1);
		cout<<count<<endl;
	}
	return 0;
}
