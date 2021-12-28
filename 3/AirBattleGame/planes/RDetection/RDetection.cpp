#include "RDetection.hpp"
#include "../../armour/Gun/Gun.hpp"
#include"../../armour/Rocket/Rocket.hpp"
#include <random>
#include "../../../info/Link/Link.hpp"
#include "../../Game/GameAux/GameAux.hpp"
#include "../Masker/Masker.hpp"
#include "../../Game/Math/Math.hpp"
#include "../MissileDefence/MissileDefence.hpp"
RDetection::RDetection(std::weak_ptr<updater> update, int sp, int ang, int x, int y, int dRad, int maskRate)
	:fighter(update, sp, ang, x, y, dRad), 
	ignoreMaskerRate(maskRate) ,armour2(std::make_shared<Rocket>(update.lock()))
{};

void RDetection::Shoot(std::shared_ptr<fighter> plane)
{
	double chance = 1.0;
	double newViewDistance = dRadius;
	double ratio = 1;
	double changeRate = 0;
	std::shared_ptr<Link> lnk = plane->getLink().lock();
	if (auto elem = GameAux::isMaskerInLink(lnk)) {
		newViewDistance = dRadius - dRadius * elem->changabillityRate();
		changeRate = elem->changabillityRate();
	}
	Point p1(pos.first, pos.second);
	Point p2(plane->getX(), plane->getY());
	std::random_device rd;
	std::mt19937 gen(rd());
	if (1.0 -changeRate >= 0 && 1.0 - changeRate <= std::generate_canonical<double, 10 >(gen)) {
		if (lnk->targets.count(plane) > 0 && !is_visible(plane)) {
			auto missile = GameAux::isMissileInLink(lnk);
			armour2->Shoot(missile, plane, ratio,std::dynamic_pointer_cast<RDetection>(shared_from_this()));// Shoot from rocket
			/// Next we need to activate MissileDefence
		}
		else if (lnk->targets.count(plane) < 0 && is_visible(plane)) {
			lnk->targets.insert(plane);
			setOrder(plane);
			armour->Shoot( plane, ratio,std::dynamic_pointer_cast<RDetection>(shared_from_this()));//Shoot from gun
		}
	}
}