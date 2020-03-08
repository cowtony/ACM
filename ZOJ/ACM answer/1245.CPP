 #include<iostream.h>

 int main()
 {
	int n;                      int amount=0;
	while(cin>>n)
	{
		if(n==0)	break;
		amount++;
		int flag[101][201];int i,j;
		char ch;
		for(i=n;i>0;i--)
			for(j=1;j<2*i;j++)
			{
				cin>>ch;
				if(ch=='#')	flag[i][j]=0;
				else flag[i][j]=1;
			}
		int max=1;          int max_line=1;
		for(i=n;i>0;i--)
			for(j=1;j<2*i;j++)
			{
				if(j%2==1&&i+max_line>n+1) continue;
				if(j%2==0&&i-max_line<0) continue;



				if(flag[i][j]==0) continue;
				int line=i;int add=3;
				int total=1; int temp_line=0;
				while(1)
				{
					if(j%2==1)
					{
						if(line==n) break;
						int temp;
						for(temp=j;temp<j+add;temp++)
							if(!flag[line+1][temp]) break;
						if(temp!=j+add) break;
						line++;
						temp_line++;
						total=total+add;
						add+=2;
					}
					else
					{
						if(line<=3) break;
						if(j-add<0) break;
						int temp;
						for(temp=j;temp>j-add;temp--)
							if(!flag[line-1][temp]) break;
						if(temp!=j-add) break;
						line--;
						temp_line++;
						total+=add;
						add+=2;
					}
				}

				if(total>max)
				{
					max=total;
					max_line=temp_line;
				}

			}
		cout<<"Triangle #"<<amount<<endl;
		cout<<"The largest triangle area is "<<max<<"."<<endl;
		cout<<endl;
	}
	return 0;
 }
