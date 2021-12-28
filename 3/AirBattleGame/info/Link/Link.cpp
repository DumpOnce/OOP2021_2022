#include "Link.hpp"

#include "../../planes/fighter.hpp"
#include "../Table/Table.hpp"

float distanceTo(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	float sqrx = dx * dx;
	float sqry = dy * dy;
	return sqrt(sqrx + sqry);
}

Link::Link(std::vector<El> fighters) 
{
	for (auto c : fighters) 
	{
		l_planes.insert(c);
	}
}

Link& Link::operator=(std::vector<El>vec)
{
	for (auto& c : vec)
	{
		l_planes.insert(c);
	}
	return *this;
}

Link::Iterator  Link::begin() { return Iterator(l_planes.begin()); }

Link::Iterator Link::end() { return Iterator(l_planes.end()); }

void Link::updateTargets(std::shared_ptr<Table> vTeam)
{
	targets.clear();
	for (auto c : *this) {
		for (auto el : *vTeam) {
			for (auto tEl : *el.second)
			{
				float x1 = c.second->getX();
				float x2 = tEl.second->getX();
				float y1 = c.second->getY();
				float y2 = tEl.second->getY();
				if (distanceTo(x1, y1, x2, y2) < c.second->getRadius()) {
					targets.insert(tEl.second);
				}
			}
		}
	}
}


std::shared_ptr<fighter> Link::operator[](std::string str)
{
	return l_planes[str];
}
