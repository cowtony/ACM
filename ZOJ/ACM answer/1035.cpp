//253099 2003-08-12 21:42:25 Wrong Answer 1035 C++ 00:00.17 436K just for play 
//253142 2003-08-12 21:59:06 Wrong Answer 1035 C++ 00:00.12 440K just for play 
//253190 2003-08-12 22:24:40 Wrong Answer 1035 C++ 00:00.14 440K just for play 
#include<stdio.h>
#include<iostream.h>
#include<string.h>

struct CUBE
{
	int a[6][6];
};
	
CUBE cube[6];
bool has_put[6];
int cube_at[6];
int angle[8];

int convert(char ch)
{
	if(ch=='X')	return 1;
	else if(ch=='.')	return 0;
	else return -1;
}

bool input()
{
	bool result=true;
	int i,j,t;char ch;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			for(t=0;t<6;t++)
			{
				cin>>ch;
				cube[j].a[i][t]=convert(ch);
			}
			cin>>ch;
		}
	}

	for(i=0;i<6;i++)	
		for(j=1;j<5;j++)
			for(t=1;t<5;t++)
				if(cube[i].a[j][t]==0){result=false;goto out_break;}

	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)	if(cube[i].a[0][j]==1)	break;
		if(j<6)	continue;
		for(j=0;j<6;j++)	if(cube[i].a[5][j]==1)	break;
		if(j<6)	continue;
		for(j=0;j<6;j++)	if(cube[i].a[j][0]==1)	break;
		if(j<6)	continue;
		for(j=0;j<6;j++)	if(cube[i].a[j][5]==1)	break;
		if(j<6)	continue;
		break;
	}
	if(i<6)	result=false;		

out_break:
	return result;
}

void get_num(int store[],int cubept,int pt)
{
	int i;
	switch(pt)
	{
	case 0:	for(i=0;i<6;i++)	store[i]=cube[cubept].a[0][i];break;
	case 1: for(i=0;i<6;i++)	store[i]=cube[cubept].a[i][5];break;
	case 2: for(i=0;i<6;i++)	store[i]=cube[cubept].a[5][i];break;
	case 3: for(i=0;i<6;i++)	store[i]=cube[cubept].a[i][0];break;
	}
}
bool can_place(int fir,int firpt,int sec,int secpt)
{
	int num[2][6];
	get_num(num[0],fir,firpt);
	get_num(num[1],sec,secpt);
	int i;
// the second modification
	if((firpt==0&&secpt==1)||(firpt==2&&secpt==3))
	{
		for(i=1;i<5;i++)
			if(num[0][i]+num[1][5-i]!=1)	return false;
	}
//end
	else
	{
		for(i=1;i<5;i++)	
			if(num[0][i]+num[1][i]!=1)	return false;
	}
	return true;
}
bool can_put(int cur,int lev)
{
	switch(lev)
	{
	case 1:
		if(!can_place(cur,2,0,0))	return false;
		
		angle[0]=cube[0].a[0][0]+cube[cur].a[5][0];
		angle[1]=cube[0].a[0][5]+cube[cur].a[5][5];
		if(angle[0]>1||angle[1]>1)	return false;

		return true;
	case 2:
		if(!can_place(cur,3,0,1))	return false;
		if(!can_place(cur,0,cube_at[1],1))	return false;								

		angle[1]=cube[0].a[0][5]+cube[cube_at[1]].a[5][5]+cube[cur].a[0][0];
		angle[2]=cube[0].a[5][5]+cube[cur].a[5][0];
		angle[5]=cube[cube_at[1]].a[0][5]+cube[cur].a[0][5];
		if(angle[1]!=1||angle[2]>1||angle[5]>1)	return false;

		return true;	
	case 3:
		if(!can_place(cur,0,0,2))	return false;
		if(!can_place(cur,1,cube_at[2],2))	return false;						

		angle[2]=cube[0].a[5][5]+cube[cube_at[2]].a[5][0]+cube[cur].a[0][5];
		angle[3]=cube[0].a[5][0]+cube[cur].a[0][0];
		angle[6]=cube[cur].a[5][5]+cube[cube_at[2]].a[5][5];
		if(angle[2]!=1||angle[3]>1||angle[6]>1)	return false;

		return true;	
	case 4:
		if(!can_place(cur,1,0,3))	return false;
		if(!can_place(cur,2,cube_at[3],3))	return false;		
		if(!can_place(cur,0,cube_at[1],3))	return false;

		angle[0]=cube[0].a[0][0]+cube[cube_at[1]].a[5][0]+cube[cur].a[0][5];
		angle[3]=cube[0].a[5][0]+cube[cube_at[3]].a[0][0]+cube[cur].a[5][5];
		angle[7]=cube[cur].a[5][0]+cube[cube_at[3]].a[5][0];
		angle[4]=cube[cur].a[0][0]+cube[cube_at[1]].a[0][0];
		if(angle[0]!=1||angle[3]!=1||angle[7]>1||angle[4]>1)	return false;

		return true;
	case 5:
		if(!can_place(cur,0,cube_at[1],0))	return false;
		if(!can_place(cur,1,cube_at[2],1))	return false;		
		if(!can_place(cur,2,cube_at[3],2))	return false;		
		if(!can_place(cur,3,cube_at[4],3))	return false;		

		angle[4]=cube[cur].a[0][0]+cube[cube_at[1]].a[0][0]+cube[cube_at[4]].a[0][0];
		angle[5]=cube[cur].a[0][5]+cube[cube_at[1]].a[0][5]+cube[cube_at[2]].a[0][5];
		angle[6]=cube[cur].a[5][5]+cube[cube_at[2]].a[5][5]+cube[cube_at[3]].a[5][5];
		angle[7]=cube[cur].a[5][0]+cube[cube_at[3]].a[5][0]+cube[cube_at[4]].a[5][0];
		if(angle[4]!=1||angle[5]!=1||angle[6]!=1||angle[7]!=1)	return false;

		return true;	
	}
	return false;
}


