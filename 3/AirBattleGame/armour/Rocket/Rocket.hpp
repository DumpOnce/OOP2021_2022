#pragma once
/////////////////
/// Headers
/////////////////
#include "../Armour.hpp"
#include <memory>
class MissileDefence;
class AutocontrolBullet;
class Rocket :public Armour {
	int rocketCount;
public:
	Rocket(std::shared_ptr<updater> f ,int rCount = 5, float fireRate = 5 ) :rocketCount(rCount),Armour(f,fireRate) {}
	void Shoot(std::shared_ptr<fighter>, double,std::shared_ptr<fighter>) ;
	void Shoot(std::shared_ptr<MissileDefence>, std::shared_ptr<fighter>, double,std::shared_ptr<fighter>);
	void Shoot(std::shared_ptr<fighter>);
	void Shoot(const Point&);
	void Shoot(std::shared_ptr<AutocontrolBullet>) {}
};