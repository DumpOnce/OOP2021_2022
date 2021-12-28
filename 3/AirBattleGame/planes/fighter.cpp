#include "fighter.hpp"
#include "../info/updater.hpp"
#include "../armour/Rocket/Rocket.hpp"
#include"../armour/Gun/Gun.hpp"
#include <memory>
#include"../UI/UI.hpp"
#include "../Game/Math/Math.hpp"
#include "../bullets/bullet.hpp"
//#include "../bullets/AbstractBullet/AbstractBullet.hpp"
fighter::fighter(std::weak_ptr<updater> update, int sp, int ang, int x, int y, int dRad) :dRadius(dRad), speed(sp), angle(ang), upd(update), pos(std::make_pair(x, y)) { angle = MATH::normalisation(ang); };

void fighter::setOrder(double x, double y) { orderPosition->x = x; orderPosition->y = y; }
void fighter::setOrder(Point& p) { orderPosition = std::make_shared<Point>(p); }

void fighter::breakOrder() { order = nullptr; }

bool fighter::operator ==(bullet& b)
{
	if (pos.first == b.getX()&&pos.second == b.getY())return true;
	return false;
}

 //update poistion
void fighter::update()
{

	// If order exist
	if (order) {
		if (is_visible(order))// We arent doint mild rotation
		{
			Vector a(orderPosition->x - pos.first, orderPosition->y - pos.second);
			Vector x(1, 0);
			angle = MATH::normalisation(MATH::angleBetweenVectors(a, x));// We find angle between OX and Vector a
		}
		else {
			breakOrder();
		}
	}
	float x = pos.first + std::cos((MATH::deg2Rad(angle))) * speed;
	float y = pos.second + std::sin((MATH::deg2Rad(angle))) * speed;
	if (x >= updater::width || x <= 1 || y >= updater::height || y <= 1)
	{
		rand() % 2 ? angle += 270 : angle += 180;
		x = pos.first + std::cos((MATH::deg2Rad(angle))) * speed;
		y = pos.second + std::sin((MATH::deg2Rad(angle))) * speed;
	}
	pos.first = x;
	pos.second = y;
	if (timeFrequencyNow == shotFrequency) {
		timeFrequencyNow = 0;
		if (order)
			Shoot(order);
	}
}
int fighter::getX()const { return pos.first; }
int fighter::getY() const
{
	return pos.second;
}
/**
	*Setting angle with forward normalization(on 360 degree)
*/
void fighter::setAngle(int ang) {
	angle = MATH::normalisation(ang);
}

void fighter::getDamage (int a) {
	hp -= a;
}

void fighter::Shoot()
{
	armour->Shoot(shared_from_this());
}

bool fighter::is_visible(std::shared_ptr<fighter> vrag)
{
	float distance = sqrt(pow(pos.first - vrag->getPos().first, 2) + pow(pos.second - vrag->getPos().second, 2));
	double dx = dRadius * cos((MATH::deg2Rad(angle)));
	double dy = dRadius * sin((MATH::deg2Rad(angle)));
	Vector v(dx, dy);
	std::pair<Vector, Vector> vectors = MATH::getViewVectors(angle,dRadius,v,view_angle);
	Vector check(pos.first,pos.second,vrag->getX(),vrag->getY());
	if (dRadius >= distance&&MATH::isBetween(vectors.first,vectors.second,check))
	{
		return true;
	}
	return false;
}