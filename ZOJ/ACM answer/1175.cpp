 //61698 2002-12-07 13:51:40 Accepted 1175 C++ 00:00.02 532K Century Ghost
 #include<iostream.h>
 #include<stdio.h>
 #include<string.h>

 int main()
 {
	int n;
	cin>>n;int tt=0;
	while(n--)
	{
		if(tt)	cout<<endl;
		tt=1;

		 char input[50000];
		 char output[50000];

		int line;long inpt=0,outpt=0;
		cin>>line;
		cin.get();
		char buffer;
		while(line)
		{
			while(1)
			{       cin.get(buffer);
				if(buffer=='\n')	break;
				input[inpt++]=buffer;
			}line--;
		}


		long begpt=0;long endpt=inpt-1;int flag=0;
		while(cin.get(buffer))
		{
			if(buffer=='#')	break;
			if(buffer=='G')
			{       if(flag==0)
					output[outpt++]=input[begpt++];
				else output[outpt++]=input[endpt--];
			}
			if(buffer=='R'){
				if(flag==0)	flag=1;
				else flag=0;
			}
		}
		long i;
		for(i=0;i<outpt;i++)
		{	if(i!=0&&i%80==0)	cout<<endl;
			cout<<output[i];
		}
		cout<<endl;
	}
	return 0;
 }
