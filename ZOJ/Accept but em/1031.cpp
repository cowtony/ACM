//238097 2003-08-04 20:15:10 Time Limit Exceeded 1031 C++ 00:10.00 380K just for play 
#include<stdio.h>
#include<string.h>
int moved[61];
int Size;

int check_complete(int UpLeft,int CurSize)
{
	int i;
	for(i=UpLeft;i<UpLeft+CurSize;i++)	
		if(moved[i]==1)	return 0;	
	for(i=UpLeft+Size;i<UpLeft+CurSize*Size+CurSize*(Size+1);i+=2*Size+1)			
		if(moved[i]==1)	return 0;	
	for(i=UpLeft+CurSize*Size+CurSize*(Size+1);i<UpLeft+CurSize*Size+CurSize*(Size+1)+CurSize;i++)			
	{
//		printf("%d ---- \n",i);
		if(moved[i]==1)	return 0;
	}
	for(i=UpLeft+Size+CurSize;i<UpLeft+CurSize*Size+CurSize*(Size+1);i+=2*Size+1)
	{
		//printf("%d ---- \n",i);
		if(moved[i]==1)	return 0;
	}
	return 1;
}

int check_size(int CurSize)
{
	int i=1;
	int CurEnd=Size;
	while(1)
	{
		
		if(i+CurSize-1<=CurEnd)	
		{
			if(i+CurSize*Size+CurSize*(Size+1)>2*Size*(Size+1))
				break;
/*
			int j;
			for(j=1;j<=2*Size*(Size+1);j++)
				if(moved[j]==1)	printf("%d ",j);
			printf("  size  %d ",CurSize);
			printf("  --> %d \n",i);
*/
			if(check_complete(i,CurSize))	return 1;
		}
		if(i==CurEnd)
		{
			i+=Size+1+1;
			CurEnd=i+Size-1;
		}
		else	i++;
	}
	return 0;
}

	
int Check()
{
	int i;
	for(i=1;i<=Size;i++)
		if(check_size(i))	return 0;
	return 1;
}

int RecMove(int CurStick,int CurMov,int ToMov)
{
	if(CurMov==ToMov)	
	{
		if(Check())	return 1;
		return 0;
	}
	int i,j;
	for(i=CurStick+1;i<=2*Size*(Size+1);i++)
	{
		if(moved[i]==1)	continue;
		moved[i]=1;
		if(RecMove(i,CurMov+1,ToMov))	return 1;
		moved[i]=0;
	}
	return 0;
}


int try_move(int num)
{
	int i,j;
	for(i=1;i<=2*Size*(Size+1);i++)
	{
		if(moved[i]==1)	continue;
		moved[i]=1;
		if(RecMove(i,1,num))	return 1;
		moved[i]=0;
	}
	return 0;
}
		
		
			
int main()
{
//	freopen("1031.in","r",stdin);
//	freopen("1031.out","w",stdout);
	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
		int n,i,j,t;
		scanf("%d %d",&Size,&n);
		memset(moved,0,sizeof(moved));
		for(i=0;i<n;i++)
		{scanf("%d",&t);moved[t]=1;}
		for(i=1;;i++)
		{
	//		printf("%d --\n",i);
			if(try_move(i))	break;
		}
		printf("%d\n",i);
		;
	}
	return 0;
}

		

