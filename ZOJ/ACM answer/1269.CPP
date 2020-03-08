 //accepted

 #include<iostream.h>
 int test(long time,long nn,long num)
 {
	if(time==num+1){	if(nn%num==0) return 1;}
	if((nn-1)%num!=0) return 0;
	if(test(time+1,((nn-1)/num)*(num-1),num)) return 1;
	return 0;
 }


 int main()
 {
	long nn;
	while(1)
	{
		cin>>nn;
		if(nn<=0) 	break;
		long pos=0;
		long i;
		for(i=2;i<=nn;i++)
		{
			if(test(1,nn,i))	pos=i;
		}
		if(pos==0) cout<<nn<<" coconuts, no solution"<<endl;
		else cout<<nn<<" coconuts, "<<pos<<" people and 1 monkey"<<endl;
	}
	return 0;
 }
