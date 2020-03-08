 #include<iostream.h>

 int main()
 {
	int amount=0;
	while(1)
	{
		int nn;cin>>nn;
		if(nn==0) break;
		int a[7];char str[3];int i;
		for(i=0;i<nn;i++)
		{
			cin>>str;a[i]=str[1]-48;
		}

		int val[7];char ter_val[130];
		int end=1;
		for(i=0;i<nn;i++) end*=2;
		for(i=0;i<end;i++) cin>>ter_val[i];
		int n;cin>>n;
		cout<<"S-Tree #"<<(++amount)<<":"<<endl;
		for(i=0;i<n;i++)
		{
			int j;char ch;
			for(j=0;j<nn;j++) {	cin>>ch;val[j]=ch-48;}
			int pt=0;int ini=end/2;
			for(j=0;j<nn;j++)
			{      pt+=ini*val[a[j]-1];
			       ini/=2;
			}
			cout<<(int)(ter_val[pt]-48);
		}
		cout<<endl<<endl;
	}
	return 0;
 }

