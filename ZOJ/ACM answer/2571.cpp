#include <iostream>
#include <string>
#include <stack>
using namespace std;


int proce(char ch, char cl)
{
	if(cl=='#'&&ch=='#') return 3;
	if(cl=='#') return -1;
	if(cl==')'&&ch=='(') return 2;
	if(cl==')') return -1;
	if(cl=='(') return 1;
	if(cl=='+'&&(ch=='*'||ch=='+')) return -1;
	if(cl=='+') return 1;
	if(cl=='*'&&ch=='*') return -1;
	if(cl=='*') return 1;
}


int main()
{
	int cas;
	int i;
	string str;
	
	scanf("%d%*c",&cas);
	while(cas--)
	{
		string stre="#";
		cin>>str;
		for(i=0; i<str.length(); i++)
		{
			stre+=str[i];
			if(i==str.length()-1) break;
			if(str[i]>='0'&&str[i]<='9'&&str[i+1]=='(')
			{
				stre+='*';
			}
			else if(str[i]>='0'&&str[i]<='9'&&str[i+1]>='a'&&str[i+1]<='z')
			{
				stre+='*';
			}
			else if(str[i]>='a'&&str[i]<='z'&&str[i+1]>='a'&&str[i+1]<='z')
			{
				stre+='+';
			}
			else if(str[i]==')'&&str[i+1]>='0'&&str[i+1]<='9')
			{
				stre+='+';
			}
			else if(str[i]==')'&&str[i+1]>='a'&&str[i+1]<='z')
			{
				stre+='+';
			}
			else if(str[i]>='a'&&str[i]<='z'&&str[i+1]>='0'&&str[i+1]<='9')
			{
				stre+='+';
			}
		}
		stre+='#';
		stack <char> opr;
		stack <string> data;
		stack <int>  time;
		opr.push('#');
		for(i=1; i<stre.length(); i++)
		{
			if(stre[i]>='a'&&stre[i]<='z')
			{
				string sh="#";
				sh[0]=stre[i];
				data.push(sh);
				continue;
			}
			if(stre[i]>='0'&&stre[i]<='9')
			{
				int haha=stre[i]-48;
				i++;
				for(;;i++)
				{
					if(stre[i]>='0'&&stre[i]<='9')
					{
						haha=haha*10+(stre[i]-48);
					}
					else break;
				}
				time.push(haha);
				data.push("Z");
				i--;
				continue;
			}
			int b=proce(opr.top(),stre[i]);
			if(b==-1)
			{
				while(b==-1)
				{
					char cs=opr.top();
					opr.pop();
					string s1,s2;
					s1=data.top();
					data.pop();
					s2=data.top();
					data.pop();
					if(s2!="Z")
					{
						string s3=s2+s1;
						data.push(s3);
					}
					else
					{
						int lop=time.top();
						time.pop();
						string s3;
						for(int i=0; i<lop; i++)
						{
							s3+=s1;
						}
						data.push(s3);
					}
					b=proce(opr.top(),stre[i]);
				}
			}
			if(b==3) break;
			if(b==2) opr.pop();
			else if(b==1)
			{
				opr.push(stre[i]);
			}
		}
		string ans=data.top();
		cout<<ans<<endl;
	}
	return 0;
}
