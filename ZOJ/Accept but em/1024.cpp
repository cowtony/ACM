 //79442 2003-02-26 23:36:52 Accepted 1024 C++ 00:00.01 600K Century Ghost
 #include<iostream.h>

 int state[102][13][32];

 int outofrange(int year,int month,int day)
 {
	if(year==101&&(month>11||(month==11&&day>4)))	return 1;
	return 0;
 }
 int isleap(int year)
 {
	if((year%4==0&&year%100!=0)||year%400==0)	return 1;
	return 0;
 }
 int monthday(int year,int month)
 {
	if(month==2)
	{	if(isleap(year))	return 29;
		else	return 28;
	}
	if(month==4||month==6||month==9||month==11)	return 30;
	return 31;
 }

 int valid(int year,int month,int day)
 {
	if(outofrange(year,month,day))	return 0;
	if(day>monthday(year,month))	return 0;
	return 1;

 }
 void calnextday(int year,int month,int day,int& nextyear,int& nextmonth,int&nextday)
 {
	nextday=day+1;
	if(nextday>monthday(year,month))
	{	nextday=1;
		if(month==12){nextmonth=1;nextyear=year+1;}
		else{nextmonth=month+1;nextyear=year;}
	}
	else{nextmonth=month;nextyear=year;}
 }


 int getval(int year,int month,int day)
 {
	int nextyear,nextmonth,nextday;
	calnextday(year,month,day,nextyear,nextmonth,nextday);
	if(!state[nextyear][nextmonth][nextday])	return 1;
	nextday=day;
	if(month==12){	nextmonth=1;nextyear=year+1;}
	else   {	nextmonth=month+1;nextyear=year;}
	if(nextday>monthday(nextyear,nextmonth))		return 0;
	if(outofrange(nextyear,nextmonth,nextday))	return 0;
	if(!state[nextyear][nextmonth][nextday])	return 1;
	return 0;
 }



 int main()
 {
	int n;
	state[101][11][4]=0;
	int i,j,t;
	for(i=101;i>=0;i--)
		for(j=12;j>=1;j--)
			for(t=31;t>=1;t--)
			{
				if(!valid(i,j,t))	continue;
				state[i][j][t]=getval(i,j,t);
				state[101][11][4]=0;
			}
	cin>>n;
	while(n--)
	{
		int year,month,day;
		cin>>year>>month>>day;
		year-=1900;
		if(state[year][month][day])	cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	return 0;
 }




