#include "bullet.hpp"
#include "../info/updater.hpp"
#include "../planes/fighter.hpp"
#include "../UI/UI.hpp"

bullet::bullet(std::shared_ptr<updater> update, int ang, int sp, float x, float y,int damage) :damage(damage),angle(ang), speed(sp),  pos(std::make_pair(x, y))
{
	upd = (update);
}

void bullet::addBul() {
	upd->addBullet(shared_from_this());
}

bool bullet::equalPosition(std::shared_ptr<bullet>bul)const
{
	if ((int)pos.first == (int)bul->getX() && (int)pos.second == (int)bul->getY())
	{
		return true;
	}
	return false;
}


bool bullet::equalPosition(std::shared_ptr<fighter> f) const{
	if ((int)pos.first ==(int)f->getPos().first && (int)pos.second == (int)f->getPos().second)
	{
		f->getDamage(2000);
		return true;
	}
	return false;
}