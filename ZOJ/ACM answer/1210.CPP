 #include<iostream.h>
 #include<string.h>

 void add(char first[],char second[]){
	int len1=strlen(first);
	int len2=strlen(second);
	int max;
	if(len1>len2){
		max=len1;
		for(int i=len2;i<=len1;i++) second[i]=48;
		first[len1]=48;
	}
	if(len1<len2){
		max=len2;
		for(int i=len1;i<=len2;i++) first[i]=48;
		second[len2]=48;
	}
	if(len1==len2){
		first[len1]=48;second[len2]=48;
		max=len1;
	}
	for(int i=0;i<max;i++){
		int temp=first[i]+second[i]-96;
		if(temp>=10) first[i+1]++;
		first[i]=temp%10+48;

	}

	if(first[max]==48) first[max]='\0';
	else first[max+1]='\0';


 }
 void deduce(char[],char[]);
 void mai(){
	char ch1[10],ch2[10];
	while(cin>>ch1>>ch2){
		deduce(ch1,ch2);
		cout<<ch1<<endl;
	}
 }


 void deduce(char first[],char second[]){
	int len1=strlen(first);
	int len2=strlen(second);
	for(int i=len2;i<len1;i++) second[i]=48;
	for(int j=0;j<len1;j++){
		if(first[j]<second[j]) {first[j]=first[j]+10;first[j+1]--;}
		first[j]=first[j]-second[j]+48;
	}
 }
 int main(){
	char ch[80];
	while(cin>>ch){
		cout<<endl;
		cout<<"1 / "<<ch<<endl;
		cout<<"= "<<endl;
		int len=strlen(ch);
		int mid=len/2;
		for(int i=0;i<mid;i++){
			int temp=ch[i];
			ch[i]=ch[len-i-1];
			ch[len-i-1]=temp;
		}

		char result[80];
		result[0]=48;result[1]=46;
		for(int t=2;t<=len;t++) result[t]=48;
		char rest[80];
		for(int j=0;j<len;j++) rest[j]=48;
		rest[len]='\0';
		int point=len+1;
		while(1){
			cout<<rest<<endl;
			cin.get();
			int i;
			char temp[80];
			for(i=0;i<len;i++) temp[i]=48;
			temp[len]='\0';
			for(i=0;i<=10;i++){

				 add(temp,ch);
				 cout<<temp<<endl;
				 if(strcmp(rest,temp)<=0) break;
			}
			if(strcmp(rest,temp)==0){ result[point]=i+1;break;}
			result[point++]=i;
			deduce(temp,ch);
			deduce(result,temp);

		}
		result[point]='\0';
		cout<<result<<endl;
	}
	return 0;
 }







