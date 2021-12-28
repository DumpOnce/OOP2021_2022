#pragma once
#include "../../Game/Math/Math.hpp"
#include "../bullet.hpp"
class SimpleBullet:public bullet {
private:
	
public:
	SimpleBullet(std::shared_ptr<updater> update, int ang, int sp, float x, float y, int damage);
	bool update();
};