 #include<iostream.h>





 #include<string.h>

 int main(){

	char phone[8][4]={{97,98,99,32},{100,101,102,32},
		{103,104,105,32},{106,107,108,32},{109,110,111,32},
		{112,113,114,115},{116,117,118,32},{119,120,121,122}};

	int nn;int i;
	cin>>nn;
	for(i=1;i<=nn;i++){
		cout<<"Scenario #"<<i<<":"<<endl;
		char* ch[1001];int* poss[1001];
		int w;int j;
		cin>>w;
		for(j=0;j<w;j++){
			char temp[101];poss[j]=new int;
			cin>>temp>>*poss[j];



			ch[j]=new char[strlen(temp)+1];

			strcpy(ch[j],temp);
		}
		int m;cin>>m;
		for(j=0;j<m;j++){
			char str[105];
			cin>>str;
			int len=strlen(str);
			int t;
			int flag[1001];
			for(t=0;t<w;t++) flag[t]=1;
			for(t=0;t<len-1;t++){
				int tt;int point=-1;int pp=0;
				for(tt=0;tt<w;tt++){


					if(flag[tt]==1){
						int te;

						for(te=0;te<4;te++){

							if(ch[tt][t]==phone[str[t]-50][te]){

								if(*poss[tt]>pp) {pp=*poss[tt];point=tt;}
								break;
							}
						}
						if(t==strlen(ch[tt])-1) flag[tt]=0;
						if(te==4) flag[tt]=0;
					}
				}
				if(pp==0) cout<<"MANUALLY"<<endl;
				else{for(int iii=0;iii<=t;iii++)
						cout<<ch[point][iii];
					 cout<<endl;

				}




			}
			cout<<endl;
		}
		cout<<endl;
		for(j=0;j<w;j++){
			delete poss[j];
			delete ch[j];
		}



	}
	return 0;
 }










