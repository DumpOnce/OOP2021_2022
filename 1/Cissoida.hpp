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
		float a;///�����������, ������������ ���� ��������
	public:
		explicit Cissoida(float a = 1);
		float getA()const;///������� a
		void setA(float a);///���������� �
		float getpar()const;/// ������� ��������� ��������
		float retY(float x)const;///������� Y
		float getCoef()const;
		float squareAsymp() const;//
		float getR(float deg)const;
		float volumeCount() const;
	};
}