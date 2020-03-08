 //55441 2002-11-20 23:23:35 Accepted 1324 C++ 00:00.00 440K Century Ghost
 #include<iostream.h>

 #include<string.h>


 char str[101][61];
 int partion(int beg,int end)
 {
	char temp[61];
	strcpy(temp,str[beg]);
	int j=beg;
	int k=end+1;
	while(1)
	{
		while(j<end&&strcmp(str[++j],temp)<0);
		while(k>beg&&strcmp(str[--k],temp)>0);
		if(j>=k)	break;
		char ttt[61];strcpy(ttt,str[j]);
		strcpy(str[j],str[k]);strcpy(str[k],ttt);
	}
	strcpy(str[beg],str[k]);
	strcpy(str[k],temp);
	return k;
 }
 void quicksort(int beg,int end)
 {
	if(beg<end)
	{
		int q=partion(beg,end);
		quicksort(beg,q-1);
		quicksort(q+1,end);
	}
 }

 int main()
 {
	int n;int i,j;
	while(cin>>n)
	{
		int len[101];int maxlen;
		for(i=0;i<n;i++)	cin>>str[i];
		quicksort(0,n-1);

		for(i=0;i<n;i++)	len[i]=strlen(str[i]);
		maxlen=0;
		for(i=0;i<n;i++)	if(len[i]>maxlen)	maxlen=len[i];

		cout<<"------------------------------------------------------------"<<endl;
		int col=62/(maxlen+2);
		int row=n/col;
		if(n%col)	row++;

		for(i=0;i<row;i++)
		{
			for(j=0;j<col-1;j++)
			{       int id=j*row+i;
				cout<<str[id];
				if(j==col-2&&((col-1)*row+i>=n)){cout<<endl; break;}
				for(int t=len[id];t<maxlen+2;t++)	cout<<" ";
			}

			if((col-1)*row+i<n)
				cout<<str[(col-1)*row+i]<<endl;

		}
	}
	return 0;
 }

