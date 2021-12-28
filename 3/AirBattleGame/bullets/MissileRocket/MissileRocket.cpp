#include "MissileRocket.hpp"
#include "../../Game/Math/Math.hpp"
#include "../AutoRocket/AutoRocket.hpp"
#include "../../Game/GameAux/GameAux.hpp"
#include "../../planes/fighter.hpp"

MissileRocket::MissileRocket(std::shared_ptr<updater> update, std::shared_ptr<AutoRocket>bul, int ang, int sp, float x, float y, int damage = 1000):
	bullet(update,ang,sp,x,y,damage),target(bul) {};

MissileRocket::MissileRocket(std::shared_ptr<fighter> plane, std::shared_ptr<AutoRocket> targ,int damage = MISSILE_DEFAULT_DAMAGE):
	bullet(plane->getUpdater().lock(),plane->getAngle(),plane->getSpeed(),plane->getX(),plane->getY(), damage)
{

}


bool MissileRocket::update()
{

	Vector a(target->getX() - (int)pos.first, target->getY() - (int)pos.second);
	Vector vec(1, 0);
	angle = MATH::normalisation(MATH::angleBetweenVectors(a, vec));// We find angle between OX and Vector a

	float x1 = pos.first;
	float y1 = pos.second;
	float x = pos.first + std::cos((angle * 3.14) / 180) * speed;
	float y = pos.second + std::sin((angle * 3.14) / 180) * speed;

	distance += sqrt(pow(x - x1, 2) + pow(y - y1, 2));
	if (distance > maxDistance || GameAux::isFighterAttackedByBullet(target,shared_from_this()))
	{
		return true;
	}
	pos.first = x;
	pos.second = y;
	return false;


}
