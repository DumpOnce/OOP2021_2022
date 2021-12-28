#pragma once
#include "../bullet.hpp"
class AutoRocket;
#define MISSILE_DEFAULT_DAMAGE 1000
class MissileRocket :public bullet {

private:
	std::shared_ptr<AutoRocket> target;
public:
	MissileRocket(std::shared_ptr<updater> update,std::shared_ptr<AutoRocket>, int ang, int sp, float x, float y, int damage);
	MissileRocket(std::shared_ptr<fighter>, std::shared_ptr<AutoRocket>,int);
	bool update();
	bool isEqualPosition(std::shared_ptr<AutoRocket>){}
};