#include "User.h"

User::User()
{
}

User::User(std::string name)
{
	this->name = name;
}

User::User(std::string name, std::vector<int> workedHours)
{
	this->name = name;
	this->workedHours = workedHours;
}

std::string& User::getName()
{
	return name;
}

void User::setName(std::string& name)
{
	this->name = name;
}

std::vector<int>& User::getWorkedHours()
{
	return workedHours;
}

void User::addHours(int& hours)
{
	workedHours.push_back(hours);
}

void User::fromJson(const nlohmann::json& j)
{
	j[name].get_to<std::vector<int>>(workedHours);
}
