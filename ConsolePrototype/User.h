#pragma once
#include <string>
#include <vector>
class User
{
private:
	std::string name;
	std::vector<int> workedHours;

public:
	User();
	User(std::string name);
	std::string& getName();
	void setName(std::string& name);
	std::vector<int>& getWorkedHours();
	void addHours(int& hours);
};

