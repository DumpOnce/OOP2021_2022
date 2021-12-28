#pragma once
#include "../fighter.hpp"

class Masker:virtual public fighter {
protected:
	float changabillityR;
	float decreaseDetectionRate;
public:
	Masker(std::weak_ptr<updater> update, int sp, int ang, int x, int y, int dRad, int changeRate, int decreaseRate);
	float getDecreaseDetectionRate() { return decreaseDetectionRate; }
	float changabillityRate() { return changabillityR; }
	void Shoot(const Point&) {}
	std::string getType() { return "Masker"; }
	void Shoot(std::shared_ptr<fighter>){}
};