#include "../fighter.hpp"
#pragma once
class Rocket;
class RDetection:virtual public fighter 
{
public:
	RDetection(std::weak_ptr<updater> update, int sp, int ang, int x, int y, int dRad, int maskRate);
	int getMaskRate() { return ignoreMaskerRate; }
	void Shoot(const Point&) { std::cout << "RDetection-Shoot\n"; };
	void Shoot(std::shared_ptr<fighter>);
	std::string getType() { return "RDetection"; }

protected:
	float ignoreMaskerRate;
	std::shared_ptr<Rocket> armour2;
};
