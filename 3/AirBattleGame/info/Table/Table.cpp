#include "Table.hpp"
#include <nlohmann/json.hpp>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>
//#include "../../planes/fighter.hpp"
#include "../Link/Link.hpp"
#include "../updater.hpp"
#include "../../planes/Scout/Scout.hpp"
#include "../../planes/RElectronics/RElectronics.hpp"
#include "../../planes/MissileDefence/MissileDefence.hpp"
std::string readFile2(const std::string& fileName) {
	std::ifstream f(fileName);
	std::stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}

void Table::write() {
	std::string data;
	if (teamId) {
		int linksNum = t_links.size();
		data += "{ \"User\":{ \"Num\""+std::to_string(linksNum)+":{\"";
		int i = 0;
		for (auto& c : t_links) 
		{			
				std::shared_ptr<Link> link = (c).second  ;
				data += "\"link" + std::to_string(i + 1) + "\":{\"CallSign\":\""+c.first+"\","+"\"Num\":"+std::to_string(link->size())+"\',";
				int j = 0;
				for (auto element : *c.second) {
					data += "\'plane" + std::to_string(j + 1) + "\',";
					data += "\"Type\":";
					std::string generalInfo;
					generalInfo += "\"Call\":\"" + element.first + "\",";
					generalInfo += "\"speed\":" + std::to_string(element.second->getSpeed()) + ","; +
						"\"angle\":" + std::to_string(element.second->getAngle()) + ","+
						"\"pos\":{" +
						"\"x\":" +std::to_string(element.second->getX())+","+
						"\"y\":" + std::to_string(element.second->getY())+"}"+
						"\"radius\":" + std::to_string(element.second->getRadius())+",";
					if (std::shared_ptr<Scout> scout = std::dynamic_pointer_cast<Scout>(element.second))
					{
						data += "\'Scout\',";
						data += generalInfo;
						data += "\"changabillityR\":" + std::to_string(scout->changabillityRate()) + "," +
							"\"decreaseDetectionRate\":" + std::to_string(scout->getDecreaseDetectionRate()) + "," +
							"\"ignoreMaskerRate\":" + std::to_string(scout->getMaskRate());

					}
					else if(std::shared_ptr<RDetection> rdetection = std::dynamic_pointer_cast<RDetection>(element.second)){
						data += "\"RDetection\"";
						data += generalInfo;
						data += 
							"\"ignoreMaskerRate\":" + std::to_string(rdetection->getMaskRate())  ;
					}
					else if (std::shared_ptr<MissileDefence> missile = std::dynamic_pointer_cast<MissileDefence>(element.second)) {
						data += "\'MissileDefence\'";
						data += generalInfo;
						data +=
							"\"rockets\":" + std::to_string(missile->getRockets()) ;

					}
					else if (std::shared_ptr<Masker> masker = std::dynamic_pointer_cast<Masker>(element.second)) {
						data += "\'Masker\'";
						data += generalInfo;
						data += "\"changabillityR\":" + std::to_string(masker->changabillityRate()) + "," +
							"\"decreaseDetectionRate\":" + std::to_string(masker->getDecreaseDetectionRate());
					}
					else if (std::shared_ptr<RElectronics> electronics = std::dynamic_pointer_cast<RElectronics>(element.second)) {
						data += "\"RElectronics\'";
						data += generalInfo;
						data += "\"supprPro\":" + std::to_string(electronics->getSupprPro()) + "," +
							"\"supprMask\":" + std::to_string(electronics->getSupprMask()) + "," +
							"\"supprRdetect\":" + std::to_string(electronics->getSupprRdetect()) ;

					}
					data += "}";
					j++;
				}	
				data += "}";
				i++;
		}
	}
	else {}
	std::ofstream file("c:\\users\\admin\\source\\repos\\testerrors\\testErrors\\info.json");
	file << data;
	std::cout << data;
}


std::shared_ptr<Link> Table::operator[](std::string str)
{
	return t_links[str];
}

