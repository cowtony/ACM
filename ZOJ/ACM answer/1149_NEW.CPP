 #include<iostream.h>
 void change(int a[])
 {
	int i;
	for(i=1;i<=6;i++)
	{
		if(a[i]>20)
		{	 if((a[i]-20)%2) a[i]=21;
			else a[i]=20;
		}
	}
 }
 int divide(int a[],long sum)
 {
	int i,j,k,l,m,n;long half=sum/2;

	for(i=0;i<=a[6];i++)
	{

		long temp_sum=i*6;
		if(temp_sum>half) break;
		for(j=0;j<=a[5];j++)
		{

			temp_sum+=j*5;
			if(temp_sum>half) break;

			for(k=0;k<=a[4];k++)
			{
				temp_sum+=k*4;
				if(temp_sum>half) break;
				for(l=0;l<=a[3];l++)
				{

					temp_sum+=l*3;
					if(temp_sum>half) break;
					for(m=0;m<=a[2];m++)
					{       temp_sum+=m*2;
						if(temp_sum>half) break;
						for(n=0;n<=a[1];n++)
						{
							temp_sum+=n;
							if(temp_sum==half) return 1;
							if(temp_sum>half) break;
							temp_sum-=n;
						}
						temp_sum-=m*2;
					}
					temp_sum-=l*3;

				}
				temp_sum-=k*4;

			}
			temp_sum-=j*5;

		}
		temp_sum-=i*6;

	}
	return 0;
 }




 int main()
 {
	int amount=0;
	while(1)
	{
		int i;
		int a[7]; long sum=0;
		for(i=1;i<=6;i++){	cin>>a[i];sum+=a[i]*i;}
		if(!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]&&!a[6]) break;
		int can=0;
		if(sum%2==0) {
			change(a);
			sum=0;
			for(i=1;i<=6;i++) sum+=a[i]*i;
			can=divide(a,sum);
		}
		cout<<"Collection #"<<(++amount)<<":"<<endl;
		if(can) cout<<"Can be divided."<<endl;
		else cout<<"Can't be divided."<<endl;
		cout<<endl;
	}

	return 0;
 }
