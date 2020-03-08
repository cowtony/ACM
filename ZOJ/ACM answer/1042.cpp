 //83231 2003-03-05 16:15:33 Accepted 1042 C++ 00:00.00 436K Century Ghost
 #include<iostream.h>
 #include<string.h>

 void rotate(char* string,int flag[],int count,int tt)
 {
	char temp[81];
	strcpy(temp,string);int i;
	for(i=0;i<count;i++)
		string[flag[(i+tt)%count]]=temp[flag[i]];
 }
 int main()
 {
	char string[81];
	int one,two,three;
	while(cin>>one>>two>>three)
	{
		if(one==0&&two==0&&three==0)	break;
		cin>>string;
		int len=strlen(string);
		int i,j;
		int flag[81];int count=0;
		for(i=0;i<len;i++)
			if(string[i]!='_'&&string[i]>='a'&&string[i]<='i')	flag[count++]=i;
		rotate(string,flag,count,one);
		count=0;
		for(i=0;i<len;i++)
			if(string[i]!='_'&&string[i]>='j'&&string[i]<='r')	flag[count++]=i;
		rotate(string,flag,count,two);
		count=0;
		for(i=0;i<len;i++)
			if(string[i]=='_'||string[i]>'r')	flag[count++]=i;
		rotate(string,flag,count,three);
		cout<<string<<endl;
	}
	return 0;
 }


