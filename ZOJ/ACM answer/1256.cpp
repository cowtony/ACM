 //56650 2002-11-23 00:25:43 Accepted 1256 C++ 00:00.00 436K Century Ghost
 #include<iostream.h>
 #include<string.h>

 int isleapyear(int year)
 {
	if(year<1753&&year%4==0)	return 1;
	if((year%4==0&&year%100!=0)||year%400==0)	return 1;
	return 0;
 }
 int year_day(int year)
 {
	if(year==1752)	return 355;
	if(isleapyear(year))	return 366;
	return 365;
 }
 int month_day(int year,int month)
 {
	if(year==1752&&month==9)	return 19;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		return 31;
	if(month==4||month==6||month==9||month==11)	return 30;
	if(isleapyear(year))	return 29;
	return 28;
 }
 int wrong(int year,int month,int day)
 {
	if(day<1||day>31)	return 1;
	if(month<1||month>12)	return 1;
	if(year==1752&&month==9)
	{	if((day>2&&day<14)||day>30)	return 1;
		return 0;
	}
	if(day>month_day(year,month))	return 1;
	return 0;
 }

 int main()
 {
	int month,day,year;
	char week[7][10];char mm[14][20];
	strcpy(week[0],"Sunday");strcpy(week[1],"Monday");strcpy(week[2],"Tuesday");
	strcpy(week[3],"Wednesday");strcpy(week[4],"Thursday");
	strcpy(week[5],"Friday");strcpy(week[6],"Saturday");
	strcpy(mm[1],"January");strcpy(mm[2],"February");strcpy(mm[3],"March");strcpy(mm[4],"April");
	strcpy(mm[5],"May");strcpy(mm[6],"June");strcpy(mm[7],"July");strcpy(mm[8],"August");
	strcpy(mm[9],"September");strcpy(mm[10],"October");strcpy(mm[11],"November");strcpy(mm[12],"December");

	while(1)
	{
		cin>>month>>day>>year;
		if(month==0&&day==0&&year==0)	break;
		if(wrong(year,month,day))
		{	cout<<month<<"/"<<day<<"/"<<year<<" is an invalid date."<<endl;
			continue;
		}
		int sum=0;int i;
		if(year>=2000)
		{
			for(i=2000;i<year;i++)
				sum=(sum+year_day(i))%7;
			for(i=1;i<month;i++)
				sum=(sum+month_day(year,i))%7;
			sum=(sum+(day-1))%7;
			sum=(sum+6)%7;

		}
		else
		{
			int temday;
			if(year==1752&&month==9)
			{	if(day<=2)	temday=20-day;
				else	temday=31-day;
			}
			else	temday=month_day(year,month)-day+1;
			sum=(temday)%7;
			for(i=month+1;i<=12;i++)
				sum=(sum+month_day(year,i))%7;
			for(i=year+1;i<2000;i++)
				sum=(sum+year_day(i))%7;
			sum=sum%7;
			sum=(13-sum)%7;
		}

		cout<<mm[month]<<" "<<day<<", "<<year<<" is a "<<week[sum]<<endl;
	}
	return 0;
 }

