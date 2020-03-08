 #include<iostream.h>


 int divide(int a[],int t)
 {
	int i;
	for(i=1;i<=6;i++)	if(a[i]<0) return 0;
	int left=a[t]-2*(a[t]/2);
	if(t==1)
	{ 	if(left) return 0;
		else return 1;
	}
	if(left==0)
	{
		if( divide(a,t-1)) return 1;
		else return 0;
	}
	if(t==6)
	{
		a[1]-=6;if(divide(a,t-1)) return 1;a[1]+=6;
		a[1]-=4;a[2]--;if(divide(a,t-1)) return 1;a[1]+=4;a[2]++;
		a[1]-=3;a[3]--;if(divide(a,t-1)) return 1;a[1]+=3;a[3]++;
		a[1]-=2;a[4]--;if(divide(a,t-1)) return 1;a[1]+=2;a[4]++;
		a[1]-=2;a[2]-=2;if(divide(a,t-1)) return 1;a[1]+=2;a[2]+=2;
		a[1]--;a[2]--;a[3]--;if(divide(a,t-1)) return 1;a[1]++;a[2]++;a[3]++;
		a[1]--;a[5]--;if(divide(a,t-1)) return 1;a[1]++;a[5]++;
		a[2]--;a[4]--;if(divide(a,t-1)) return 1;a[2]++;a[4]++;
		a[2]-=3;if(divide(a,t-1)) return 1;a[2]+=3;
		a[3]-=2;if(divide(a,t-1)) return 1;a[3]+=2;
		return 0;
	}
	if(t==5)
	{
		a[1]-=5;if(divide(a,t-1)) return 1;a[1]+=5;
		a[1]-=3;a[2]--;if(divide(a,t-1)) return 1;a[1]+=3;a[2]++;
		a[1]-=2;a[3]--;if(divide(a,t-1)) return 1;a[1]+=2;a[3]++;
		a[1]--;a[4]--;if(divide(a,t-1)) return 1;a[1]++;a[4]++;
		a[1]--;a[2]-=2;if(divide(a,t-1)) return 1;a[1]++;a[2]+=2;
		a[2]--;a[3]--;if(divide(a,t-1)) return 1;a[2]++;a[3]++;
		return 0;
	}
	if(t==4)
	{
		a[1]-=4;if(divide(a,t-1)) return 1;a[1]+=4;
		a[1]-=2;a[2]--;if(divide(a,t-1)) return 1;a[1]+=2;a[2]++;
		a[1]--;a[3]--;if(divide(a,t-1)) return 1;a[1]++;a[3]++;
		a[2]-=2;if(divide(a,t-1)) return 1;a[2]+=2;
		return 0;
	}
	if(t==3)
	{
		a[1]-=3;if(divide(a,t-1)) return 1;a[1]+=3;
		a[1]--;a[2]--;if(divide(a,t-1)) return 1;a[1]++;a[2]++;
		return 0;
	}
	if(t==2)
	{	a[1]-=2;if(divide(a,t-1)) return 1;a[1]+=2;
		return 0;
	}
	return 0;

 }
 int main()
 {
	int amount=0;
	while(1)
	{
		int i;
		int a[7];
		for(i=1;i<=6;i++)	cin>>a[i];
		if(!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]&&!a[6]) break;
		int can=0;
		can=divide(a,6);
		cout<<"Collection #"<<(++amount)<<":"<<endl;
		if(can) cout<<"Can be divided."<<endl;
		else cout<<"Can't be divided."<<endl;
		cout<<endl;
	}
	return 0;
 }

