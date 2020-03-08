 #include<iostream.h>
 #include<iomanip.h>

 int main(){
	int hour,minute;
	cout<<"Problem 3 by team x"<<endl;
	cout<<"=============================================================================="<<endl;

	cout<<" True     True     Minutes From   Minutes From   Discrepancy  Swapped  Swapped"<<endl;
	cout<<"Hours  Minutes   Minute Hand In   Hour Hand In    Of Minutes    Hours  Minutes"<<endl;
	cout<<"                  Swapped Clock  Swapped Clock"<<endl;

	cout<<"=============================================================================="<<endl;


	while(cin>>hour>>minute){
		cout<<setw(5)<<hour<<setw(9)<<minute;
		int min;
		if(hour==12) min=(5*minute)/60;
		else min=hour*5+(5*minute)/60;
		int temp=(minute*5)%60;
		if(temp>=30) min++;


		if(min>=60) min=60-min;
		cout<<setw(17)<<min;
		int hh=(minute%5)*12;

		cout<<setw(15)<<hh;
		int tt=min-hh;
		if(tt<0) tt=-tt;
		if(tt>30) tt=60-tt;
		cout<<setw(14)<<tt;
		if(tt>12) cout<<setw(9)<<"--"<<setw(9)<<"--";
		else{int t_hour=minute/5;if(t_hour==0) t_hour=12;
			cout<<setw(9)<<t_hour<<setw(9)<<min;
		}
		cout<<endl;
	}
	cout<<"=============================================================================="<<endl;

	cout<<"End of problem 3 by team x"<<endl;


	return 0;
 }