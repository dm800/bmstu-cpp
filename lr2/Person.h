#pragma once
#include <string>

class Person
{
    public:
    double height;
    double weight;
    int year;
    std::string name;
    std::string surname;
    char pol;
    Person(double height, double weight, int year, std::string name, std::string surname, char pol)
    {
        this->height = height;
        this->weight = weight;
        this->year = year;
        this->name = name;
        this->surname = surname;
        this->pol = pol;
    }
    Person()
    {
        this->height = 0;
        this->weight = 0;
        this->year = 0;
        this->name = "";
        this->surname = "";
        this->pol = 'M';
    }

    static Person* getRandom()
    {
        return new Person(rand() % 100 + 100, rand() % 100 + 30, rand() % 100 + 1950, "Name", "Surname", 'M');
    }
};