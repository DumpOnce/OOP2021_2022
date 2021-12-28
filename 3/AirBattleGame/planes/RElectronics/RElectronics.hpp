#include "../fighter.hpp"
#pragma once

class RElectronics:public fighter {
	float supprPro, supprMask, supprRdetect;
public:
	inline float getSupprPro() { return supprPro; }
	inline float getSupprRdetect() { return supprRdetect; }
	inline float getSupprMask() { return supprMask; }
	void Shoot(const Point&) {};
	void Shoot(std::shared_ptr<fighter>){}
	std::string getType() { return "RElectronics"; }
	RElectronics(float supprP, float supprM, float supprRdet, std::weak_ptr<updater> update, int sp, int ang, int x, int y, int dRad):fighter(update, sp, ang, x, y, dRad), supprPro(supprP), supprMask(supprM), supprRdetect(supprRdet){}
};