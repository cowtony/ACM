 //1243.cpp

 #include<iostream.h>
 #include<string.h>
 int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char str[100];
		cin>>str;

		int from1=0,to1=0,from2=0,to2=0,from3=0,to3=0,from4=0,to4=0;
		int len=strlen(str);
		for(int j=0;j<len;j++){
			if(to1==0&&str[j]==':') {to1=j-1;from2=j+3;}
			if(to1+3<j&&str[j]==':'){to2=j-1;from3=j+1;}
			if(str[j]=='/'&&j>from2){if(from3!=0) to3=j-1;
									else to2=j-1;
									from4=j+1;to4=len-1;break;}

		}

		if(from3==0&&from4==0) to2=len-1;
		if(from3!=0&&from4==0) to3=len-1;
		int t;
		cout<<"URL #"<<i<<endl;
		cout<<"Protocol = ";



		for(t=from1;t<=to1;t++) cout<<str[t];
		cout<<endl;
		cout<<"Host     = ";
		for(t=from2;t<=to2;t++) cout<<str[t];
		cout<<endl;



		cout<<"Port     = ";
		if(from3==0)   cout<<"<default>";
		else{for(t=from3;t<=to3;t++) cout<<str[t];}
		cout<<endl;
		cout<<"Path     = ";
		if(from4==0) cout<<"<default>";
		else {for(t=from4;t<=to4;t++) cout<<str[t];}
		cout<<endl<<endl;
	}
	return 0;
 }

















