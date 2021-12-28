#include <cstdlib>
#include <time.h>
#include <conio.h>
#include "Capsule.h"
#include <vld.h>

int(*fptr[])(Figure::Cissoida&) = { NULL, returnY,  returnRadius,returnAsympCoef, returnSquare, returnVolume, returnParabolaC,changeA,getCisA };
extern const char* msgs[];

int main() 
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	std::cout << "Enter a:\n";
	float a;
	std::cin >> a;
	Figure::Cissoida cis = Figure::Cissoida(a);//Здесь необходимо определить состояние класса
	int rc;
	while ((rc = dialog(msgs, NMsgs)))
	{
		if (!fptr[rc](cis))
		{
			break;
		}
	}
	return 0;
}




