 #include<iostream.h>


 int adjust(int point[][26],int fir,int sec,int m)
 {
        if(point[fir][sec])     return 0;
        if(point[sec][fir])     return 1;
        point[fir][sec]=1;
        int i;
        for(i=0;i<m;i++)
        {
                if(point[sec][i])
                {       if(!point[fir][i])
                        {        if(adjust(point,fir,i,m)) return 1;}
                }
        }
        for(i=0;i<m;i++)
        {
                if(point[i][fir])
                {       if(!point[i][sec])
                                if(adjust(point,i,sec,m))       return 1;
                }
        }
        return 0;
 }


 int main()
 {
	int m,n;
	while(1)
	{
		cin>>m>>n;
		if(m==0&&n==0)	break;
		int i,j;int flag=0;int pt;int pt2;int flag2=0;
		int point[26][26];int a[26];
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)	point[i][j]=0;
		for(i=0;i<n;i++)
		{
			char ch1,ch2,ch3;
			cin>>ch1>>ch2>>ch3;
			if(flag)	continue;
                      	if(flag2)	continue;
			if(adjust(point,ch1-65,ch3-65,m)){flag=1;pt=i+1;continue;}
			int t;
			for(t=0;t<m;t++)	a[t]=-1;
			for(t=0;t<m;t++)
			{
				int add=0;
				for(j=0;j<m;j++)
					if(point[t][j])	add++;
				int temp=m-add-1;
				if(a[temp]!=-1)	break;
				a[temp]=t;
			}
			if(t==m){flag2=1;pt2=i+1;}

		}
		if(flag)
		{	cout<<"Inconsistency found after "<<pt<<" relations."<<endl;continue;}
		if(flag2)
		{  cout<<"Sorted sequence determined after "<<pt2<<" relations: ";
			for(i=0;i<m;i++)	cout<<char(a[i]+65);
			cout<<"."<<endl;	continue;
		}
		cout<<"Sorted sequence cannot be determined."<<endl;
	}
	return 0;
 }














