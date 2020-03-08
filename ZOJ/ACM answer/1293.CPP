 #include<iostream.h>
 #include<math.h>

 int main()
 {
	double  input;int count=0;
	while(1)
	{
		cin>>input;
		if(input<0.001)	break;
		double out;
		out=input*0.75/(1.86*1000*1000);
		long result=ceil(out);
		cout<<"File #"<<(++count)<<endl;
		cout<<"John needs "<<result<<" floppies."<<endl;
		cout<<endl;
	}
	return 0;
 }



