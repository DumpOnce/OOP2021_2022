#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
class Link;
class updater;
class Table {
public:
	using type = std::unordered_map< std::string, std::shared_ptr <Link>>::iterator;
	using _Pair = std::pair<std::string, std::shared_ptr <Link>>;
	friend class Iterator;
	class Iterator
	{
	public:
		friend class Table;
		Iterator(type t) :element(t) {};
		Iterator(type& it) :element(it){}

		std::pair< std::string, std::shared_ptr <Link>> operator *() { return *element; }
		Iterator operator ++() 
		{
			++element;
			return *this;
		}
		Iterator operator--() {
			--element;
			return *this;
		}

		Iterator(const Iterator& it) :element(it.element) {};
		friend std::ostream& operator<<(std::ostream& out, Iterator const& it)
		{
			return out<<it;
		}
		bool operator!=(Iterator const& it)const 
		{
			return it.element != element;
		}
		bool operator!=(Iterator* it)const
		{
			return it->element != element;
		}
		bool operator==( Iterator const& it)const
		{
			return element == it.element;
		}
	private:
		std::unordered_map<std::string, std::shared_ptr <Link>>::iterator element;
	};
private:
	/*!
		* Number of team(1st(1)or 2nd(0))
	*/
	bool teamId;
	////////////////////////////////////////////////
	/// \brief Writing data to JSON file via json library
	///
	/////////////////////////////////////////////////
	void write();

	////////////////////////////////////////
	/// \brief Reading data from JSON file
	///
	////////////////////////////////////////
	void read(bool, std::weak_ptr <updater>);
	int t_num = 0;
	std::unordered_map<std::string, std::shared_ptr<Link>> t_links;
public:
	// Class methods
	int size()const;
	void erase(std::string key) { t_links.erase(key); }
	void insert(_Pair _pair) { t_links.insert(_pair); }

	// Constructors/Destructors
	Table() = default;
	Table(bool, std::weak_ptr<updater>);
	~Table();

	// Operators
	std::shared_ptr<Link> operator[](std::string);

	// Iterator methods
	Iterator begin();
	Iterator end();
};