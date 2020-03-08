//86793 2003-03-11 23:38:25 Accepted 1100 C++ 00:00.39 636K Century Ghost 
#include<iostream.h>
#include<stdio.h>

int row,col;
double flag[2048][12];
int max;
int andnum[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
int cannum[2048];
int getnum(int num,int k)
{
	return (andnum[k]&num);
}
int can(int num)
{
	int total=0;
	int i;
	for(i=0;i<col;i++)
	{
		if(getnum(num,i))
		{
			if(total%2==1)	return 0;
			total=0;
		}
		else	total++;
	}
	if(total%2==1)	return 0;
	return 1;
}
		
		


double search(int num,int lev)
{

	if(flag[num][lev-1]!=-1)	return flag[num][lev-1];
	if(lev==row)
	{
		if(cannum[num])	flag[num][lev-1]=1;
		else	flag[num][lev-1]=0;
		return flag[num][lev-1];
	}
	double count=0;
	int i;
	for(i=0;i<max;i++)
	{
		if(i&num)	continue;
		int tempnum=i|num;
		if(!cannum[tempnum])	continue;
		count+=search(i,lev+1);
	}
	flag[num][lev-1]=count;
	return count;
}
	
int main()
{
	
	
	while(cin>>row>>col)
	{	

		if(row==0&&col==0)	break;
		if((row*col)%2==1)	{cout<<"0"<<endl;continue;}
		if(row>col){int temp=row;row=col;col=temp;}
		for(int t=0;t<2048;t++)
		{	
			if(can(t))	cannum[t]=1;
			else	cannum[t]=0;
		}
		int i,j;
		max=1;
		for(i=0;i<col;i++)	max*=2;
		for(i=0;i<2048;i++)
			for(j=0;j<12;j++)	flag[i][j]=-1;
		search(0,1);
		printf("%.0lf\n",flag[0][0]);
		
	}
	return 0;
}