void rotate(int cur)
{
	int temp[6],i;
	for(i=0;i<6;i++)	temp[i]=cube[cur].a[0][i];
	for(i=0;i<6;i++)	cube[cur].a[0][i]=cube[cur].a[i][5];
	for(i=0;i<6;i++)	cube[cur].a[i][5]=cube[cur].a[5][5-i];
	for(i=0;i<6;i++)	cube[cur].a[5][i]=cube[cur].a[i][0];
	for(i=0;i<6;i++)	cube[cur].a[i][0]=temp[5-i];
}
void overturn(int cur)
{
	int temp[6],i,t;
	for(i=0;i<6;i++)	temp[i]=cube[cur].a[0][i];
	for(i=0;i<6;i++)	cube[cur].a[0][i]=cube[cur].a[5][i];
	for(i=0;i<6;i++)	cube[cur].a[5][i]=temp[i];
//the first modification
	for(i=1;i<3;i++)
	{	
		t=cube[cur].a[i][0];cube[cur].a[i][0]=cube[cur].a[5-i][0];
		cube[cur].a[5-i][0]=t;
		t=cube[cur].a[i][5];cube[cur].a[i][5]=cube[cur].a[5-i][5];
		cube[cur].a[5-i][5]=t;

	}
//end	
	
}
/*
void output(int cur)
{
	int j,t;
	for(j=0;j<6;j++)	
		{
			for(t=0;t<6;t++)
				printf("%d",cube[cur].a[j][t]);
			printf("\n");
		}
		printf("\n");
}
*/
bool search(int lev)
{
	if(lev==6)	return true;
	int i,j,t;
	for(i=1;i<6;i++)
	{
		if(has_put[i])	continue;
		for(t=0;t<2;t++)
		{
			for(j=0;j<4;j++)
			{
				if(can_put(i,lev))
				{

					has_put[i]=true;
					cube_at[lev]=i;
					if(search(lev+1))	return true;					
					has_put[i]=false;
				}				

				if(j<3)	rotate(i);
			}
			if(t==0)	overturn(i);
		}
	}
	return false;
}

int main()
{
//	freopen("1035.in","r",stdin);
//	freopen("1035.out","w",stdout);
	int nn,i;
	cin>>nn;
	for(i=1;i<=nn;i++)
	{
		printf("Scenario #%d:\n",i);
		if(!input()){printf("No\n\n");continue;}
		memset(has_put,false,sizeof(has_put));
		memset(angle,0,sizeof(angle));
		has_put[0]=true;cube_at[0]=0;
		if(search(1))	printf("Yes\n");
		else printf("No\n");
		printf("\n");

	}
	return 0;
}

