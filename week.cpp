#include <iostream>
using namespace std;

#define mon (1 << 0) 
#define tue (1 << 1) 
#define wed ((1 << 1) + (1 << 0))
#define thu (1 << 2)
#define fri ((1 << 2) + (1 << 0))
#define sat ((1 << 2) + (1 << 1))
#define sun ((1 << 2) + (1 << 1) + (1 << 0))
#define mon_day "Monday"
#define tue_day "Tuesday"
#define wed_day "Wednesday"
#define thu_day "Thursday"
#define fri_day "Friday"
#define sat_day "Saturday"
#define sun_day "Sunday"
#define week(value, day) value ## _ ## day

int main()
{
	int day = 1;
	while (day != -1)
	{
		cout << "Input week day: ";
		cin >> day;
		if ((day < 1 || day > 7) && day != -1)
			cerr << "Input error.Try again" << endl;
		else
		{
			if (day == mon) cout << week(mon, day) << endl;
			if (day == tue) cout << week(tue, day) << endl;
			if (day == wed) cout << week(wed, day) << endl;
			if (day == thu) cout << week(thu, day) << endl;
			if (day == fri) cout << week(fri, day) << endl;
			if (day == sat) cout << week(sat, day) << endl;
			if (day == sun) cout << week(sun, day) << endl;
		}
	}
}