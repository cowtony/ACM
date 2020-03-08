 //54897 2002-11-19 23:43:25 Accepted 1342 C++ 00:00.01 432K Century Ghost
 #include<iostream.h>
 #include<string.h>

 char str[6];int count=0;

 long cal(int t,int len,int k)
 {

	if(k==len)
	{       long res;
		if(count==len-1)	res=str[k-1]-t-96;
		else	res=26-t;
		if(res<0)	res=0;
		return res;
	}
	long sum=0;int i;int pt;
	if(count==k-1)	pt=str[k-1]-96;
	else	pt=26;
	for(i=t+1;i<=pt;i++)
	{	if(count==k-1&&i==pt)	count++;
		sum+=cal(i,len,k+1);
		if(count==k-1&&i==pt) 	count--;
	}
	return sum;
 }


 int main()
 {
	int i,j;long a[4]={26,325,2600,14950};
	while(cin>>str)
	{
		count=0;
		int len=strlen(str);int flag=0;
		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len;j++)
				if(str[i]>=str[j]){flag=1;break;}
			if(flag)	break;
		}
		long sum=0;
		if(flag) sum=0;
		else{
			for(i=0;i<len-1;i++)	sum+=a[i];
			sum+=cal(0,len,1);
		}
		cout<<sum<<endl;
	}
	return 0;
 }


