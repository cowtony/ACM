 #include<iostream.h>


 int is_leap(int year)
 {
	if(year>=1752)
	{
		if(year%400==0||(year%4==0&&year%100!=0))
			return 1;
	}
	else if(year%4==0) return 1;
	return 0;
 }




 int get_day(int year)
 {
	if(is_leap(year)) return 366;
	return 365;
 }

 int get_day(int year,int month)
 {
	switch(month)
	{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			return 31;
		case 4:case 6:case 9:case 11:
			return 30;
		case 2:
			if(is_leap(year)) return 29;
			else return 28;

	}
	return 0;
 }

 int is_valid(int year,int month,int day)
 {
	if(year==1752&&month==9&&day>2&&day<14)
		return 0;



	if(day<=0||day>get_day(year,month))
		return 0;
	return 1;
 }



 void output(int year,int month,int day,int addday)
 {

	switch(month)
	{
		case 1:cout<<"January";break;
		case 2:cout<<"February";break;
		case 3:cout<<"March";break;
		case 4:cout<<"April";break;
		case 5:cout<<"May";break;
		case 6:cout<<"June";break;
		case 7:cout<<"July";break;
		case 8:cout<<"August";break;
		case 9:cout<<"September";break;
		case 10:cout<<"October";break;
		case 11:cout<<"November";break;
		case 12:cout<<"December";break;
	}
	cout<<" "<<day<<", "<<year<<" is a ";
	switch(addday)
	{
		case 0:cout<<"Sunday";break;
		case 1:cout<<"Monday";break;
		case 2:cout<<"Tuesday";break;
		case 3:cout<<"Wednesday";break;
		case 4:cout<<"Thursday";break;
		case 5:cout<<"Friday";break;
		case 6:cout<<"Saturday";break;
	}
	cout<<endl;

 }
 int count_day(int year,int month,int day,int flag=0)
 {
	int return_day=0;
	int i;
	if(flag==0)
	{
		if(year==1752)
		{
			if(month==9)
			{
				return_day=day-14;
			}
			else
			{
				return_day+=16;
				for(i=10;i<month;i++)
				{
					return_day+=get_day(1752,i);
				}
				return_day+=day;
				return_day%=7;
			}
		}
		else
		{
			return_day+=16;
			for(i=10;i<=12;i++)
			{
				return_day+=get_day(1752,i);
			}
			for(i=1753;i<year;i++)
			{
				return_day+=get_day(i);
				return_day%=7;
			}

			for(i=1;i<month;i++)
			{
				return_day+=get_day(year,i);
			}
			return_day+=day;
			return_day%=7;
		}
	}



	else
	{
		if(year==1752)
		{
			if(month<9)
			{
				return_day+=get_day(1752,month)-day+1;
				for(i=month+1;i<9;i++)
				{
					return_day+=get_day(1752,i);
				}
				return_day+=1;
				return_day%=7;
			}
			else
			{
				if(day==1) return_day=1;
				else return_day=0;
			}
		}
		else
		{
			return_day+=get_day(year,month)-day+1;
			for(i=month+1;i<=12;i++)
			{
				return_day+=get_day(year,i);
			}
			return_day%=7;
			for(i=year+1;i<1752;i++)
			{
				return_day+=get_day(i);
				return_day%=7;
			}
			for(i=1;i<9;i++)
			{
				return_day+=get_day(1752,i);
			}
			return_day+=1;
			return_day%=7;
		}
	}
	return return_day;
 }





 int main()
 {
	int year; int month;int day;
	cin>>month>>day>>year;
	while(year!=0||month!=0||day!=0)
	{
		if(!is_valid(year,month,day))
		{
			cout<<month<<"/"<<day<<"/"<<year<<" is an invalid date\n";


		}
		else if(year<1752||(year==1752&&(month<9||(month==9&&day<3))))
		{
			int dd=count_day(year,month,day,1);
			output(year,month,day,(10-dd)%7);
		}
		else
		{
			int dd=count_day(year,month,day);
			output(year,month,day,(4+dd)%7);
		}

		cin>>month>>day>>year;



	}
	return 0;
 }








