#include "Header.h"
Figure::Cissoida::Cissoida(float a) :a(a){}

float Figure::Cissoida::getR(float deg)const
{
	deg = pi * (deg / 180.0);
	return (2 * abs(this->a) * ((1 / cos(deg)) - cos(deg)));
}

float Figure::Cissoida::getpar()const {
	float deg = 30;
	deg = pi * (deg / 180.0);
	return (2 * ((this->a * ((1 / cos(deg)) - cos(deg)) * (pow((sin(deg)), 2)) / (cos(deg)))));
}


float Figure::Cissoida::retY(float x)const {
			return sqrt((x * x * x) / (2 * this->a - x));;
		
}


float Figure::Cissoida::squareAsymp() const { return (2.0 * pi * this->a * this->a); }

float Figure::Cissoida::getCoef()const { return 2 * a; }

void Figure::Cissoida::setA(float a)//Изменить A
{
	this->a = a;
}


float Figure::Cissoida::getA()const { return this->a; }

float Figure::Cissoida::volumeCount() const {
	return (10 * (pow(pi, 2)) * pow(abs(a), 3));
}
