 #include<iostream.h>
 #include<string.h>
 int same(int b[],int k){
	for(int i=0;i<k;i++)
		if(b[i]==b[k]) return 1;
	return 0;
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
		char result[720][7];int a[6];
		int len=strlen(ch);
		int flag=0;char temp[7];
		for(a[0]=0;a[0]<len;a[0]++){

		if(len>1){for(a[1]=0;a[1]<len;a[1]++){
		if(same(a,1)==1) continue;

		if(len>2){for(a[2]=0;a[2]<len;a[2]++){
		if(same(a,2)==1) continue;

		if(len>3){for(a[3]=0;a[3]<len;a[3]++){
		if(same(a,3)==1) continue;

		if(len>4){for(a[4]=0;a[4]<len;a[4]++){
		if(same(a,4)==1) continue;

		if(len>5){for(a[5]=0;a[5]<len;a[5]++){
		if(same(a,5)==1) continue;



		   }}}}}}
			for(int i=0;i<len;i++)
				temp[i]=ch[a[i]];
			cout<<temp<<"\t";
			cout<<endl;

			temp[len]='\0';

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
			}
			}}}}
			if(flag==0) cout<<"NOT A VALID WORD"<<endl;
			cout<<"******"<<endl;
			cin>>ch;
		}
		return 0;
	}


