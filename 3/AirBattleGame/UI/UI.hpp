#pragma once
class Table;
class Link;
class Point;
class fighter;
class bullet;
class RElectronics;
/*! \file */
class Mission;
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
//! UI namespace
namespace UI{

	void modificationMenu(bool team, std::shared_ptr<Mission>);

	int planeCount(std::shared_ptr<Table> table);
	/////////////////////////////////
	///	\brief Change angle for plane
	/// 
	/// \param std::shared_ptr<Table> Table element
	/// 
	////////////////////////////////////
	 void changeAngle(std::shared_ptr<Table>);

	 /// /////////////////////////////////////////////////////////////
	 /// \brief Adding Plane to link
	 /// \param link Shared ptr to the link
	 /// \param   
	 ///	_pair std::pair<std::string, std::shared_ptr<fighter>>
	 ///		 _pair that we want to add to the link
	 /// 
	 /// \todo Check that planes < 4, if not - return false
	 /////////////////////////////////////////////////////////////////
	 bool addPlane(std::shared_ptr<Link> link, std::pair<std::string, std::shared_ptr<fighter>> _pair);

	 ////////////////////////////////
	 /// \brief Link attack function
	 ////////////////////////////////
	 void attack(std::shared_ptr<Link>);

	 //////////////////////////////////
	 /// \brief Plane attack funtion
	 //////////////////////////////////
	 void attack(std::shared_ptr<fighter>);

	 ///  Saving position of link
	 void savePosition(double x, double y, std::shared_ptr<Link>);

	 void savePosition(Point&, std::shared_ptr<Link>);

	 void delPlane(std::shared_ptr<Table>t, std::shared_ptr<fighter>f);//Do checking if link size == 0 - delete link

	 void delPlane(std::shared_ptr<Table>, std::string);

	 void shootSomebody(std::shared_ptr<Table>);

	 void movePlaneToPoint(std::shared_ptr<fighter>f, Point _point);

	 
	 void moveLinkToPoint(std::shared_ptr<Link> link, Point _point);

	 void viewStat(std::shared_ptr<Table>, std::shared_ptr<Table>);
	 /**
		\brief Checking fight result 

		* 1 - 1win,-1 - 2win, 0 - no result
	 */
	 short int is_result(std::shared_ptr<Table>, std::shared_ptr<Table>);
	
	 std::string whoIsWinning(std::shared_ptr<Mission>);
	 //////////////////////////////////////
	 /// \brief Function to stop Plane flying to the target
	 /// and set the way around definite point
	 /// 
	 /// \param plane Stop order to this plane
	 /// 
	 /////////////////////////////////////////
	 void toStopPlane(std::shared_ptr<fighter>);
}; //namespace UI


