#include "pch.h"
#include "../JsonTest/Collection.hpp"


TEST(Collection, Iteration)
{
	Collection<int, int> collection;
	for (int i = 0; i < 22000; i++) {
		collection.insert(std::make_pair(i, i));
	}
	std::cout << "gg\n";
	int i = 0;
	for (auto c : collection) 
	{
		EXPECT_EQ((c).first, i);
		EXPECT_EQ((c).second, i++);
	}
}

TEST(Collection, Iteration2)
{
	Collection<int, int> collection;

	for (int i = 0; i < 1000; i++) 
	{
		collection.insert(std::make_pair(i, i));
	}
	int g = 0;
	//for (auto c : collection)
	//{
	//	EXPECT_EQ(collection[g], g++);
	//}
}
TEST(Collection, Equallity)
{
	Collection<std::string, int> col;
	std::string str = "str";
	for (int i = 0; i < 110; i++) {
		col.insert(std::make_pair(str + std::to_string(i), i));
	}
	Collection<std::string, int> col2;
	for (int i = 0; i < 110; i++) {
		col2.insert(std::make_pair(str + std::to_string(i), i));
	}
	EXPECT_TRUE(col == col2);
}

TEST(Collection, deleting) {
	Collection<std::string, int> col;
	std::string str = "str";
	for (int i = 0; i < 5; i++) {
		col.insert(std::make_pair(str + std::to_string(i), i));
	}
	EXPECT_EQ(col.size(),5);
	std::string str2("str3");
	col.erase(str2);
	EXPECT_EQ(col.size(), 4);
}

TEST(Collection, copyOperator)
{
	Collection<std::string, int> col;
	std::string str = "str";
	for (int i = 0; i < 5; i++) {
		col.insert(std::make_pair(str + std::to_string(i), i));
	}
	Collection<std::string, int> col2;
	col2 = col;
	EXPECT_EQ(col2.size(),col.size());
}
TEST(Collection, copyConstructor)
{
	Collection<std::string, int> col;
	std::string str = "str";
	for (int i = 0; i < 5; i++) {
		col.insert(std::make_pair(str + std::to_string(i), i));
	}
	Collection<std::string, int> col2(col);
	EXPECT_EQ(col2.size(), col.size());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}