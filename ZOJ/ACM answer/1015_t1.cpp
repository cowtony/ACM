 #include<iostream.h>

 int main(){
	int a,b;
	cin>>a>>b;
	while(a!=0&&b!=0){
		if(a==(b*(b-1)/2)) cout<<"Perfect"<<endl;
		else cout<<"Imperfect"<<endl;
		cout<<endl;
		for(int i=1;i<=b;i++){
			int c,d;
			cin>>c>>d;
		}
		cin>>a>>b;
	}
	return 0;
 }
