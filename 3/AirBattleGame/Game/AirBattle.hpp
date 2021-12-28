#pragma once
#include <memory>
#include <vector>
#include <string>
#include <iostream>
class updater;
class AirBattle {
public:
	AirBattle() { menu(); }
	inline  ~AirBattle() = default;
private:
	enum menuTitle {
		StartBattle,
		Garage,
		Exit,
		Count
	};
	void menu();
	void gameLoop();
	std::shared_ptr<updater> gameUpd;
	std::vector<std::string> mainMenu = {
		"Start Game",
		"To Garage",
		"Exit"
	};
};