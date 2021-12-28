#pragma once
/////////////////
/// Headers
/////////////////
#include <memory>
#include <iostream>
class updater;
class fighter;
/////////////////////////////////
/// \brief Patron class which use when we shoot
/// from the gun or the rocket
/// 
/////////////////////////////////
class bullet:public std::enable_shared_from_this<bullet> {
public:
	// Constructor/Destructor
	bullet(std::shared_ptr<updater> update, int ang, int sp, float x, float y,int damage);
	~bullet() { std::cout << "~bullet\n"; }

	//Getters
	int getX()const { return pos.first; }
	int getY()const { return pos.second; }

	// Other
	virtual bool update() = 0;

	void addBul();// Add bullet to the mission table
	
	int getDamage()const { return damage; }
	////////////////////////////////
	/// \brief Function to compaire position bullet and plane
	/// 
	/// \return True, if positions EQUAL,else False
	/// 
	////////////////////////////////////////////////////  
	bool equalPosition(std::shared_ptr<fighter>)const;
	bool equalPosition(std::shared_ptr<bullet>)const;

	int getAngle() { return angle; }
	int getSpeed() { return speed; }
protected:
	float maxDistance = 25;
	float distance = 0;

	int damage = 40;
	
	int speed;
	int angle;

	std::shared_ptr<updater> upd;
	std::pair<float, float> pos;
public:
	char img = '*';
};
