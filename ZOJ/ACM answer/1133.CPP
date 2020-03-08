 #include<iostream.h>
 #include<math.h>

 int apart(unsigned long temp)
 {
	int result=0;
	while(temp/10>0)
	{
		result+=temp%10;
		temp=temp/10;
	}
	result+=temp;
	return result;
 }

 int prime(unsigned long temp)
 {
	unsigned long i;
	double end=sqrt(temp);
	for(i=2;i<=end;i++)
		if(temp%i==0) return 0;
	return 1;
 }


 int yes(unsigned long temp)
 {
	if(prime(temp)) return 0;
	int add=apart(temp);
	unsigned long i;
	int t_add=0;
	while(1)
	{
		if(prime(temp)) break;
		double end=sqrt(temp);
		for(i=2;i<=end;i++)
		{

			if(!prime(i)) continue;
			if(temp%i==0){temp=temp/i;t_add+=apart(i);break;}
		}


	}
	t_add+=apart(temp);
	if(add!=t_add) return 0;
	return 1;
 }




 int main()
 {
	while(1)
	{
		unsigned long n;
		cin>>n;
		if(n==0) break;
		unsigned long temp;
		for(temp=n+1;;temp++)
		{
			if(yes(temp)) break;
		}
		cout<<temp<<endl;
	}
	return 0;
 }
