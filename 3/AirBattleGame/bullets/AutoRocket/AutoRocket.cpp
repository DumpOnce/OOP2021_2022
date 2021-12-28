#include"AutoRocket.hpp"
#include "../../Game/Math/Math.hpp"
#include "../../planes/fighter.hpp"
#include "../../Game/GameAux/GameAux.hpp"

AutoRocket::AutoRocket(std::shared_ptr<updater> update,std::shared_ptr<fighter> target, int ang, int sp, float x, float y, int damage)
	:bullet(update, damage, ang, sp, x, y),target(target) {
	img = '0';
}

AutoRocket::AutoRocket(std::shared_ptr<fighter> f, int damage) :
	bullet(f->getUpdater().lock(), f->getAngle(), f->getSpeed(), f->getX(), f->getY(), damage) {};

AutoRocket::AutoRocket(std::shared_ptr<fighter> f, std::shared_ptr<fighter> attack,int damage) :
	bullet(f->getUpdater().lock(),f->getAngle(),f->getSpeed(),f->getX(),f->getY(),damage)
{

}

bool AutoRocket::update()
{
	Vector a(target->getX() - (int)pos.first, target->getY() - (int)pos.second);
	Vector vec(1, 0);
	angle = MATH::normalisation(MATH::angleBetweenVectors(a, vec));// We find angle between OX and Vector a

	float x1 = pos.first;
	float y1 = pos.second;
	float x =  pos.first + std::cos((angle * 3.14) / 180) * speed;
	float y =  pos.second + std::sin((angle * 3.14) / 180) * speed;

	distance += sqrt(pow(x - x1, 2) + pow(y - y1, 2));
	if (distance > maxDistance || GameAux::isFighterAttackedByBullet(target,shared_from_this()))
	{
		return true;
	}
	pos.first = x;
	pos.second = y;
	return false;
}