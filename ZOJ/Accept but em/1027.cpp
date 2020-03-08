 //80860 2003-03-01 19:59:26 Time Limit Exceeded 1027 C++ 00:30.00 436K Century Ghost
 //80866 2003-03-01 20:08:07 Accepted 1027 C++ 00:00.01 520K Century Ghost
 #include<iostream.h>

 int val[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},
		{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
 int fir[101],sec[101];
 int visit[101][101];
 int flag[101][101];
 int match(int len1,int len2)
 {
	if(flag[len1][len2])	return visit[len1][len2];
	int i;
	if(len1==0)
	{
		int total=0;
		for(i=0;i<len2;i++)	total+=val[4][sec[i]];
		flag[len1][len2]=1;visit[len1][len2]=total;
		return total;
	}
	if(len2==0)
	{
		int total=0;
		for(i=0;i<len1;i++)	total+=val[fir[i]][4];
		flag[len1][len2]=1;visit[len1][len2]=total;
		return total;
	}
	int max;int temp;
	max=val[fir[len1-1]][sec[len2-1]]+match(len1-1,len2-1);
	temp=val[fir[len1-1]][4]+match(len1-1,len2);
	if(temp>max)	max=temp;
	temp=val[4][sec[len2-1]]+match(len1,len2-1);
	if(temp>max)	max=temp;
	flag[len1][len2]=1;visit[len1][len2]=max;
	return max;
 }

 int main()
 {
	int n;
	cin>>n;
	while(n--)
	{
		int len1,len2;int i;
		cin>>len1;char ch;
		for(i=0;i<len1;i++)
		{	cin>>ch;
			if(ch=='A')	fir[i]=0;
			else if(ch=='C')	fir[i]=1;
			else if(ch=='G')	fir[i]=2;
			else if(ch=='T')	fir[i]=3;
		}
		cin>>len2;
		for(i=0;i<len2;i++)
		{	cin>>ch;
			if(ch=='A')	sec[i]=0;
			else if(ch=='C')	sec[i]=1;
			else if(ch=='G')	sec[i]=2;
			else if(ch=='T')	sec[i]=3;
		}
		int j;
		for(i=0;i<=len1;i++)
			for(j=0;j<=len2;j++)
				flag[i][j]=0;
		cout<<match(len1,len2)<<endl;
	}
	return 0;

 }