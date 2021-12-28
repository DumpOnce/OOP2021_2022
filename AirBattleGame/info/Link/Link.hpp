#pragma once
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <set>
class Point;
class fighter;
class Table;
class updater;
class Link
 {
public:
	friend class Iterator;
	using El =  std::pair<std::string,std::shared_ptr<fighter>>;
	class Iterator //:std::Iteratoratorator<std::input_Iteratorator_tag, Link>
	{
	public:
		using iterator = std::map<std::string,std::shared_ptr<fighter >>::iterator ;
		friend class Link;
		Iterator(iterator& it) :element(it) {}
		Iterator(iterator it) :element(it) {}

		Iterator() {}

		bool operator==(Iterator const& it)
		{
			return element == it.element;
		}

		bool operator!=(Iterator const& it)
		{
			return element != it.element;
		}
		El operator*() { return *element; }
		iterator operator++() {
			return ++element;
		}
	private:
		iterator element;
	};
private:
	std::map<std::string,std::shared_ptr<fighter>> l_planes;
	std::weak_ptr<updater> update;
public:
	std::set<std::shared_ptr<fighter>> targets;
	Iterator  begin();
	Iterator end();
	std::set<std::shared_ptr<fighter>> getTargets() { return targets; }
	void insert(El _pair) { l_planes.insert(_pair); }
	void erase(std::string& key) { l_planes.erase(key); }
	int size() { return l_planes.size(); }
	Link(std::weak_ptr<updater> upd) { update = upd; };
	std::shared_ptr<fighter> operator[](std::string);
	~Link() { std::cout << "~Link"; }

	Link(std::vector<El>);
	inline Link() = default;
	Link& operator=(std::vector<El>);
	
	void updateTargets(std::shared_ptr<Table> vTeam);
};