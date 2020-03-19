// ConsolePrototype.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"
#include <nlohmann/json.hpp>
#include <fstream>

void askQuestion();
void addHours();
void printHours();
void loadData();
void findUser();
void saveData();
void changeUser();

std::string filename = "data.json";
nlohmann::json data;
User user;
int main()
{
    std::string name;
    std::cout << "Welcome to the registration prototype! What is your name?" << std::endl;
    std::cin >> name;
    
    user = User(name);

    loadData();

    askQuestion();


}

void askQuestion() {
    std::cout << "What would you like to do? 1. Add worked hours 2. Show all worked hours 3. Switch user 4. Exit" << std::endl;

    int option;

    std::cin >> option;

    switch (option)
    {
    case 1:
        addHours();
        break;
    case 2:
        printHours();
        break;
    case 3:
        changeUser();
        break; 
    case 4:
        saveData();
        return;
    default:
        break;
    }
    askQuestion();
}

void addHours()
{
    std::cout << "How many hours have you worked?" << std::endl;
    int hours;
    std::cin >> hours;

    user.addHours(hours);
}

void printHours()
{
    std::vector<int> hours = user.getWorkedHours();
    int totalWorked = 0;
    for (int time : hours)
    {
        totalWorked += time;
        std::cout << "You have worked " << time << " hours" << std::endl;
    }

    std::cout << "All those hours combined you have worked " << totalWorked << " hours" << std::endl;
}

void loadData()
{
    std::fstream file;

    file.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!file) {
        file.open(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
        file << "\n";
        file.close();
    }

    x = nlohmann::json::parse(file);

    file.close();

    findUser();
}

void findUser()
{
    if (data[user.getName()] != NULL) {
        //user = User(user.getName(), data[user.getName()].get_to<std::vector<int>>(user.workedHours));
        user.fromJson(data);
    }

}

void saveData()
{
    data[user.getName()] = user.getWorkedHours();

    std::fstream file;

    file.open(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);

    file.clear();

    file << data;

    file.close();

}

void changeUser()
{
    std::cout << "To what name do you want to switch?" << std::endl;
    std::string name;
    std::cin >> name;

    user = User(name);
    findUser();
}
