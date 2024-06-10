#include <iostream>
using namespace std;

#define SPRING (1 << 0)
#define SAMMER (1 << 1)
#define AUTUMN ((1 << 1) + (1 << 0))
#define WINTER (1 << 2)


void spring()
{
	cout << "SPRING" << endl;
}

void sammer()
{
	cout << "SAMMER" << endl;
}

void autumn()
{
	cout << "AUTUMN" << endl;
}

void winter()
{
	cout << "WINTER" << endl;
}

//#if SPRING
#if SAMMER
//#if AUTUMN
//#if WINTER

int main()
{
	#if 0
	spring();
	#endif
	//#if 0
	sammer();
	#endif
	#if 0
	autumn();
	#endif
	#if 0
	winter();
	#endif
}
