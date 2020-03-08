//109184 2003-04-06 15:43:19 Accepted 1325 C++ 00:00.00 436K Century Ghost 
#include<iostream.h>
#include<string.h>
#include<stdio.h>


	char mirror[21][2]={{'A','A'},{'E','3'},{'H','H'},{'I','I'},{'J','L'},
	{'L','J'},{'M','M'},{'O','O'},{'S','2'},{'T','T'},{'U','U'},{'V','V'},
	{'W','W'},{'X','X'},{'Y','Y'},{'Z','5'},{'1','1'},{'2','S'},{'3','E'},
	{'5','Z'},{'8','8'}};

int is_mirror(char* str)
{
	int len=strlen(str);
	int i;
	for(i=0;i<=len/2;i++)
	{
		char fir=str[i];char sec=str[len-1-i];
		int j;bool flag=false;
		for(j=0;j<21;j++)
			if(mirror[j][0]==fir)
			{
				if(mirror[j][1]==sec)	flag=true;
				break;
			}
		if(!flag)	return 0;
	}
	return 1;
}
int is_palind(char* str)
{
	int len=strlen(str);
	int i;
	for(i=0;i<=len/2;i++)
		if(str[i]!=str[len-1-i])	return 0;
	return 1;
}

				

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char string[500];
	
	while(cin>>string)
	{
		if(is_mirror(string))
		{
			if(is_palind(string))			
				cout<<string<<" -- is a mirrored palindrome."<<endl;
			else	cout<<string<<" -- is a mirrored string."<<endl;
		}
		else	if(is_palind(string))
			cout<<string<<" -- is a regular palindrome."<<endl;
		else	cout<<string<<" -- is not a palindrome."<<endl;
		cout<<endl;
	}
	return 0;
}




