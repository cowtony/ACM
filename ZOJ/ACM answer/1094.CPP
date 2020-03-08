 #include<iostream.h>

 #include<string.h>

 struct matrix
 {
	int row;
	int col;
 };
 matrix capital[27];
 int can=0;long sum=0;

 matrix doing(char str[],int beg,int end)
 {
	if(beg==end)
	{
		matrix returnval;
		returnval.row=capital[str[beg]-65].row;
		returnval.col=capital[str[beg]-65].col;
		return returnval;
	}
	int fir=beg;int sec=end;

	if(str[fir]=='('&&str[sec]==')')
	{
		int count=1;int pt;
		for(pt=beg+1;pt<=sec;pt++)
		{

			if(str[pt]=='(') count++;
			if(str[pt]==')') count--;
			if(count==0) break;
		}
		if(pt==sec) return doing(str,fir+1,sec-1);
		else
		{
			matrix tempfir,tempsec;
			tempfir=doing(str,fir+1,pt-1);
			tempsec=doing(str,pt+2,sec-1);
			matrix returnval;
			if(tempfir.col!=tempsec.row||
			   tempfir.row==0||tempfir.col==0||
			   tempsec.row==0||tempsec.col==0)
			{
				can=0;
				returnval.row=0;returnval.col=0;
				return returnval;
			}
			returnval.row=tempfir.row;
			returnval.col=tempsec.col;
			sum+=tempfir.row*tempfir.col*tempsec.col;
			return returnval;
		}

	}
	if(str[fir]!='(')
	{
		matrix temp=doing(str,fir+1,sec);
		matrix returnval;
		if(temp.row!=capital[str[fir]-65].col||temp.row==0&&temp.col==0)
		{can=0;returnval.row=0;returnval.col=0;return returnval;}
		sum+=capital[str[fir]-65].row*capital[str[fir]-65].col*temp.col;

		returnval.row=capital[str[fir]-65].row;returnval.col=temp.col;
		return returnval;
	}
	else
	{
		matrix temp=doing(str,fir,sec-1);
		matrix returnval;
		if(temp.col!=capital[str[sec]-65].row||temp.row==0&&temp.col==0)
		{can=0;returnval.row=0;returnval.col=0;return returnval;}
		sum+=temp.row*temp.col*capital[str[sec]-65].col;

		returnval.row=temp.row;returnval.col=capital[str[sec]-65].col;
		return returnval;
	}
 }



 int main()
 {
	int n;int i;
	char ch;cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ch;
		cin>>capital[ch-65].row>>capital[ch-65].col;
	}
	char str[150];
	while(cin>>str)
	{
		int len=strlen(str);
		can=1;sum=0;
		doing(str,0,len-1);
		if(can==0) cout<<"error"<<endl;
		else cout<<sum<<endl;
	}
	return 0;
 }
