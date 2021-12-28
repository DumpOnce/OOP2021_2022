#pragma once
#include "../fighter.hpp"
class updater;
class Rocket;
class MissileDefence :public fighter {
private:
	int rockets;
	std::shared_ptr<Rocket> armRocket;
	// New type of armour RocketPuller
public:
	int getRockets() { return rockets; }
	void Shoot(std::shared_ptr<bullet>) {};
	void Shoot(std::shared_ptr<fighter>) {};
	void Shoot(const Point&){}
	std::string getType() { return "MissileDefence"; }
	MissileDefence(std::weak_ptr<updater> up, int angle, int x, int y, int sp, int radius, int roc);
};