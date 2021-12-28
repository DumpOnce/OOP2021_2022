#include "MissileDefence.hpp"
#include "../../armour/Rocket/Rocket.hpp"


MissileDefence::MissileDefence(std::weak_ptr<updater> up, int angle, int x, int y, int sp, int radius, int roc) :rockets(roc), fighter(up, sp, angle, x, y, radius)
{
	armRocket = std::make_shared<Rocket>(up.lock());
}