 #include<iostream.h>
 #include<string.h>

 int outlen;
 struct string
 {
	char str[21];
	int len;
	int a[26];
 };


 int same(string* input,string* dic[],int b[],int tt)
 {
	int org=0;int i;
	while(1)
	{
		for(i=org;i<outlen;i++)
			if(input->str[i]==32)	break;
		char temp[30];int j=0;int t;
		for(t=org;t<i;t++)
			temp[j++]=input->str[t];

		org=i+1;
		temp[j]=0;

		for(t=0;t<tt;t++)
			if(strcmp(temp,dic[b[t]]->str)==0)	break;
		if(t>=tt)	return 0;
		if(i==outlen)	break;
	}
	return 1;

 }



 void output(string* input,string* dic[],int pt,int b[],int lev,string* total,int tt)
 {


	int i,j;
	if(total->len==input->len)
	{
		if(same(input,dic,b,tt))	return;
		for(i=0;i<outlen;i++)
			cout<<input->str[i];
		cout<<" = ";
		for(i=0;i<tt;i++)
		{
			if(i)	cout<<" ";
			cout<<dic[b[i]]->str;
		}
		cout<<endl;
	}
	for(i=lev;i<pt;i++)
	{
		if(total->len+dic[i]->len>input->len)	continue;
		for(j=0;j<26;j++)
			if(total->a[j]+dic[i]->a[j]>input->a[j])	break;
		if(j<26)	continue;
		total->len+=dic[i]->len;
		for(j=0;j<26;j++)
			total->a[j]+=dic[i]->a[j];
		b[tt]=i;
		output(input,dic,pt,b,i+1,total,tt+1);
		total->len-=dic[i]->len;
		for(j=0;j<26;j++)
			total->a[j]-=dic[i]->a[j];
	}
 }




 int main()
 {
	string* dic[2001];
	char buffer[21];int pt=0;
	int i;
	while(cin>>buffer)
	{
		int temlen=strlen(buffer);
		if(temlen==1&&buffer[0]=='#')	break;
		dic[pt]=new string;
		for(i=0;i<26;i++)	dic[pt]->a[i]=0;
		strcpy(dic[pt]->str,buffer);
		dic[pt]->len=temlen;
		for(i=0;i<temlen;i++)	dic[pt]->a[buffer[i]-65]++;
		pt++;
	}

	char ch;
	cin.get(ch);
	while(1)
	{
		int temlen=0;int flag=0;
		string* input=new string;outlen=0;
		for(i=0;i<26;i++)	input->a[i]=0;
		while(cin.get(ch))
		{
			if(ch=='\n')	break;
			if(ch=='#')    {flag=1;break;}
			input->str[outlen++]=ch;
			if(ch==32)	continue;
			input->a[ch-65]++;
			temlen++;
		}
		if(flag)	break;
		input->len=temlen;
		int b[21];
		string* total=new string;
		total->len=0;
		for(i=0;i<26;i++)	total->a[i]=0;
		output(input,dic,pt,b,0,total,0);

	}
	return 0;
 }

