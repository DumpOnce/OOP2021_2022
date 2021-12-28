#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <chrono>
#include <memory>
class Mission;
class fighter;
class bullet;

class updater: public std::enable_shared_from_this<updater>{

public:
	///////////////////
	/// \brief Deleting bullet
	///
	////////
	void addBullet(std::shared_ptr<bullet>);
	void delBullet(std::shared_ptr<bullet>);
	/////////////////////////////////////////////////
	/// \brief Main update function
	/// Updating all apositions(bullets,aplanes, etc.)
	///
	/// \bug When the bullet leaves the map area, 
	/// an error occurs when accessing an inaccessible map index
	/// (the map is stored as a vector of rows)
	/// 
	//////////////////////////////////////////////////
	void update();
	void addElement(std::shared_ptr<bullet>);
	void addElement(std::shared_ptr<fighter>);
	void deleteElement(std::shared_ptr<bullet>);
	void draw();
	~updater() { /*ENter result window here*/std::cout << "~updater\n"; }
	//std::set<std::shared_ptr<bullet>> bullets;
	void addVrag(std::shared_ptr<fighter>);
	static const int width = 93;
	static const int height = 15;
	/**
		\brief Method for updating info on the battle field
	*/
	 updater(){}
private:
	short int result = -2;
	std::shared_ptr<Mission> mission ;
	std::string numerical_superiority =
		"###############################################################################################\n"
		"#                                                                                             #\n"
		"#                         TEAM1                                   TEAM2                       #\n"
		"#                                                                                             #\n";
	std::string clearStr = "#                                                                                             #\n";
	std::vector<std::string> field = {
									"###############################################################################################",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"#                                                                                             #",
									"###############################################################################################"
	};
	std::string infoOutputer =
		"#                                          TAB - End Battle                                   #\n"
		"#                                     BACKSPACE - INFO ABOUT PLANES                           #\n"
		"#                                     WHITESPACE - COMMON MENU                                #\n"
		"###############################################################################################";
	std::string infoTables = {	"*                      Users                    *",};
	std::string verticalBorder = { "************************************************************************************************************" };

	std::vector<std::string> generalInfo;
};