 #include<iostream.h>
 #include<string.h>
 int same(char ch[],int mul){
	char temp[150];
	strcpy(temp,ch);
	int j;int len=strlen(temp);
	for(j=1;j<mul;j++){
		int t;
		for(t=len-1;t>=0;t--){

			int tt=temp[t]+ch[t]-96;

			if(t==0){if(tt>=10) return 0;}
			temp[t]=tt%10+48;
			if(t!=0) temp[t-1]+=tt/10;
		}

	}

	for(j=0;j<len;j++)
		temp[j+len]=temp[j];
	temp[len+len]='\0';

	if(strstr(temp,ch)) return 1;
	else return 0;
 }



 int main(){
	char ch[70];
	while(cin>>ch){
		int len=strlen(ch);
		int i;
		for(i=1;i<=len;i++)
			if(!same(ch,i)) break;
		cout<<ch<<" is ";
		if(i!=len+1) cout<<"not ";
		cout<<"cyclic"<<endl;
	}
	return 0;
 }
