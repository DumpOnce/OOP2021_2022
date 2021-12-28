#pragma once
/////////////////
/// Headers
/////////////////
#include "../Armour.hpp"

///////////////////////////////
///
/// \brief Armour, attack only with bullets,
/// and no rockets
/// 
//////////////////////////////
class Gun : public Armour {
private:
	int gunCount;
public:
	// Getters
	int getGunCoumt() { return gunCount; }

	Gun(std::shared_ptr<updater>f ,int gCount = 5,int fRate = 2) :gunCount(gCount), Armour(f,fRate) {};

	//Other functions
	void Shoot(std::shared_ptr<fighter>, double,std::shared_ptr<fighter>);
	void Shoot(const Point&);
	void Shoot(std::shared_ptr<fighter>);
};