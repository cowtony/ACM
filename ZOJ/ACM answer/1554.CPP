#include<stdio.h>
#include<iostream.h>
#include<string>
using namespace std;

int digit(int num)
{
	int result=0;
	while(num)
	{
		result++;
		num/=10;
	}
	return result;
}
string tostr(int num)
{
	string result;
	while(num)
	{
		result=char(num%10+48)+result;
		num/=10;
	}
	return result;
}

struct str_type
{
	int num;
	string str;
	str_type()
	{
		num=0;
	}
	int cal_len()
	{
		int fir=str.length()*num;
		int sec=str.length()*digit(num)+2;
		return (fir<sec)?fir:sec;		
	}
	string convert()
	{
		int fir=str.length()*num;
		int sec=str.length()*digit(num)+2;
		string result;
		if(fir<=sec)
			result=str;
		else	result=tostr(num)+"("+str+")";
		return result;
	}
		



};

void output(string& tt)
{
	char temp[101];
	strcpy(temp,tt.c_str());
	cout<<temp;
}
int main()

{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char input_ch[101];

	while(cin>>input_ch)
	{
		string input=input_ch;
		int len=input.length();
		str_type val[101][101];		
		int i,j,t;
		for(t=0;t<len;t++)
		{
			val[t][t].num=1;
			val[t][t].str=input[t];
		}
		for(t=1;t<len;t++)
		{
			for(i=0;i<len-t;i++)
			{
				
				int minlen=-1;
				for(j=i;j<i+t;j++)
				{
					str_type temp;
					if(val[i][j].str==val[j+1][j+t].str)
					{
						temp.num=val[i][j].num+val[j+1][j+t].num;
						temp.str=val[i][j].str;
					}
					else
					{
						temp.num=1;
						temp.str=val[i][j].convert()+val[j+1][j+t].convert();
					}
					if(minlen<0||temp.cal_len()<minlen)
					{
						minlen=temp.cal_len();
						val[i][i+t].num=temp.num;
						val[i][i+t].str=temp.str;
					}
				}
			}
		}
		for(i=0;i<len;i++)
			for(j=i;j<len;j++)
			{
				cout<<i<<" ---  "<<j<<"   ";
				output(val[i][j].str);
				cout<<"  "<<val[i][j].num;
				cout<<endl;
			}
		char result_str[200];
		cout<<val[0][len-1].num<<endl;
		string result=val[0][len-1].convert();
		strcpy(result_str,result.c_str());
		cout<<result_str<<endl;					
	}
	return 0;
}