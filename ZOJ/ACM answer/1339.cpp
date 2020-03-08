 //55095 2002-11-20 13:18:05 Accepted 1339 C++ 00:00.00 432K Century Ghost
 #include<iostream.h>
 int main()
 {
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)	break;
		int i;int a[15];int j;
		cin.get();
		for(i=0;i<n;i++)
		{


			int add=0;char ch;
			for(j=0;j<25;j++)
			{	cin.get(ch);
				if(ch=='X')	add++;
			}

			a[i]=add;
			cin.get();
		}
		int max=0;
		for(i=0;i<n;i++)
			if(a[i]>max)	max=a[i];
		int sum=0;
		for(i=0;i<n;i++)	sum+=(max-a[i]);
		cout<<sum<<endl;
	}
	return 0;
 }




