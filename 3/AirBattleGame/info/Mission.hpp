#pragma once
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <memory>
#include <vector>
#include "../bullets/bullet.hpp"

class updater;
class Table;
class AutocontrolBullet;
/**
	\brief Class that activates when we start fight
		It contains two tables and bullets
*/
class Mission {
public:
	Mission(std::shared_ptr<Table>, std::shared_ptr<Table>,std::weak_ptr<updater>);

	std::shared_ptr<Table> t1; // Team1
	std::shared_ptr<Table> t2; // Team2
	std::vector<std::shared_ptr<bullet>> bullets; // All patrons
	std::weak_ptr<updater> upd; // Pointer to update center
	std::vector<std::shared_ptr<AutocontrolBullet>> Autobullets; // All patrons
};

/////////////////////////////////////////////////////////////
/// \todo I need to create common vector of abstract bullets
/// to make code more templatable
/// 
/////////////////////////////////////////////////////////////