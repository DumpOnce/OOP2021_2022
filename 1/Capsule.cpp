#pragma once
#include "Capsule.h"



//Здесь находятся функции-оболочки для нашкй менюшки

int returnY(Figure::Cissoida& cis) {
	float x;
	do {
		try {
			std::cout << "Print x:\n";
			std::cin >> x;
			if (cis.getA() > 0) {
				if (x == cis.getA() * 2 || x < 0 || x > 2 * cis.getA()) {
					throw 404;
				}
				if (x == INFINITY) {
					throw "inf";
				}
				break;
			}
			else {
				if (x < cis.getA() * 2) {
					throw 100;
				}
				if (2 * cis.getA() == x) {
					throw"inf";
				}
				break;
			}
		}
		catch (int) {
			std::cout << "Деление на ноль/угроза извлечения отрицательного корня в выражении Y!\n";
		}
		catch (const char*) {
			std::cout << "X == бесконечности!Повторите ввод!\n";
		}
	} while (1);
	int choose;
	do {
		std::cout << "Вывести положительное или отрицательное число?(1/0)\n";
		std::cin >> choose;
		float res;
		switch (choose) {
		case 1:
			std::cout << cis.retY(x) << std::endl;;
		case 0:
			std::cout << -cis.retY(x) << std::endl;;
		}
	} while (choose != 1 && choose != 0);
	return 1;
}
int returnVolume(Figure::Cissoida& cis) {
	std::cout << cis.volumeCount() << std::endl;
	return 1;
}

int returnRadius(Figure::Cissoida& cis) {
	float deg;
	do {
		try {
			std::cout << "Print deg:\n";
			std::cin >> deg;
			if (deg == INFINITY) {
				throw 100;
			}
			break;
		}
		catch (int)
		{
			std::cout << "Ошибка!Угол равен бесконечности!\n";
		}
	} while (1);
	std::cout<<cis.getR(deg)<<std::endl;
	return 1;
}

int returnSquare(Figure::Cissoida& cis) {
	std::cout << cis.squareAsymp() << std::endl;
	return 1;
}

int returnParabolaC(Figure::Cissoida& cis) {
	std::cout<<cis.getpar()<<std::endl;
	return 1;
}
int returnAsympCoef(Figure::Cissoida& cis) {
	std::cout<<cis.getCoef()<<std::endl;
	return 1;
}

int changeA(Figure::Cissoida& cis) {
	float a;
	std::cout << "Enter a\n";
	std::cin >> a;
	cis.setA(a);
	return 1;
}

int getCisA(Figure::Cissoida& cis) {
	std::cout << "Here is your a:" << cis.getA() << std::endl;
	return 1;
}
