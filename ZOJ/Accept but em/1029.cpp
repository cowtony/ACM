 //80936 2003-03-01 21:53:10 Wrong Answer 1029 C++ 00:00.00 436K Century Ghost
 //80966 2003-03-01 22:27:42 Accepted 1029 C++ 00:00.01 436K Century Ghost
 #include<iostream.h>

 struct move
 {
	int from,to;
 };

 void swap(int& fir,int& to)
 {
	int tt=fir;fir=to;to=tt;
 }
 int min(move fir,move sec)
 {
	if(sec.from-fir.from>1)	return 1;
	if(sec.from-fir.from==1&&sec.from%2==1)	return 1;
	if(sec.from==fir.from||(sec.from-fir.from==1))
	{	if(fir.to-sec.to>1)	return 1;
		if(fir.to-sec.to==1&&fir.to%2==1)	return 1;
	}
	return 0;
 }
 void sort(int num,move table[])
 {
	int i,j;int tt;
	for(i=0;i<num;i++)
	{
		tt=i;
		for(j=i+1;j<num;j++)
			if(min(table[j],table[tt]))	tt=j;
		if(tt!=i)
		{
			swap(table[i].from,table[tt].from);
			swap(table[i].to,table[tt].to);
		}
	}
 }


 int main()
 {
	int n;
	cin>>n;
	while(n--)
	{
		move   table[201];
		int num;int i,j;
		cin>>num;
		for(i=0;i<num;i++)
		{	cin>>table[i].from>>table[i].to;
			if(table[i].from>table[i].to)	swap(table[i].from,table[i].to);
		}
		sort(num,table);
		int flag[201];
		for(i=0;i<num;i++)	flag[i]=0;
		int total=0;
		while(1)
		{
			int tt=0;int changed=0;
			for(i=0;i<num;i++)
			{
				if(!flag[i]&&(table[i].from-tt>1||(table[i].from-tt==1&&tt%2==0)))
				{	changed=1;flag[i]=1;tt=table[i].to;}
			}
			if(changed)	total+=10;
			else	break;
		}
		cout<<total<<endl;
	}
	return 0;
 }




