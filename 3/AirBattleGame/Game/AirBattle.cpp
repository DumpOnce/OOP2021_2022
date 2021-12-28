#include "AirBattle.hpp"
#include <iostream>
#include "../../info/updater.hpp"
#include <Windows.h>
#include <conio.h>
#include "GameAux/GameAux.hpp"
void AirBattle::gameLoop() {
	gameUpd = std::make_shared<updater>();
	try
	{
		gameUpd->update();
	}
	catch (...) 
	{
		throw std::runtime_error("Some error");
	}
}

void printMenu(std::vector<std::string>mainMenu,int Count,int Where) {
	std::vector<std::string>copy = mainMenu;
	
	for (int i = 0; i < Count; i++) {
		if (i == Where) {
			std::cout << "\033[1;47;35m" << copy[i] << "\033[0m\t\t" << std::endl;
			continue;
		}
		std::cout << copy[i] << std::endl;
	}
}

void GarageMenu()
{
	int choice = -1;
	int Where = 0;
	char c;
	do {
		printMenu(GameAux::garageMenu, GameAux::GarageCount, Where);
		c = _getch();
		if (c == (80)) {// Up
			Where++;
			system("cls");
			if (Where > GameAux::GarageCount - 1)
				Where = 0;
			else if (Where < 0)
				Where = GameAux::GarageCount - 1;
			continue;
		}
		if (c == (72)) {// Down
			Where--;
			if (Where > GameAux::GarageCount)
				Where = 0;
			else if (Where < 0)
				Where = GameAux::GarageCount - 1;
			system("cls");
			continue;
		}

		if (c == (13)) {
			choice = Where;
			switch (choice) {
			case(GameAux::Add_Plane_To_Link): {
				system("cls");
				
				break;
			};
			case(GameAux::Delete_Plane_From_The_Link): {

				system("cls");
				break;
			};
			case(GameAux::Modify_Plane):
			{
				choice = 10;
				break;
			}
			default:
				system("cls");
				break;
			};
		}
		//etchar();
	} while (choice != 10);
}


void AirBattle::menu() 
{
	int choice = -1;
	int Where = 0;
	char c;
	do {
			printMenu(mainMenu, Count, Where);
			c = _getch();
			if (c == (80)) {// Up
				Where++;
				system("cls");
				if (Where > Count-1)
					Where = 0;
				else if (Where < 0)
					Where = Count - 1;
				continue;
			}
			if (c == (72)) {// Down
				Where--;
				if (Where > Count)
					Where = 0;
				else if (Where < 0)
				Where = Count-1;
				system("cls");
				continue;
			}
			
			if (c == (13)) {
				choice = Where;
				switch (choice) {
					case(StartBattle): {
						system("cls");
						gameLoop();
						break;
					};
					case(Garage): {
						GarageMenu();
						system("cls");
						break;
					};
					case(Exit):
					{
						choice = Exit;
						break;
					}
					default:
						system("cls");
						break;
					};
			}
	} while (choice != Exit);

}