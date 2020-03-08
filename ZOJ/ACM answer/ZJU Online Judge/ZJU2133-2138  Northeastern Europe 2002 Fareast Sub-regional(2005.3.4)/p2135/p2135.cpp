#include <cstdio>
#include <cstring>

#define DEBUG

char MonthName[12][30] = {"JANUARY" , "FEBRUARY" , "MARCH" , "APRIL" , "MAY" , "JUNE" ,
					 "JULY" , "AUGUST" , "SEPTEMBER" , "OCTOBER" , "NOVEMBER" , "DECEMBER"};
int MonthDay [12] = {31,28,31,30,31,30,31,31,30,31,30,31};

char M[10*200 * 3][20 * 4];
int Line = 0;
int Weight = 18 * 12 / 3;

inline int GetDay(int Year , int Month)
{
	if(Month == 1) // February
	{
		if((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0) return 29;
		else return 28;
	}
	else return MonthDay[Month];
}

void Fill_Month(int R , int C , int MonthID)
{
	for(int i=0; MonthName[MonthID][i]; i++)
	{
		M[R][C + i] = MonthName[MonthID][i];
	}
}

void Fill_Day(int R , int C , int DayID)
{
	if(DayID >= 10) M[R][C] = DayID / 10 + '0';
	M[R][C+1] = DayID % 10 + '0';
}

void Gen_Calendar()
{
	// from 1900.Jan.1
	// Each year , 9(row) * (18 * 12)

	int YearID , MonthID , DayID , Days;
	int WeekID = 0;
	
	int PCol , curtCol;
	int i , j;

	for(YearID = 1900; YearID <= 2100; YearID ++)
	{
		for(i=0; i<9*3; i++)
			for(j=0; j<Weight; j++)
				M[Line + i][j] = '.';
		PCol = 0;
		for(MonthID = 0; MonthID < 12; MonthID ++)
		{
			Days = GetDay(YearID , MonthID);
			curtCol = PCol;

			Fill_Month(Line , curtCol + 1 , MonthID);

			for(DayID = 1; DayID <= Days; DayID ++)
			{
				WeekID++;
				if(WeekID > 7)
				{
					WeekID = 1; 
					if(DayID != 1) curtCol	+= 3;
				}
				Fill_Day(Line + WeekID , curtCol , DayID);
			}
			
			PCol += 18;

			if(MonthID % 4 == 3)
			{
				Line += 9;
				PCol = 0;
			}
		}		
	}

	#ifdef DEBUG
	FILE* fdebug = fopen("calendar.txt" , "w");

	for(i=0; i<Line; i++)
	{
		for(j=0; j<Weight; j++)
		{
			fprintf(fdebug , "%c" , M[i][j]);
		}
		fprintf(fdebug , "\n");
	}	
	#endif
}

int n , m;
char CM[12][12];

bool Judge_Same(int R , int C)
{
	int i , j;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(M[R+i][C+j] != CM[i][j]) return 0;
	return 1;
}

void Solve()
{
	int i , j;
	scanf("%d%d" , &m , &n);
	for(i=0; i<n; i++)	
		scanf("%s" , CM[i]);

	int prev = 0;
	int curt;
	bool found = 0;

	for(i=0; i+n<=Line; i++)
	{
		curt = i / 27 + 1900;
		if(curt == prev) continue;
		for(j=0; j+m<=Weight; j++)
		{
			if(Judge_Same(i , j))
			{
				prev = curt;
				if(curt >= 1900) printf("%d\n" , curt);
				found = 1; 
				break;
			}
		}
	}

	if(!found) puts("0");
}

int main()
{
	freopen("in.txt" , "r" , stdin);

	Gen_Calendar();

	int T;
	scanf("%d" , &T);
	while(T--)
	{
		Solve();
		if(T) putchar('\n');
	}

	return 0;
}