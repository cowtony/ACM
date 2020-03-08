 #include<iostream.h>
 #include<stdlib.h>
 #include<string.h>

 int main()
 {
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)	break;
		int i,j;
		int line[26][26];int pt[26];
		char str[30];
		for(i=0;i<n;i++)
		{
			cin>>str;
			int len=strlen(str);
			pt[i]=len-2;
			for(j=2;j<len;j++)
				line[i][j-2]=str[j]-65;
		}
		int flag[26]; int min=0;int a[26];
		int totalflag[26];

		for(long tt=0;tt<10000;tt++)
		{
			for(i=0;i<n;i++)	flag[i]=0;
			int occur[26];
			for(i=0;i<n;i++)  occur[i]=0;
			for(i=0;i<n;i++){
				int b;
				while(1)
				{
					b=rand()%n;
					if(!occur[b])	break;
				}
				a[i]=b;
				occur[b]=1;
			}

			for(i=0;i<n;i++)
			{
				int c=0;
				while(1)
				{       c++;
					for(j=0;j<pt[a[i]];j++)
						if(flag[line[a[i]][j]]==c)	break;
					if(j==pt[a[i]])	break;
				}
				flag[a[i]]=c;
			}
			int tempmin=0;
			for(i=0;i<n;i++)
				if(flag[i]>tempmin)	tempmin=flag[i];
			if(tempmin>4){tt--;continue;}
			if(min==0||tempmin<min)
			{	min=tempmin;
				for(j=0;j<n;j++)	totalflag[j]=flag[j];
			}
			if(min==1)	break;

		}
		if(min==1)	cout<<min<<" channel needed."<<endl;
		else	cout<<min<<" channels needed."<<endl;
	}

	return 0;
 }






