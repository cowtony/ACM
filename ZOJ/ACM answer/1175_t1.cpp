 #include<iostream.h>
 #include<string.h>

 char input[5000];
 char output[5000];
 int main()
 {
	int n;
	cin>>n;
	while(n--)
	{
		int line;int inpt=0,outpt=0;
		cin>>line;
		cin.get();
		char buffer;
		while(line)
		{

			while(1)
			{       cin.get(buffer);
				if(buffer=='\n')	break;
				input[inpt++]=buffer;
			}
			line--;
		}
		int getpt=0;
		while(cin.get(buffer))
		{
			if(buffer=='#')	break;
			if(buffer=='G')
				output[outpt++]=input[getpt++];
			if(buffer=='R')
			{
				int beg=getpt;int end=inpt-1;
				while(beg<end)
				{
					char temp=input[beg];
					input[beg++]=input[end];
					input[end--]=temp;
				}
			}
		}
		for(int i=0;i<outpt;i++)
		{       if(i%80==0)	cout<<endl;
			cout<<output[i];
		}
		cout<<endl;
	}
 }
