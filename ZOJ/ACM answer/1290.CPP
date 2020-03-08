 #include<iostream.h>
 #include<string.h>


 char ch[101][101];
 int num;

 int find(char* str,int row,int col)
 {
	int way;
	int len=strlen(str);
	for(way=1;way<=8;way++)
	{
		int i;
		switch(way)
		{
			case 1:
				if(col+len>num+1) break;
				for(i=0;i<len;i++)
					if(str[i]!=ch[row][col+i]) break;
				if(i==len) return 1;
				break;
			case 2:
				if(col+len>num+1||row+len>num+1) break;
				for(i=0;i<len;i++)
					if(str[i]!=ch[row+i][col+i]) break;
				if(i==len)     return 2;
				break;
			case 3:
				if(row+len>num+1) break;
				for(i=0;i<len;i++)
					if(str[i]!=ch[row+i][col]) break;
				if(i==len) return 3;
				break;
			case 4:
				if(row+len>num+1||col-len<0) break;
				for(i=0;i<len;i++)
					if(str[i]!=ch[row+i][col-i]) break;
				if(i==len)	return 4;
				break;
			case 5:
				if(col-len<0) break;
				for(i=0;i<len;i++)
					if(str[i]!=ch[row][col-i]) break;
				if(i==len) return 5;
				break;
			case 6:
				if(col-len<0||row-len<0) break;
				for(i=0;i<len;i++)
					if(str[i]!=ch[row-i][col-i]) break;
				if(i==len) return 6;
				break;
			case 7:
				if(row-len<0) break;
				for(i=0;i<len;i++)
					if(str[i]!=ch[row-i][col]) break;
				if(i==len) return 7;
				break;
			case 8:
				if(row-len<0||col+len>num+1) break;
				for(i=0;i<len;i++)
					if(str[i]!=ch[row-i][col+i]) break;
				if(i==len) return 8;
				break;
		}
	}
	return 0;
 }



 int main()
 {
	int nn;int i;
	cin>>nn;
	for(i=1;i<=nn;i++)
	{
		if(i!=1) cout<<endl;
		cin>>num;
		int j,k;
		for(j=1;j<=num;j++)
			for(k=1;k<=num;k++)
				cin>>ch[j][k];
		char str[101];

		while(1)
		{
			cin>>str;
			if(str[0]==48) break;
			int way;
			int len=strlen(str);
			for(j=1;j<=num;j++)
			{
				for(k=1;k<=num;k++)
				{
					if(str[0]!=ch[j][k]) continue;

					way=find(str,j,k);




					if(way) break;
				}
				if(k!=num+1) break;
			}

			  switch(way)
			  {
				case 0: cout<<"Not found"<<endl;break;
				case 1:cout<<j<<","<<k<<" "<<j<<","<<(k+len-1)<<endl;break;
				case 2:cout<<j<<","<<k<<" "<<(j+len-1)<<","<<(k+len-1)<<endl;break;
				case 3:cout<<j<<","<<k<<" "<<(j+len-1)<<","<<k<<endl;break;
				case 4:cout<<j<<","<<k<<" "<<(j+len-1)<<","<<(k-len+1)<<endl;break;
				case 5:cout<<j<<","<<k<<" "<<j<<","<<(k-len+1)<<endl;break;
				case 6:cout<<j<<","<<k<<" "<<(j-len+1)<<","<<(k-len+1)<<endl;break;
				case 7:cout<<j<<","<<k<<" "<<(j-len+1)<<","<<k<<endl;break;
				case 8:cout<<j<<","<<k<<" "<<(j-len+1)<<","<<(k+len-1)<<endl;break;

			  }
		}
	}
	return 0;
 }






