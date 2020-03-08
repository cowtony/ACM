
 //1009.cpp

 #include<iostream.h>
 #include<string.h>

 struct line{
	int from,to;
 };
 line state[3][26];
 line st[3][26];

 void change(int i,int j){
	for(int temp=0;temp<j;temp++){
		st[i][temp].from=(st[i][temp].from+1)%j;
		st[i][temp].to=(st[i][temp].to+1)%j;
	}
 }


 int main(){

	int n;
	cin>>n; int amount=0;
	while(n!=0){

		char str[3][30]; amount++;
		if(amount!=1) cout<<endl;
		cin>>str[0]>>str[1]>>str[2];
		int i;int j;
		for(j=0;j<3;j++)
			for(i=0;i<n;i++){
				state[j][i].from=i;
				state[j][i].to=str[j][i]-65;

			}
		cout<<"Enigma "<<amount<<":"<<endl;
		int m;
		cin>>m;

		for(i=1;i<=m;i++){
			for(int tt=0;tt<3;tt++)
				for(int qq=0;qq<n;qq++){
					st[tt][qq].from=state[tt][qq].from;
					st[tt][qq].to=state[tt][qq].to;
				}

			char ch[1000];
			cin>>ch;
			int len=strlen(ch);
			int first=0,second=0;
			for(j=0;j<len;j++){
				first++;int next;
				int tt;
				for(tt=0;tt<n;tt++)
					if(st[2][tt].to==ch[j]-65){
						next=st[2][tt].from;break;
					}

				for(tt=0;tt<n;tt++)
					if(st[1][tt].to==next){
						next=st[1][tt].from;break;
					}

				for(tt=0;tt<n;tt++)
					if(st[0][tt].to==next)
						break;

				char c;
				c=st[0][tt].from+97;
				cout<<c;
				change(0,n);

				if(first==n){
					first=0;
					second++;
					change(1,n);
				}



				if(second==n){
					second=0;
					change(2,n);
				}
			}
			cout<<endl;
		}

		cin>>n;



	}
	return 0;
 }









