 //78841 2003-02-25 23:44:34 Accepted 1014 C++ 00:00.00 436K Century Ghost
 #include<iostream.h>
 #include<string.h>

 void output(char string,int num[],int tt,int k);
 void search(char* middle,char* result,int n);

 int main()
 {
	char name;int flag=0;
	while(cin>>name)
	{
		if(name=='*')	break;
		if(flag)	cout<<endl;
		flag=1;
		char temp;
		cin>>temp>>temp;
		char string[500];char result[500];char middle[500];
		cin>>string;
		int n;int i;
		cout<<"Expression "<<name<<":"<<endl;
		cin>>n;
		for(i=0;i<n;i++)
		{
			int num[100];
			int tt=0;
			while(1)
			{
				cin>>num[tt];
				cin.get(temp);
				if(temp=='\n')	break;
				tt++;
			}
			strcpy(middle,string);
			int j;
			for(j=0;j<=tt;j++)
			{

				search(middle,result,num[j]);
				strcpy(middle,result);
			}
			output(name,num,tt,tt);
			cout<<"=";
			cout<<middle<<endl;
		}
	}
	return 0;
 }
 void output(char string,int num[],int tt,int k)
 {
	if(k==-1){	cout<<string;return;}
	cout<<"op("<<num[k]<<",";
	output(string,num,tt,k-1);
	cout<<")";
 }



 int get_ope(char* middle)
 {
	int len=strlen(middle);
	int i;
	int circle=0;  int two=0,three=0,four=0;
	for(i=0;i<len;i++)
	{
		if(middle[i]=='('){circle++;four=1;}
		if(middle[i]==')')     circle--;
		if(circle==0)
		{
			if(middle[i]=='+'){	return 1;}
			if(middle[i]=='*')	two=1;
			if(middle[i]=='^')	three=1;
		}
	}
	if(two)	return 2;
	if(three)	return 3;
	if(four)	return 4;
	return 0;
 }

 void search(char* middle,char* result,int n)
 {

	int pio=get_ope(middle);
	if(pio==0) {	strcpy(result,middle);return;}
	int circle=0;
	char ch;    int len=strlen(middle);
	int i;
	if(pio==4)
	{
		for(i=0;i<len-2;i++)	result[i]=middle[i+1];
		result[len-2]='\0';
		return;
	}
	if(pio==1)	ch='+';
	if(pio==2)	ch='*';
	if(pio==3)	ch='^';
	int beg=-1,end=-1;int pt=1;
	for(i=0;i<len;i++)
	{
		if(pt==n&&beg<0)	beg=i;
		if(middle[i]=='(')	circle++;
		if(middle[i]==')')	circle--;
		if(circle==0&&ch==middle[i])	pt++;
		if(pt==n+1&&end<0)  {	end=i-1;break;}
	}
	if(end<0)	end=len-1;
	for(i=0;i<=end-beg;i++)	result[i]=middle[i+beg];
	result[end-beg+1]='\0';
 }







