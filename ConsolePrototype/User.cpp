#include "User.h"

User::User()
{
}

User::User(std::string name)
{
	this->name = name;
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
