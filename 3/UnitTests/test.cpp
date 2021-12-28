#include "pch.h"
#include "../testErrors/planes/fighter.cpp"
#include "../testErrors/info/Table/Table.cpp"
#include "../testErrors/info/Link/Link.cpp"
#include "../testErrors/Game/Math/Math.cpp"
#include"../testErrors/UI/UI.cpp"
#include "../testErrors/Game/GameAux/GameAux.hpp"
#include "../testErrors/info/Mission.cpp"

TEST(fighter, settingAngleTest) {
	std::weak_ptr<updater> a;
	fighter fighter( a,43, 56, 4, 3, 65);
	fighter.setAngle(-1060);
	EXPECT_EQ(fighter.getAngle(), 20);
}

TEST(Table, addLink) {
	std::weak_ptr<updater> a;
	Table t;
	Link l;
	l.insert(std::make_pair(std::string("fighter1"), std::make_shared<Scout>(a, 4, 30, 4, 6, 43, 0.6, 0.8, 0.1)));
	t.insert(std::make_pair(std::string("link"),std::make_shared<Link>(l)));
	EXPECT_EQ(t.size(), 1);
	EXPECT_EQ((int)MATH::normalisation(-543),177);
}

TEST(Table, readJsonTest)
{

	int a;
}
TEST(Table, writeJsonTest)
{

	int a;

}

TEST(fighter, ShootTest) {
	std::shared_ptr<updater> up(new updater);
	std::weak_ptr<updater> update = up;
	std::shared_ptr<Table> t1 = std::make_shared<Table>(1, update);
	std::shared_ptr<Table> t2 = std::make_shared<Table>(0, update);
	std::shared_ptr<Mission> a(new Mission(t1, t2, (update)));
	a->t1 = t1;
	a->t2 = t2;
	a->upd = update;
	std::shared_ptr<Link> link1(new Link);
	std::shared_ptr<Link> link2(new Link);
	std::shared_ptr<fighter> f1 = std::make_shared<fighter>(update, 2, 180, 10, 0, 5);
	std::shared_ptr<fighter> f2 = std::make_shared<fighter>(update, 2, 0, 0, 0, 4);
	link1->insert(std::make_pair(std::string("plane1"), f1));
	link2->insert(std::make_pair(std::string("plane2"), f2));
	/*Смоделировать ситуацию атаки*/
}

TEST(fighter, isLessZeroHp)
{
	std::weak_ptr<updater> a;
	std::shared_ptr<Table> t = std::make_shared<Table>();
	std::shared_ptr<Link> l =  std::make_shared<Link>();
	std::shared_ptr<Scout> plane = std::make_shared<Scout>(a, 4, 30, 4, 6, 43, 0.6, 0.8, 0.1);
	l->insert(std::make_pair(std::string("fighter1"),plane ));
	t->insert(std::make_pair(std::string("link"),l ));
	EXPECT_EQ(t->size(), 1);
	plane->getDamage(1000);
	for (auto c : *l) 
	{
		if (c.second->getHp() < 0) {
			UI::delPlane(t, c.second);
			break;
		}
	}
	EXPECT_EQ(t->size(), 0);
}

TEST(fighter, is_visible)/*Is not working yet*///Add some tests here
{
	std::weak_ptr<updater> up;
	fighter a(up, 1, 0, 0, 0, 10);
	fighter b(up, 1, 0, 5, 0, 10);
	fighter c(up, 1, 0, 1, 1, 10);
	fighter d(up, 1, 0, 545, 2, 10);
	EXPECT_EQ(a.is_visible(std::make_shared<fighter>(b)),true);
	EXPECT_EQ(c.is_visible(std::make_shared<fighter>(d)), false);
}


int main(int argc, char* argv[]) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}