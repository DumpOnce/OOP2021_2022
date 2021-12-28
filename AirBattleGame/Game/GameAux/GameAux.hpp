#pragma once
#include <memory>
class RElectronics;
class Table;
class Link;
class bullet;
class fighter;
class AutoRocket;
class MissileDefence;
#include <vector>
#include <string>
class Masker;
namespace GameAux
{
	std::shared_ptr<MissileDefence> isMissileInLink(std::shared_ptr<Link> lnk);

	std::shared_ptr<fighter> targetHit(std::shared_ptr<Table>t, std::shared_ptr<bullet> b);
	std::shared_ptr<RElectronics> isElectronicsHere(std::shared_ptr<Link> link);
	bool isBulletDestroy( std::vector<std::shared_ptr<bullet>>&, std::shared_ptr<bullet>);
	bool bulletsDestrouInvolucre(std::vector<std::shared_ptr<bullet>>& vec, std::shared_ptr<bullet>b);
	/////////////////////////////////////////////////////////////////////////////////
	/// \brief Ёта функци€ помогает пон€ть был ли атакован истребитель ракетой или патроном.
	///  ћы сравниваем вектор между иекущим положением 
	/// бомбы и будущим и вектором между текущим положением бомбы и будущим положением истребител€. 
	///≈сли векторы колинеарны , то пул€ достигла цели.
	/// 
	/////////////////////////////////////////////////////////////////////////////////////
	bool isFighterAttackedByBullet(std::shared_ptr<fighter>,std::shared_ptr<bullet>);
	bool isFighterAttackedByBullet(std::shared_ptr<AutoRocket>, std::shared_ptr<bullet>);
	std::shared_ptr<Masker> isMaskerInLink(std::shared_ptr<Link>);
	static std::vector<std::string> info = {
		"Modify 1st Team\n",
		"Modify 2nd Team\n",
		"End Battle\n",
		"Save Game and Exit\n",
		"Show winning Team\n",
		"Exit without Saving\n",
		"Re-play Game\n",
		"Random_Shoot"
	};
	static std::vector<std::string> gameOrders = {
		"Move Link To Point:\n",
		"Move Plane To Point:\n",
		"Attack Link - Plane:\n",
		"Attack Plane - Plane\n"
		"Attack Streight\n",
		"Save Link Position\n",
		"Save Plane Position\n"
	};
	enum preMenu {
		Modify_1st_Team,
		Modify_2nd_Team,
		End_Battle,
		Save_Gameand_Exit,
		Show_winning_Team,
		Exit_without_Saving,
		Re_play_Game,
		Count
	};
	static std::vector<std::string> garageMenu = {
		"Add Plane To Link\n",
		"Delete Plane From The Link\n",
		"Modify Plane"
	};
	enum GarageMenu {
		Add_Plane_To_Link,
		Delete_Plane_From_The_Link,
		Modify_Plane,
		GarageCount
	};
}
