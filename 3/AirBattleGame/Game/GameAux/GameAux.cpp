#include "GameAux.hpp"
#include "../../planes/RElectronics/RElectronics.hpp"
#include "../../info/Table/Table.hpp"
#include "../../bullets/bullet.hpp"
#include "../../info/Link/Link.hpp"
#include "../../Game/Math/Math.hpp"
#include "../../bullets/AutoRocket/AutoRocket.hpp"
#include "../../planes/Masker/Masker.hpp"
#include "../../planes/MissileDefence/MissileDefence.hpp"
////////////////////////////////////////////////////////////////////
/// \brief A class with auxiliary functions that are used somewhere 
/// in the depth of the main functions for bullets and planes,
/// as well as updates
///
////////////////////////////////////////////////////////////////////
namespace GameAux
{
	std::shared_ptr<Masker> isMaskerInLink(std::shared_ptr<Link> lnk)
	{
		for (auto c : *lnk)
			if (auto elem = std::dynamic_pointer_cast<Masker>(c.second))
				return elem;
		return nullptr;
	}
	std::shared_ptr<MissileDefence> isMissileInLink(std::shared_ptr<Link> lnk)
	{
		for (auto c : *lnk)
			if (auto elem = std::dynamic_pointer_cast<MissileDefence>(c.second))
				return elem;
		return nullptr;
	}
	bool isFighterAttackedByBullet(std::shared_ptr<AutoRocket>rocket, std::shared_ptr<bullet>bul)
	{
		float x = rocket->getX() + std::cos((MATH::deg2Rad(rocket->getAngle()))) * rocket->getSpeed();
		float y = rocket->getY() + std::sin((MATH::deg2Rad(rocket->getAngle()))) * rocket->getSpeed();
		Vector Vec1(std::cos((bul->getAngle() * 3.14) / 180) * bul->getSpeed(),
			std::sin((bul->getAngle() * 3.14) / 180) * bul->getSpeed());
		Vector Vec2(
			x - bul->getX(),
			y - bul->getY()
		);
		if (MATH::angleBetweenVectors(Vec1, Vec2) <= 1)
			return true;
		return false;


	}
	bool isFighterAttackedByBullet(std::shared_ptr<fighter>plane, std::shared_ptr<bullet> bul)
	{
		float x = plane->getX() + std::cos((MATH::deg2Rad(plane->getAngle()))) * plane->getSpeed();
		float y = plane->getY() + std::sin((MATH::deg2Rad(plane->getAngle()))) * plane->getSpeed();
		Vector Vec1( std::cos((bul->getAngle() * 3.14) / 180) * bul->getSpeed(),
			std::sin((bul->getAngle() * 3.14) / 180) * bul->getSpeed());
		Vector Vec2(
			x-bul->getX(),
			y-bul->getY()
		);
		if (MATH::angleBetweenVectors(Vec1, Vec2) <= 1)
			return true;
		return false;
	}

	std::shared_ptr<fighter> targetHit(std::shared_ptr<Table>t, std::shared_ptr<bullet> b)
	{
		for (auto c : *t) {
			for (auto x : *c.second)
			{
				if (b->equalPosition(x.second)) {
					return x.second;
				}
			}
		}
		return nullptr;
	}
	//////////////////////////////////////////////////////////////////////
	/// \brief Check function to get Electronics plane
	/// 
	/// \param link shared_ptr on Link
	/// \return shared ptr to RElectronics if exist, nullptr - if NOT exist
	/// 
	///////////////////////////////////////////////////////////////////////
	std::shared_ptr<RElectronics> isElectronicsHere(std::shared_ptr<Link> link)
	{
		for (auto c : *link)
		{
			if (std::shared_ptr<RElectronics> fighter = std::dynamic_pointer_cast<RElectronics>(c.second))
			{
				return fighter;
			}
		}
		return nullptr;
	}
	///////////////////
	/// \brief Check if bullet destroyed return true
	///
	//////////////////////////////////
	bool isBulletDestroy( std::vector<std::shared_ptr<bullet>>&vec, std::shared_ptr<bullet>b)
	{
		int i = 0;
		for (auto& c : vec)
		{
			if (c == b) {
				std::vector<std::shared_ptr<bullet>>::iterator it = vec.begin();
				std::advance(it, i);
				vec.erase(it);
				return true;
			}
			i++;
		}
		return false;
	}
	bool bulletsDestrouInvolucre(std::vector<std::shared_ptr<bullet>>& vec, std::shared_ptr<bullet>b)
	{
		if (isBulletDestroy(vec, b))
			return true;
		else return false;
	}
}

