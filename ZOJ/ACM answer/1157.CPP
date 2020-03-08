 #include<iostream.h>
 #include<string.h>

 int main(){
	int nn;int i;
	cin>>nn;
	for(i=1;i<=nn;i++){
		if(i!=1) cout<<endl;
		int n,m,k;
		cin>>n;
		char ch[101][25];int j;
		for(j=0;j<n;j++) cin>>ch[j];
		cin>>m;
		char temp[101];char in[101][25];
		for(j=0;j<m;j++) cin>>temp>>in[j];
		cin>>k;
		char to[101][25],from[101][25];
		for(j=0;j<k;j++) cin>>to[j]>>from[j];
		int flag[101];
		for(j=0;j<m;j++) flag[j]=0;

		int num=m;
		for(j=0;j<n;j++){
			char stack[101][25];int ptr=0;int get[101];int gg;
			while(1){
				int jj;
				for(jj=0;jj<m;jj++){
					if(flag[jj]==0&&strcmp(ch[j],in[jj])==0){
						flag[jj]=1;num--;break;
					}
				}
				if(jj!=m) break;int ff=0;
				for(jj=0;jj<k;jj++){
				   if(strcmp(from[jj],ch[j])==0){
						strcpy(stack[ptr++],ch[j]);
						strcpy(ch[j],to[jj]);break;
					}
				}
				if(jj==k) break;
				for(int tt=0;tt<ptr;tt++){
					if(strcmp(ch[j],stack[tt])==0){

						ff=1;break;
					}
				}

				if(ff==1) break;

		   }

		}
		cout<<num<<endl;

	}
	return 0;
 }




