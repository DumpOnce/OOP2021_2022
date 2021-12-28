#include "menu.h"

const char* msgs[] = { "0. Выйти",
"1. Вернуть координату y в декартовой системе координат, принадлежащую циссоиде в зависимости от x",
"2.Вернуть расстояние до центра в полярной системе координат в зависимости от угла",
"3.Вернуть коэффициент в уравнении асимптоты UV",
"4. Вернуть площадь полосы между циссоидой и ее асимптотой.",
"5. Вернуть объем тела, полученной вращением полосы из пункта 6 вокруг асимптоты UV",
"6. Вернуть коэффициенты в уравнении параболы такой, что основания перпендикуляров, опущенных из вершины параболы на ее касательные, образуют данную циссоиду.","7.Изменить a.","8.Вернуть параметр a."};





const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

template <class T>
int getNum(T& a)
{
	int rc = 0;
	std::cin >> a;
	if (!std::cin.good())
		rc = 1;				// Обнаружена ошибка ввода
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return rc;
};

/*Figure::Cissoida& makeCis() {
	float a;
	do {
		std::cout << "Enter a:\n";
		std::cin >> a;
	} while (a == 0);
	Figure::Cissoida cis(a);
	return cis;
}*/


int dialog(const char* msgs[], int N)
{
	const char* errmsgs = "";
	int rc, i;
	do
	{
		puts(errmsgs);
		errmsgs = "Ошибка! Повторите ввод!";
		for (i = 0; i < N; ++i)					// Вывод списка альтернатив
		{
			puts(msgs[i]);
		}
		printf("Выберите: --> ");
	} while (getNum(rc) < 0 || rc >= N);
	return rc;
}
