#include "updater.hpp"
#include <chrono>
#include <thread>
#include <memory>
#include "../planes/fighter.hpp"
#include "../bullets/bullet.hpp"
#include "./Table/Table.hpp"
#include "./Mission.hpp"
#include <windows.h>
#include "./Link/Link.hpp"
#include "../Game/GameAux/GameAux.hpp"
#include "../UI/UI.hpp"
#include <conio.h>
#include <vector>
class fighter;



void updater::addBullet( std::shared_ptr<bullet>b)
{
	mission->bullets.push_back(b);
}

void updater::delBullet(std::shared_ptr<bullet>b)
{
	GameAux::isBulletDestroy(mission->bullets,b);
}

void updater::update() 
{
	std::shared_ptr<Table> t1 = std::make_shared<Table>(1, weak_from_this());
	std::shared_ptr<Table> t2 = std::make_shared<Table>( 0, weak_from_this());
	std::shared_ptr<Mission> a(new Mission(t1, t2, (weak_from_this())));
	mission = a;
	time_t battleTime= 0;
	std::chrono::milliseconds attackInverval = std::chrono::milliseconds(0);
	while (true) 
	{
		if (result = UI::is_result(t1, t2) != 0)
			break;
		if (GetAsyncKeyState(8)) 
		{
			//break;
			while (true) 
			{
				std::cout << infoTables<< std::endl;
				
				for (auto c : *mission->t1) {
					std::cout << "*" << "         " << c.first << ":" << std::endl;
					std::cout << "	";
					for (auto g : *c.second) {
						std::cout << "planeCall:" << g.first << "			" << g.second->getType() << std::endl;
						std::cout << "	   ";
						std::cout << "{X:" << g.second->getX() << ",Y:" << g.second->getY() << "}" << std::endl;
					}
				}
				std::cout << "\n" << "2)";
				std::cout << "\n\n";
				for (auto c : *mission->t2) {
					std::cout << "*" << "         " << c.first << ":" << std::endl;
					std::cout << "	";
					for (auto g : *c.second) {
						std::cout << "planeCall:" << g.first << "			" << g.second->getType()<< std::endl;
						std::cout << "	   ";
						std::cout << "{X:" << g.second->getX() << ",Y:" << g.second->getY() << "}" << std::endl;
					}
				}
				std::cout<<"*" <<std::endl;
				std::cout << verticalBorder << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
				system("cls");
				if(GetAsyncKeyState(9))
				{
					std::string link;
					std::string plane;
					std::cout << "Choose team:\n";
					bool a;
					std::cin >> a;
					std::cout << "Choose link:\n";
						std::cin >> link;
						system("cls");
						std::cout << "Choose plane:\n";
						std::cin >> plane;
						system("cls");
						int angle;
						std::cout << "Choose angle:\n";
						std::cin >> angle;
					if (a) {
					
						(*(*mission->t1)[link])[plane]->setAngle(angle);
					}
					else {
						(*(*mission->t2)[link])[plane]->setAngle(angle);
					}
				}
				if (GetAsyncKeyState(32))
					break;
			}
		}
		if (GetAsyncKeyState(9))
		{
			//system("cls");
			//std::cout<<UI::whoIsWinning(mission);
			//std::this_thread::sleep_for(std::chrono::microseconds(100000));
			//system("cls");
			break;
		}
		if (GetAsyncKeyState(32))// Command Menu
		{
			int choice = -1;
			int Where = 0;
			char c;
			do {
				std::vector<std::string>copy = GameAux::info;
				for (int i = 0; i < GameAux::Count; i++) {
						if (i == Where) {
							std::cout << "\033[1;47;35m"<<copy[i] << "\033[0m\t\t" << std::endl;
							continue;
						}
						std::cout << copy[i] << std::endl;
					}
				c = _getch();
				if (c == (80)) {// Up
					Where++;
					system("cls");
					if (Where > GameAux::Count - 1)
						Where = 0;
					else if (Where < 0)
						Where = GameAux::Count - 1;
					continue;
				}
				if (c == (72)) {// Down
					Where--;
					if (Where > GameAux::Count)
						Where = 0;
					else if (Where < 0)
						Where = GameAux::Count - 1;
					system("cls");
					continue;
				}
				if (c == (13)) {
					choice = Where;
					switch (choice) {
					case(GameAux::Modify_1st_Team): {
						system("cls");
						break;
					};
					case(GameAux::Modify_2nd_Team): {
						system("cls");
						break;
					};
					case(GameAux::End_Battle):
					{
						choice = 10;
						break;
					}
					case(GameAux::Save_Gameand_Exit):
					{
						choice = 10;
						break;
					}
					case(GameAux::Show_winning_Team):
					{
						choice = 10;
						break;
					}
					case(GameAux::Exit_without_Saving):
					{
						choice = 10;
						break;
					}
					case(GameAux::Re_play_Game):
					{
						choice = 10;
						break;
					}
					default:
						system("cls");
						break;
					};
				}
			} while (choice != 10);
		}
		try {
			draw();
		}
		catch (...) {
			throw std::runtime_error("Draw func Error");
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		system("cls");
	}
}

void updater::draw()
{
	std::vector<std::string> b = field;
	
	for (auto c :*mission->t1)
	{
		for (auto x : *c.second) {
			x.second->update();
			//x.second->Shoot();
			b[x.second->getY()][x.second->getX()] = 'A';
		}
	}
	for (auto c : *mission->t2)
	{
		for (auto x : *c.second) {
			x.second->update();
			//x.second->Shoot();
			b[x.second->getY()][x.second->getX()] = 'a';
		}
	}
	for (auto c : *mission->t1) {
		(c).second->updateTargets(mission->t2);
	}
	for (auto c : *mission->t2) 
	{
		(c).second->updateTargets(mission->t1);
	}
	for(auto c:mission->bullets) {
		GameAux::targetHit(mission->t1, c);
	}
	for (auto c : mission->bullets) {
		GameAux::targetHit(mission->t2, c);
	}

	for (auto c : mission->bullets) {
		c->update();
		b[c->getY()][c->getX()] = '*';
	}
	for (auto c : *mission->t1)
	{
		for (auto x : *c.second) 
		{
			if (x.second->getHp() < 0) {
				UI::delPlane(mission->t1, x.second);
				//break;
				goto B;// delete
			}
		}
	}
	B:
	for (auto c : *mission->t2)
	{
		for (auto x : *c.second) {
			if (x.second->getHp() < 0)
				UI::delPlane(mission->t2, x.second);
			goto A;
		}
	}
	A:
	std::vector<std::shared_ptr<bullet>>::iterator it;
	for (it = mission->bullets.begin(); it != mission->bullets.end(); )
	{
		if ((*it)->getX() >= updater::width || (*it)->getX() <= 2 || (*it)->getY() >= updater::height || (*it)->getY() <= 2)
			it = mission->bullets.erase(it);
		else
			++it;
	}
	std::cout << numerical_superiority;
	std::cout << "#                            " << UI::planeCount(mission->t1) << "                                 " << UI::planeCount(mission->t2) << "                              #\n";
	std::cout << clearStr;
	for (int i = 0; i < b.size(); i++) 
	{
		std::cout << b[i] << std::endl;;
	}
	std::cout << infoOutputer;
}

void updater::addElement(std::shared_ptr<bullet> b) 
{
	//bullets.insert(b);
	mission->bullets.push_back(b);
}

void updater::addElement(std::shared_ptr<fighter > f) 
{
}
void updater::addVrag(std::shared_ptr<fighter > f) 
{
}
void updater::deleteElement(std::shared_ptr<bullet> bul)
{
	//bullets.erase(bul);
	mission->bullets.emplace_back(bul);
	mission->bullets.pop_back();
}
