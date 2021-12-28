#include "Mission.hpp"
#include "./updater.hpp"
#include "./Table/Table.hpp"
Mission::Mission(std::shared_ptr<Table>team1, std::shared_ptr<Table>team2, std::weak_ptr<updater> update)
{
	t1 = team1;
	t2 = team2;
	upd = (update);
}