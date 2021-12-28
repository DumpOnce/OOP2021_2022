#pragma once
#include "../fighter.hpp"
#include "../Masker/Masker.hpp"
#include "../RDetection/RDetection.hpp"
///////////////////////////////////////////////////////////
///	\brief Scout plane class
/// This class derrives traits of Masker and RDetection planes
///	
/// \todo change armour on gun
/// \todo Maybe I'm creating extra instances of classes 
/// in a virtual table, you need to check this later
///////////////////////////////////////////////////////
class Scout :virtual public Masker, virtual public RDetection {
public:
	Scout(std::weak_ptr<updater> update, int sp, int ang, int x, int y, int dRad, int changeRate, int decreaseRate,int ignoreRate) :Masker(update,sp,ang,x,y,dRad, changeRate, decreaseRate),fighter(update,sp,ang,x,y,dRad),RDetection(update, sp, ang, x, y, dRad, ignoreRate)
	{};
	void Shoot(const Point&) {};
	void Shoot(std::shared_ptr<fighter>){}
	std::string getType() { return "Scout"; }
};