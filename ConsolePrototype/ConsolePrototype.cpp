// ConsolePrototype.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"

void askQuestion();
void addHours();
void printHours();

User user;
int main()
{
    std::string name;
    std::cout << "Welcome to the registration prototype! What is your name?" << std::endl;
    std::cin >> name;
    
    user = User(name);

    askQuestion();


}

void askQuestion() {
    std::cout << "What would you like to do? 1. Add worked hours 2. Show all worked hours" << std::endl;

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
