 //85673 2003-03-09 23:25:24 Accepted 1181 C++ 00:00.00 444K Century Ghost

 #include<iostream.h>
 #include<string.h>

 struct string
 {
	char dic[7];
	int flag[26];
	string();
 };
 string::string()
 {
	int i;
	for(i=0;i<26;i++)
		flag[i]=0;
 }

 string input[101];

 void sort(int pt)
 {
	int i,j;
	for(i=0;i<pt;i++)
	{
		int out=i;
		for(j=i+1;j<pt;j++)
			if(strcmp(input[j].dic,input[out].dic)<0)	out=j;
		if(out!=i)
		{
			string temp;
			strcpy(temp.dic,input[i].dic);
			for(j=0;j<26;j++)	temp.flag[j]=input[i].flag[j];
			strcpy(input[i].dic,input[out].dic);
			for(j=0;j<26;j++)	input[i].flag[j]=input[out].flag[j];
			strcpy(input[out].dic,temp.dic);
			for(j=0;j<26;j++)	input[out].flag[j]=temp.flag[j];

		}
	}
 }

 int main()
 {
	char temp[7];
	int pt=0;int i;
	while(cin>>temp)
	{
		if(strcmp(temp,"XXXXXX")==0)	break;
		strcpy(input[pt].dic,temp);
		int len=strlen(temp);
		for(i=0;i<len;i++)	input[pt].flag[temp[i]-'a']++;
		pt++;
	}
	sort(pt);


	while(cin>>temp)
	{
		if(strcmp(temp,"XXXXXX")==0)	break;
		int tempflag[26];

		for(i=0;i<26;i++)	tempflag[i]=0;
		int len=strlen(temp);
		for(i=0;i<len;i++)	tempflag[temp[i]-'a']++;

		int flag=0;
		for(i=0;i<pt;i++)
		{
			int j;
			for(j=0;j<26;j++)
				if(tempflag[j]!=input[i].flag[j])	break;
			if(j==26){flag=1;	cout<<input[i].dic<<endl;}
		}
		if(!flag)	cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;
	}
	return 0;
 }



