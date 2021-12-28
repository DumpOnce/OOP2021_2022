#include "Gun.hpp"
#include "../../../planes/Scout/Scout.hpp"
#include"../../info/Link/Link.hpp"
#include "../../planes/RElectronics/RElectronics.hpp"
#include "../../UI/UI.hpp"
#include "../../Game/Math/Math.hpp"
#include "../../Game/GameAux/GameAux.hpp"
#include "../../bullets/SimpleBullet/SimpleBullet.hpp"

void Gun::Shoot(std::shared_ptr<fighter> plane, double damageRatio,std::shared_ptr<fighter>host) {
    std::shared_ptr<SimpleBullet> bul = std::make_shared<SimpleBullet>(upd, host->getAngle(),host->getSpeed(), host->getX(), host->getY(), damageRatio * GUN_DAMAGE);
}
void Gun::Shoot(const Point& pos) {
    /*here need to check |angle|<=viewAngle*/
   // std::shared_ptr<bullet> bul = std::make_shared<bullet>(planeShip.lock()->getUpdater().lock(), planeShip.lock()->getAngle(), planeShip.lock()->getSpeed(), planeShip.lock()->getX(), planeShip.lock()->getY());
}
void Gun::Shoot(std::shared_ptr<fighter> host)
{
    std::shared_ptr<SimpleBullet> bul = std::make_shared<SimpleBullet>(upd, host->getAngle(),host->getSpeed(), host->getX(), host->getY(),   GUN_DAMAGE);
}
