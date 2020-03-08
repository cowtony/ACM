 #include<iostream.h>

 int main(){
	int n;
	cin>>n; int amount=0;
	while(n!=0){
		amount++;

		int a[27];
		a[1]=1;int i;
		for(i=2;i<27;i++) a[i]=0;
		for(i=0;i<n;i++){
			char ch1,ch2,ch3;
			cin>>ch1>>ch2>>ch3;
			if(a[ch3-96]==1) a[ch1-96]=1;
			else a[ch1-96]=0;



		}
		cout<<"Program #"<<amount<<endl;
		int flag=0;



		for(i=1;i<27;i++)
			if(a[i]==1){
				flag=1;
				char ch;
				ch=i+96;

				cout<<ch<<" ";

		}
		if(flag==0) cout<<"none";
		cout<<endl<<endl;
		cin>>n;
	}
	return 0;
 }


