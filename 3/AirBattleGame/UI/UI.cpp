#include "UI.hpp"
#include "../info/Table/Table.hpp"
#include "../info/Link/Link.hpp"
#include "../planes/RElectronics/RElectronics.hpp"
#include "../bullets/bullet.hpp"
#include "../Game/Math/Math.hpp"
#include "../../info/Mission.hpp"
#define _CRT_SECURE_NO_WARNINGS
namespace UI {
	int planeCount(std::shared_ptr<Table> table) {
		int count = 0;
		for (auto c : *table) {
			count += c.second->size();
		}
		return count;
	}
	std::string whoIsWinning(std::shared_ptr<Mission> mission)
	{
		if (planeCount(mission->t1) > planeCount(mission->t2))
		{
			return std::string("First team Winning!\n");
		}
		else if(planeCount(mission->t1) < planeCount(mission->t2))
			return std::string("Second team Winning!\n");
		else return std::string("It's draw!\n");
	}
	void delPlane(std::shared_ptr<Table>t, std::shared_ptr<fighter>f) //Do checking if link size == 0 - delete link
	{
		for (auto c : (*t)) {
			for (auto g : (*c.second)) {
				if (g.second == f) {
					(c.second)->erase(g.first);
					if (c.second->size() == 0) {
						t->erase(c.first);
					}
					return;
				}
			}
		}
		return;
	}
	bool addPlane(std::shared_ptr<Link> link, std::pair<std::string, std::shared_ptr<fighter>> _pair)
	{
		if (link->size() == 4)
			return false;
		else link->insert(_pair); return true;
	}
	void movePlaneToPoint(std::shared_ptr<fighter>f, Point _point) {
		f->setOrder(_point);
	}
	void moveLinkToPoint(std::shared_ptr<Link> link, Point _point)
	{
		for (auto c : *link)
		{
			movePlaneToPoint(c.second, _point);
		}
	}
	short int is_result(std::shared_ptr<Table>t1, std::shared_ptr<Table>t2)
	{
		if (t1->size() == 0)//< Logging results
		{
			//freopen("logInfo.txt", "w+", stderr);
			std::cerr << "1st team win\n";
			return 1;
		}
		if (t2->size() == 0)//< Logging results
		{
			//freopen("logInfo.txt", "w+", stderr);
			std::cerr << "2nd team win\n";
			return -1;
		}
		else return 0;
	}
}

