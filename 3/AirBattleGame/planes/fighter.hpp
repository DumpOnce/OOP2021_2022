#pragma once
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <memory>
#include <iostream>
class bullet;
class Link;
class updater;
class AbstractBullet;
class Armour;
class Gun;
struct Point;

//////////////////////////////
/// \brief Base plane class 
///////////////////////////
class fighter:public std::enable_shared_from_this<fighter> {
protected:
	time_t shotFrequency = 300;
	time_t timeFrequencyNow = 0;
protected:
	int hp = 100;
	int speed;
	int angle;
	int dRadius;
	int damage = 10;
	int view_angle = 15;
protected:
	std::string call;
	//std::string type;
	std::pair<double, double> pos;
	std::shared_ptr<Point> orderPosition;
	std::weak_ptr<updater> upd;	
	std::weak_ptr<Link> link;	
	std::shared_ptr<Gun> armour;
	std::shared_ptr<fighter> order;
public:
	fighter(std::weak_ptr<updater> update, int sp, int ang, int x, int y, int dRad);
	/// <summary>
	/// We use virtual destructor to call dynamic pointer cast in Shoot function of an armour
	/// </summary>
	virtual ~fighter() { std::cout << "~fighter\n"; }

	/// Setters
	void setPos(float x, float y) { pos.first = x; pos.second = y; }
	void setAngle(int);
	void setOrder(double x, double y);
	void setOrder(Point& p);
	void setOrder(std::shared_ptr<fighter> plane) { order = plane; }
	/////////////////////////
	/// \brief Function stopping order of plane to attack another plane
	///
	////////////////////////////////////////////////////////////////////
	void breakOrder();

	///  Getters
	///////////////////
	/// \brief Get our updater weak ptr
	/// 
	/// \todo We need to return  SHARED, not WEAK
	/// 
	///////////////////////////////////////////////////
	std::weak_ptr<updater> getUpdater() const{ return upd; }
	std::weak_ptr<Link> getLink()const { return link; }
	std::shared_ptr<Point> getOrder()const{ return orderPosition; }
	int getHp()const { return hp; }
	int getViewAngle()const { return view_angle; }
	int getSpeed()const { return speed; }
	int getX()const;
	int getAngle() const{ return angle; }
	int getY()const;
	int getRadius() { return dRadius; }
	
	std::pair<double, double>& getPos() { return pos; };

	/// Other functions
	void getDamage(int);
	void update();

	bool operator ==(bullet&);
	//////////////////////////////////////////////
	/// \brief Shoot function
	/// If we have as an armour a gun(rocket) - we step forward and
	///  further control of the shot switchs to the function of the gun(rocket) 
	/// called "Shoot".
	//////////////////////////////////
	virtual std::string getType() = 0;
	// Interface
	virtual void Shoot();// If Developer would want to make new type of SuperPlane
	virtual void Shoot(const Point&) = 0;
	virtual void Shoot(std::shared_ptr<fighter>) = 0;
	
	//////////////////////////////////////////////
	/// \brief This function check visability of other plane
	/// 
	/// \param plane std::shared_ptr<gighter> plane which we want to check
	/// \return bool True if visible,else False
	/// 
	///////////////////////////////////////
	bool is_visible(std::shared_ptr<fighter>);
};
