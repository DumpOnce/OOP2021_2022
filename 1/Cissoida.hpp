#pragma once
#define pi 3.14
#include <iostream>
#include <locale.h>


namespace Figure
{
	struct Ratios {
		double a;
		double b;
	};
	class Cissoida
	{
	private:
		float a;///Коэффициент, определяющий саму циссоиду
	public:
		explicit Cissoida(float a = 1);
		float getA()const;///Вернуть a
		void setA(float a);///Установить а
		float getpar()const;/// вернуть параметры параболы
		float retY(float x)const;///вернуть Y
		float getCoef()const;
		float squareAsymp() const;//
		float getR(float deg)const;
		float volumeCount() const;
	};
}