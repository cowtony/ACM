 //accepted

 #include<iostream.h>



 int main(){
	int n;
	cin>>n;
	while(n!=0){
		int blank,sheet;
		cout<<"Printing order for "<<n<<" pages:"<<endl;

		if(n%4==0){blank=0;sheet=n/4;}
		else{blank=4-n%4;sheet=n/4+1;}
		if(n==1){cout<<"Sheet 1, front: Blank, 1"<<endl;}
		else{
		int i;int flag=0;int ptr=1;
		for(i=1;i<=sheet;i++){
			cout<<"Sheet "<<i<<", front: ";
			if(blank==0) flag=1;
			if(flag==0){cout<<"Blank, ";blank--;}
			else {cout<<n<<", ";n--;}
			cout<<ptr<<endl;ptr++;
			cout<<"Sheet "<<i<<", back : ";
			cout<<ptr<<", ";ptr++;
			if(blank==0) flag=1;
			if(flag==0){cout<<"Blank"<<endl;blank--;}
			else{ cout<<n<<endl;n--;}
		}
		}
		cin>>n;
	}
	return 0;
 }



