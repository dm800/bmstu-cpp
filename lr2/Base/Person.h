#pragma once
#include <string>
#include <fstream>
#include <random>


class Person
{
    public:
    double height;
    double weight;
    int year;
    std::string name;
    std::string surname;
    static std::string* surnames[100];
    static std::string* Fnames[100];
    static std::string* Mnames[100];
    char pol;

    static void Generator() {
        std::ifstream file;
        if (surnames[0] == nullptr) {
            file.open("./data/Surname.txt");
            for (int i = 0; i < 100; i++)
            {
                surnames[i] = new std::string;
                file >> *surnames[i];
            }
            file.close();
        }
        if (Fnames[0] == nullptr) {
            file.open("./data/Fname.txt");
            for (int i = 0; i < 100; i++)
            {
                Fnames[i] = new std::string;
                file >> *Fnames[i];
            }
            file.close();
        }
        if (Mnames[0] == nullptr) {
            file.open("./data/Mname.txt");
            for (int i = 0; i < 100; i++)
            {
                Mnames[i] = new std::string;
                file >> *Mnames[i];
            }
            file.close();
        }
    }

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

    static Person* getRandom() {
        Generator();
        std::random_device rd;
        std::mt19937 mt(rd());
        int p = mt() % 2;
        if (p == 0)
        {
            return new Person(mt() % 60 + 150, mt() % 100 + 50, mt() % 100 + 1950, *Mnames[mt() % 100], *surnames[mt() % 100], 'M');
        }
        return new Person(mt() % 60 + 150, mt() % 100 + 50, mt() % 100 + 1950, *Fnames[mt() % 100], *surnames[mt() % 100] + "а", 'F');
    }

    bool operator==(const Person& other) const {
        return height == other.height && weight == other.weight && year == other.year && name == other.name && surname == other.surname && pol == other.pol;
    }

    bool operator!=(const Person & last) const {
        return !(*this == last);
    }
};