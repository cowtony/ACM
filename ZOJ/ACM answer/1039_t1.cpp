 //83109 2003-03-05 12:49:53 Wrong Answer 1039 C++ 00:00.12 2368K Century Ghost
 //83162 2003-03-05 13:43:24 Memory Limit Exceeded 1039 C++ 00:01.07 33176K Century Ghost
 //83171 2003-03-05 14:01:26 Time Limit Exceeded 1039 C++ 00:30.00 436K Century Ghost


 #include<iostream.h>


 int a_num;
 int search(int a[],int flag[],int k,int lev)
 {

	int i,j;int changed_num=1;
	int changed[21];
	changed[0]=k;
	int pt=0;
	while(1)
	{
		if(changed_num==pt)	break;
		j=changed[pt];
		for(i=2;i<21;i++)
		{
			if(a[i])
			{
				if((i>j&&a[i-j]==0)||i%j==0)
				{	changed[changed_num++]=i;a[i]=0;}
			}
		}
		pt++;

	 }
	for(i=2;i<21;i++)	if(a[i])	break;
	if(i==21){
		for(j=0;j<changed_num;j++)	a[changed[j]]=1;
		flag[k]=1;return 1;}
	for(i=2;i<21;i++)
	{
		if(a[i])
		{
			a[i]=0;
			if(!search(a,flag,i,lev+1)){a[i]=1;	break;}
			a[i]=1;
		}
	}
	for(j=0;j<changed_num;j++)	a[changed[j]]=1;
	if(i<21){flag[k]=1;return 1;}
	flag[k]=0;
	return 0;
 }








 int main()
 {
	int tt;int i;


	cin>>tt;     int a[21];int flag[21];
	for(i=1;i<=tt;i++)
	{
		int j;
		cin>>a_num;
		for(j=2;j<=20;j++)	flag[j]=0;
		int temp;
		for(j=1;j<=a_num;j++)
		{cin>>a[j-1];}
		int can_be[21];
		for(j=2;j<21;j++)	can_be[j]=0;
		for(j=0;j<a_num;j++)
			{   for(int t=2;t<=20;t++)	flag[t]=0;
				int temp=a[j];
				a[j]=a[a_num-1];a_num--;
				search(a,flag,j,1);
				if(flag[j]) can_be[j]=1;
				a_num++;
				a[a_num]=a[j];a[j]=temp;
			}
		
		cout<<"Scenario #"<<i<<":"<<endl;
		for(j=2;j<21;j++)	if(can_be[j])	break;
		if(j<21)
		{
			cout<<"The winning moves are:";
			for(int t=2;t<21;t++)
				if(can_be[t])
					cout<<" "<<t;
			cout<<"."<<endl;
		}
		else	cout<<"There is no winning move."<<endl;

		cout<<endl;
	}
	return 0;
 }