void Table::read(bool team, std::weak_ptr<updater> u)
{
	nlohmann::json file = nlohmann::json::parse(readFile2("c:\\users\\admin\\source\\repos\\testerrors\\testErrors\\planes.json"));
	if (team)
	{
		for (int i = 0; i < file["User"]["Num"]; i++)
		{
			{
				std::vector<std::pair<std::string,std::shared_ptr<fighter>>> links;
				for (int j = 0; j < file["User"]["Link" + std::to_string(i + 1)]["Num"]; j++)
				{
					int speed = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["speed"];
					int angle = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["angle"];
					float x = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["pos"]["x"];
					float y = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["pos"]["y"];
					int radius = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["radius"];

					if (file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "Scout")
					{
						float ignoreMask = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["ignoreMaskerRate"];;;

						float changabillityR = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["changabillityR"];;
						float decreaseDetectionRate = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["decreaseDetectionRate"];

						std::shared_ptr<Scout> scout = std::make_shared<Scout>(u, speed, angle, x, y, radius,changabillityR,decreaseDetectionRate,ignoreMask);
						links.push_back(std::make_pair(file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"],scout));

					}
					else if (file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "Masker")
					{
						float changabillityR = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["changabillityR"];;
						float decreaseDetectionRate = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["decreaseDetectionRate"];
						std::shared_ptr<Masker> masker = std::make_shared<Masker>(u,angle,x,y,speed,radius,changabillityR,decreaseDetectionRate);
						links.push_back(std::make_pair(file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"], masker));
					}
					else if (file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "MissileDefence")
					{
						int rocketCount = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["rocketCount"];

						std::shared_ptr<MissileDefence> missile = std::make_shared< MissileDefence>(u, angle, x, y, speed, radius, rocketCount);
						links.push_back(std::make_pair(file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"], missile));

					}
					else if (file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "RElectrinics") 
					{
						float supprPro = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["supprPro"];
						float supprMask = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["supprMask"];
						float supprRdetect = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["supprRdetect"];

						std::shared_ptr<RElectronics> relectronics = std::make_shared<RElectronics>(supprPro, supprMask, supprRdetect, u, speed, angle, x, y, radius);
						links.push_back(std::make_pair(file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"], relectronics));

					}
					else if (file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "RDetection")
					{
						float ignoreMaskerRate = file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["ignoreMaskerRate"];

						std::shared_ptr<RDetection> rdetect = std::make_shared<RDetection>(u,speed,angle,x,y,radius,ignoreMaskerRate);
						links.push_back(std::make_pair(file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"], rdetect));

					}
				}
						std::shared_ptr<Link> link(new Link(links));
						std::string callSign = file["User"]["Link" + std::to_string(i + 1)]["CallSign"];

						t_links.insert(std::make_pair(callSign + std::to_string(team) + std::to_string(i), link));
			}
		}
	}
	else {
		for (int i = 0; i < file["User2"]["Num"]; i++)
		{
			{
				std::vector<std::pair<std::string, std::shared_ptr<fighter>>> links;
				for (int j = 0; j < file["User2"]["Link" + std::to_string(i + 1)]["Num"]; j++)
				{
					int speed = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["speed"];
					int angle = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["angle"];
					float x = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["pos"]["x"];
					float y = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["pos"]["y"];
					int radius = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["radius"];

					if (file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "Scout")
					{
						float ignoreMask = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["ignoreMaskerRate"];;;

						float changabillityR = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["changabillityR"];;
						float decreaseDetectionRate = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["decreaseDetectionRate"];

						std::shared_ptr<Scout> scout = std::make_shared<Scout>(u, speed, angle, x, y, radius, changabillityR, decreaseDetectionRate, ignoreMask);
						links.push_back(std::make_pair(file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"], scout));

					}
					else if (file["User"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "Masker")
					{
						float changabillityR = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["changabillityR"];;
						float decreaseDetectionRate = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["decreaseDetectionRate"];
						std::shared_ptr<Masker> masker = std::make_shared<Masker>(u, angle, x, y, speed, radius, changabillityR, decreaseDetectionRate);
						links.push_back(std::make_pair(file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"], masker));
					}
					else if (file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "MissileDefence")
					{
						int rocketCount = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["rocketCount"];

						std::shared_ptr<MissileDefence> missile = std::make_shared< MissileDefence>(u, angle, x, y, speed, radius, rocketCount);
						links.push_back(std::make_pair(file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"], missile));

					}
					else if (file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "RElectrinics")
					{
						float supprPro = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["supprPro"];
						float supprMask = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["supprMask"];
						float supprRdetect = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["supprRdetect"];

						std::shared_ptr<RElectronics> relectronics = std::make_shared<RElectronics>(supprPro, supprMask, supprRdetect, u, speed, angle, x, y, radius);
						links.push_back(std::make_pair(file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"], relectronics));
					}
					else if (file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Type"] == "RDetection")
					{
						float ignoreMaskerRate = file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["ignoreMaskerRate"];

						std::shared_ptr<RDetection> rdetect = std::make_shared<RDetection>(u, speed, angle, x, y, radius, ignoreMaskerRate);
						links.push_back(std::make_pair(file["User2"]["Link" + std::to_string(i + 1)]["plane" + std::to_string(j + 1)]["Call"], rdetect));
					}
				}
				std::shared_ptr<Link> link(new Link(links));
				std::string callSign = file["User2"]["Link" + std::to_string(i + 1)]["CallSign"];

				t_links.insert(std::make_pair(callSign + std::to_string(team) + std::to_string(i), link));
			}
		}
	}
}
Table::~Table() { write(); }

Table::Table(bool team,std::weak_ptr<updater> u) { 
	read(team,u); teamId = team; }

Table::Iterator Table::begin() { return Iterator(t_links.begin()); }

Table::Iterator Table::end() { return Iterator(t_links.end()); }

int Table::size()const { return t_links.size(); }