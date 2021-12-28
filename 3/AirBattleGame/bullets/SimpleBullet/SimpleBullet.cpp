#include "SimpleBullet.hpp"
#include "../../Game/GameAux/GameAux.hpp"

SimpleBullet::SimpleBullet(std::shared_ptr<updater> update, int ang, int sp, float x, float y, int damage) 
	:bullet(update, damage, ang, sp, x, y) {}

bool SimpleBullet::update()
{
	float x1 = pos.first;
	float y1 = pos.second;
	float x = x = pos.first + std::cos((angle * 3.14) / 180) * speed ;
	float y = y = pos.second + std::sin((angle * 3.14) / 180) * speed ;

	distance += sqrt(pow(x - x1, 2) + pow(y - y1, 2));
	if (distance > maxDistance) 
	{
		return true;
	}
	pos.first = x;
	pos.second = y;
	return false;
}