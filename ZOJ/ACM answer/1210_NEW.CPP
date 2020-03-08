 //accepted

 #include<iostream.h>
 #include<conio.h>
 #include<string.h>


 void reverse(char ch[]){
	int len=strlen(ch);
	int mid=len/2;
	for(int i=0;i<mid;i++){
		int temp=ch[i];
		ch[i]=ch[len-i-1];
		ch[len-i-1]=temp;
	}
 }
 void clear(char ch[]){
	int len=strlen(ch);
	int i;


	for(i=0;i<len;i++){
		if(ch[i]!=48) break;
		if(ch[i]==46) break;
	}
	if(ch[i]==46) i--;
	if(i==0) return ;
	for(int j=0;j<=len-i;j++)
		ch[j]=ch[j+i];
 }
 int compare(char ch1[],char ch2[]){
	clear(ch1);clear(ch2);
	int len1=strlen(ch1);int  len2=strlen(ch2);
	if(len1>len2) return 1;
	if(len1<len2) return -1;
	for(int i=0;i<len1;i++){
		if(ch1[i]>ch2[i]) return 1;
		if(ch1[i]<ch2[i]) return -1;
	}
	return 0;
 }


 void add(char ch1[],char ch2[]){
	reverse(ch1);reverse(ch2);
	int len1=strlen(ch1);int len2=strlen(ch2);
	int max=(len1>len2)?len1:len2;
	int i;
	for(i=len1;i<=max;i++) ch1[i]=48;
	for(i=len2;i<=max;i++) ch2[i]=48;
	ch1[max+1]='\0';ch2[max+1]='\0';
	for(i=0;i<max;i++){
		int temp=ch1[i]+ch2[i]-96;
		if(temp>=10){temp+=10;ch1[i+1]++;}
		ch1[i]=temp%10+48;
	}
	reverse(ch1);reverse(ch2);
	clear(ch1);

 }

 void deduce(char ch1[], char ch2[]){
	int flag=compare(ch1,ch2);
	clear(ch1);clear(ch2);
	reverse(ch1);reverse(ch2);
	int len1=strlen(ch1);int len2=strlen(ch2);
	if(flag==0) {ch1[0]=48;ch1[1]='\0';reverse(ch2);return;}
	if(flag==1){

		int i;
		for(i=len2;i<len1;i++) ch2[i]=48;
		ch2[len1]='\0';
		for(i=0;i<len1;i++){
			if(ch1[i]<ch2[i]){ ch1[i]=ch1[i]+10;ch1[i+1]--;}
			ch1[i]=ch1[i]-ch2[i]+48;
		}
	}
	if(flag==-1){
		int i;
		for(i=len1;i<len2;i++) ch1[i]=48;

		ch1[len2]='\0';

		for(i=0;i<len2;i++){
			if(ch1[i]>ch2[i]){ch2[i]=ch2[i]+10;ch2[i+1]--;}
			ch2[i]=ch2[i]-ch1[i]+48;
		}

		strcpy(ch1,ch2);
		reverse(ch1);clear(ch1);reverse(ch1);
		int ll=strlen(ch1);
		ch1[ll]='-';ch1[ll+1]='\0';
		reverse(ch1);reverse(ch2);return;
	}


	reverse(ch1);reverse(ch2);
	clear(ch1);clear(ch2);

 }


 void dive(char ch1[],char ch2[]){
	int len1=strlen(ch1);
	char first[82],second[82],rest[82],result[82];

	first[0]=ch1[0];first[1]='\0';
	result[0]=48;result[1]='\0';
	int point=0;int flag=0;
	while(1){
		cout<<first<<endl;
		int value;int i;rest[0]=48;rest[1]='\0';
		for(i=0;i<=9;i++){
			strcpy(second,ch2);
			add(rest,second);
			value=compare(rest,first);
			if(value!=-1) break;
		}
		result[point++]=i+48;

		if(value==0&&point>=len1){result[point-1]++;break;}
		if(flag==0&&point>=len1){result[point++]=46;len1;flag=1;}
		strcpy(second,ch2);

		if(value!=0) deduce(rest,second);
		else result[point-1]++;



		deduce(first,rest);

		int len=strlen(first);
		if(flag==0) first[len]=ch1[point];
		else first[len]=48;
		first[len+1]='\0';
		clear(first);
	}
	result[point]='\0';
	strcpy(ch1,result);
	clear(ch1);
 }

 int main(){
	char ch1[82];char ch2[82];
	cout<<"Problem 4 by team x"<<endl;

	while(cin>>ch2){
		cout<<endl;
		cout<<"1 / "<<ch2<<" ="<<endl;
		ch1[0]=49;ch1[1]='\0';
		dive(ch1,ch2);
		cout<<ch1<<endl;

	}
	cout<<"End of problem 4 by team x"<<endl;


	return 0;
 }



