  #include<iostream.h>
 #include<string.h>

	char result[720][7];int a[6];
 int same(int k){
	for(int i=0;i<k;i++)
		if(a[i]==a[k]) return 1;
	return 0;
 }
 void  doing(int i,int len){
	if(i==len){

	for(int j=0;j<len;j++){
		if(same(i)) continue;
		doing(i+1);
	}



 int main(){
	char dic[101][7];
	int point=0;
	cin>>dic[point];
	while(strcmp(dic[point],"XXXXXX")!=0)
		cin>>dic[++point];
	char ch[7];
	cin>>ch;
	while(strcmp(ch,"XXXXXX")!=0){

		int len=strlen(ch);
		int flag=0;char temp[7];
			for(int i=0;i<len;i++)
				temp[i]=ch[a[i]];
			cout<<temp<<"\t";
			cout<<endl;



			for(int j=0;j<point;j++)
				if(strcmp(temp,dic[j])==0){
					int t;
					for(t=0;t<flag;t++)
						if(strcmp(temp,result[t])==0) break;
					if(t==flag) {
						strcpy(temp,result[flag++]);
						cout<<temp<<endl;
					}
				}


			if(flag==0) cout<<"NOT A VALID WORD"<<endl;
			cout<<"******"<<endl;
			cin>>ch;
		}
		return 0;
	}


