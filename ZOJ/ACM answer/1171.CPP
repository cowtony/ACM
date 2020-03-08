 //accepted
 //1171.cpp

 #include<iostream.h>

 int main(){
	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		if(i!=1) cout<<endl;
		cin.get();cin.get();
		int m;long count=0;
		cin>>m;long tt=0;
		char ch[2];
		cin.get();
		for(long j=1;j<=m;j++){
			tt++;
			ch[tt%2]=cin.get();
			while(ch[tt%2]==32||ch[tt%2]==10) ch[tt%2]=cin.get();

			if(tt!=1){

				if(ch[0]!=ch[1]) count++;      }


		}
			cout<<count<<endl;


	}
	return 0;
 }


