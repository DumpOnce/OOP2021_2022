#include "Rocket.hpp"
#include "../../../planes/MissileDefence/MissileDefence.hpp"
#include "../../../planes/fighter.hpp"
#include "../../../planes/RElectronics/RElectronics.hpp"
#include "../../info/Link/Link.hpp"
#include "../../bullets/AutoRocket/AutoRocket.hpp"
#include "../../bullets/MissileRocket/MissileRocket.hpp"
//void Rocket::Shoot(std::shared_ptr<fighter> plane) {
//    int damage = ROCKET_DAMAGE;
//}
void Rocket::Shoot(std::shared_ptr<fighter> plane, double damageRatio,std::shared_ptr<fighter> host) {
   // plane->getDamage(GUN_DAMAGE * damageRatio);
}

void Rocket::Shoot(std::shared_ptr<MissileDefence> def, std::shared_ptr<fighter>plane, double ratio,std::shared_ptr<fighter> host)
{
    std::shared_ptr<AutoRocket> roc = std::make_shared<AutoRocket>(plane,ROCKET_DAMAGE);
    if (rand() % 2 == 0&&roc)
    {
        std::shared_ptr<MissileRocket> misRoc = std::make_shared<MissileRocket>(host,roc,MISSILE_DEFAULT_DAMAGE);
    }
}

void Rocket::Shoot(const Point& pos) {
    /*
        Here we can check if vector not leaning in attack sector - not to shoot
    */
   
    //std::shared_ptr<HomingRocket> rocket(new HomingRocket);
    //planeShip.lock()->getLink()->table->addElement(rocket);
}
void Rocket::Shoot(std::shared_ptr<fighter>host)//< We need to pull rocketBomb
{

}