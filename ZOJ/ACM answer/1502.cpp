//89944 2003-03-16 15:46:04 Accepted 1502 C++ 00:00.08 752K Century Ghost 
#include<stdio.h>
#include<math.h>
#include<vector>

//#include<fstream.h>
//ofstream fout;
using namespace std;
struct plug
{
	int from,to;
};
struct point
{	
	int row,col;
};
	int size;int vectorsize;
	int curflag[101][101];int orgflag[101][101];
	point place[10001];
	vector<plug>input;
void rotate()
{
	int i,j;
	for(i=1;i<=size;i++)
		for(j=1;j<=size;j++)
			curflag[i][j]=orgflag[j][size-i+1];
}
void reverse()
{
	int i,j;
	for(i=1;i<=size;i++)
		for(j=1;j<=size;j++)
			curflag[i][j]=orgflag[i][size-j+1];
}
/*
void output()
{
	int i,j;
	for(i=1;i<=size;i++)
	{	fout<<endl;
		for(j=1;j<=size;j++)
			fout<<curflag[i][j]<<" ";
	}
	fout<<endl;
}
*/
long cal_dis()
{
	int i;long temp=0;
	for(i=0;i<vectorsize;i++)
	{
		int tempfrom=input[i].from;
		int tempto=input[i].to;

		temp+=abs((tempfrom-1)/size+1-place[tempto].row)+abs((tempfrom-1)%size+1-place[tempto].col);
	}

	return temp;
}




int main()
{//	fout.open("temp.txt");
	int count=0;
	while(scanf("%d",&size)!=EOF)
	{
		if(size==0)	break;
		if(count) printf("\n");
		count++;
		scanf("%d",&vectorsize);
		input.clear();
		int i,j;
		for(i=0;i<vectorsize;i++)
		{
			plug temp;
			scanf("%d%d",&temp.from,&temp.to);
			input.push_back(temp);
		}
		for(i=1;i<=size;i++)
			for(j=1;j<=size;j++)			
				curflag[i][j]=(i-1)*size+j;							
		long total=-1;int t;
		for(int tt=0;tt<2;tt++)
		{
			for(t=0;t<4;t++)
			{
				for(i=1;i<=size;i++)
					for(j=1;j<=size;j++)
					{
						orgflag[i][j]=curflag[i][j];
						place[curflag[i][j]].row=i;
						place[curflag[i][j]].col=j;
					}
//				output();
				long curtotal=cal_dis();
//				fout<<curtotal<<endl;
				if(total==-1||curtotal<total)	total=curtotal;
				rotate();
			}
			reverse();
		}
		total+=vectorsize;
		double avg=total*1.0/vectorsize;
		printf("Scenario %d: smallest average = %.4lf\n",count,avg);
	}
	return 0;
}





