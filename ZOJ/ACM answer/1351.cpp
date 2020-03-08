//115228 2003-04-10 21:59:31 Wrong Answer 1351 C++ 00:00.00 432K just for play 
//115251 2003-04-10 22:07:34 Wrong Answer 1351 C++ 00:00.00 432K just for play 
#include<iostream.h>
#include<string.h>
#include<stdio.h>


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char des[16];char guess[16];char pre_res[16];
	char cur_guess[16];
	char low_des[16];int has_occur[26];
	cin.getline(des,16,'\n');
	int i;
	while(cin>>des)
	{
	
		if(strcmp(des,"LINGO")==0)	break;
		cout<<endl;
		cout<<des[0]<<"...."<<endl;
		strcpy(pre_res,des);
		
		for(i=1;i<5;i++)	pre_res[i]='.';
		for(i=0;i<5;i++)	low_des[i]=des[i]-'A'+'a';
		low_des[5]='\0';	
		int count=0;
		bool found=false;
		cin.get();
		while(1)
		{
			
			cin.getline(guess,16,'\n');

			if(strlen(guess)==0)	break;
			
			if(found)	continue;
			count++;
			if(count>6)	continue;
					for(i=0;i<26;i++)	has_occur[i]=0;

			for(i=0;i<5;i++)	has_occur[des[i]-'A']++;

			if(strlen(guess)!=5)
			{
					
				if(count==6)	cout<<low_des<<endl;
				else	cout<<pre_res<<endl;
				continue;
			}

			for(i=0;i<5;i++)
				if((guess[i]<'A')||(guess[i]>'Z'))	break;
			if(i<5)
			{	
				if(count==6)	cout<<low_des<<endl;
				else	cout<<pre_res<<endl;
				continue;
			}
			if(strcmp(des,guess)==0)
			{
				found=true;
				cout<<des<<endl;
				continue;
			}
			else	if(count==6){	cout<<low_des<<endl;continue;}
			for(i=0;i<5;i++)
			{
	
				if(des[i]==guess[i])
				{	cur_guess[i]=des[i];				
					has_occur[des[i]-'A']--;
				}
				else	cur_guess[i]='.';	
			//	cout<<des[i]<<"-----"<<guess[i]<<"--->"<<cur_guess[i]<<endl;
			}
			for(i=0;i<5;i++)
			{
				if(cur_guess[i]=='.'&&has_occur[guess[i]-'A'])
				{
					cur_guess[i]=guess[i]-'A'+'a';
					has_occur[guess[i]-'A']--;
				}
			}
			cur_guess[5]='\0';
			cout<<cur_guess<<endl;
			strcpy(pre_res,cur_guess);
		}
	}
	return 0;
}
			

