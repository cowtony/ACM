 #include<iostream.h>
 #include<string.h>


 int num[302]; int len;
 int res[10]={6,1,2,6,4,4,4,8,4,6};

 void make(int len,int& result)
 {
	if(len==0)	return;
	int i;

	result=res[num[len-1]]*result%10;
	if(len>1)	result=result*6%10;
	int left=0;

	for(i=0;i<len;i++)
	{
		int temp=left*10+num[i];
		num[i]=temp/5;
		left=temp%5;
	}
	left=0;
	for(i=0;i<len;i++)
	{
		int temp=left*10+num[i];
		left=temp%4;
	}

	for(i=0;i<left;i++)
	{
		if(result==6)	result=8;
		else if(result==8)	result=4;
		else if(result==4)	result=2;
		else if(result==2)	result=6;
	}
	if(num[0]==0){
		for(i=0;i<len-1;i++)
			num[i]=num[i+1];
		len--;
	}
	make(len,result);
 }





 int main()
 {
	 char str[302];
	 while(cin>>str)
	 {
		int len=strlen(str);
		int i;
		for(i=0;i<len;i++)
			num[i]=str[i]-48;
		int result=1;

		make(len,result);
		cout<<result<<endl;
	 }
	 return 0;
 }








