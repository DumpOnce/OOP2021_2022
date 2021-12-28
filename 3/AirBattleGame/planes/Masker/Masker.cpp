#include "Masker.hpp"
#include "../../armour/Gun/Gun.hpp"
Masker::Masker(std::weak_ptr<updater> update, int sp, int ang, int x, int y, int dRad, int changeRate, int decreaseRate) :changabillityR(changeRate), decreaseDetectionRate(decreaseRate), fighter(update, sp, ang, x, y, dRad) 
{
	armour = std::make_shared<Gun>(upd.lock());
};
