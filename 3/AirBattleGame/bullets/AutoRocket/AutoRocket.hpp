#pragma once
#include "../bullet.hpp"
class fighter;
#define ROCKET_DAM 1500
class AutoRocket:public bullet {
private:
	std::shared_ptr<fighter> target;
public:
	AutoRocket(std::shared_ptr<updater> update,std::shared_ptr<fighter>, int ang, int sp, float x, float y, int damage);
	AutoRocket(std::shared_ptr<fighter> , std::shared_ptr<fighter>,int = ROCKET_DAM);
	AutoRocket(std::shared_ptr<fighter>,int = ROCKET_DAM);
	bool update();

};