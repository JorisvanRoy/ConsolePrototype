#pragma once
#include <string>
#include <vector>
#include <nlohmann\json.hpp>
class User
{
private:
	std::string name;
	std::vector<int> workedHours;

public:
	User();
	User(std::string name);
	User(std::string name, std::vector<int> workedHours);
	std::string& getName();
	void setName(std::string& name);
	std::vector<int>& getWorkedHours();
	void addHours(int& hours);
	void fromJson(const nlohmann::json& j);
};