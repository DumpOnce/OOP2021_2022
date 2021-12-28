#pragma once
#include <memory>
///////////////////////
// Defines
///////////////////////
#define GUN_DAMAGE 15
#define ROCKET_DAMAGE 40
/////////////////////////////////////
/// Premature declaration for the compiler
struct Point;
class fighter;
class bullet;
class updater;
//////////////////////////////////////
/**
	* Class Armour (fighter class consist of Armour also)
*/
class Armour 
{
protected:
	float rate = 1;///<Percentage of hits
	/// Getting rid of cyclic links with weak ptr
	std::shared_ptr <updater> upd;
public:
	Armour() {}
	Armour(std::shared_ptr<updater>update,float rate) :rate(rate),upd(update) {}
	/////////
	/// \brief It need to make dynamic pointer cast(?)
	/////////////////
	virtual ~Armour() {};
	////////////////////////////////////////////////////
	/// \brief Shoot function
	/// All fighters are divided into links - the minimum units of fighter control. 
	/// 
	/// There can be from one to four fighters in each link, there are no fighters without
	///	links.Each link can see the enemy link only in a certain radius
	///	of radio detection, the radius of radio detection of the link 
	/// 
	/// is equal to the radius of radio detection of the fighter with
	///	the best indicator in the link.Each link can receive an order to move to a certain
	///	point, maintain a position, attack an enemy link or a specific aircraft in the link.
	///	Fighters are also divided into types according to specialization and installed
	///	equipment :
	///  missile defense systems(missile defense), 
	///		camouflage,
	///			 improved
	///				radio detection,
	///					 electronic warfare systems(electronic warfare), 
	///						 intelligence.The missile defense system has several
	///	charges, which, when used with a high probability, avoid a missile hit.
	/// 
	///	The masking system allows you to increase the probability of a miss when firing a cannon, as well
	///	as reduce the detection radius for dan
	/// 
	//////////////////////////////////////////////////////////////////
	virtual void Shoot(std::shared_ptr<fighter>) = 0;
	virtual void Shoot(std::shared_ptr<fighter>, double, std::shared_ptr<fighter>) = 0;
	virtual void Shoot(const Point&) = 0;
	//virtual void Shoot(std::shared_ptr<bullet>) = 0;
};

