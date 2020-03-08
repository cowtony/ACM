 #include<iostream.h>

 int main()
 {
	int m,n;int count=0;
	while(1)
	{
		cin>>m>>n;
		if(m==0)	break;
		count++;
		cout<<"Hole #"<<count<<endl;
		if(m==n)	cout<<"Par";
		else if(m==n+1)	cout<<"Bridie";
		else if(m==n+2)	cout<<"Hole-in-one";
		else if(m>=n+3) cout<<"Double eagle";
		else if(m+1==n) cout<<"Bogey";
		else if(m+2<=n) cout<<"Double Bogey";
		cout<<"."<<endl<<endl;
	}
	return 0;
 }

