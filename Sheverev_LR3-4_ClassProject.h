#ifndef SHEVEREV_LR3_4_CLASSPROJECT_H
#define SHEVEREV_LR3_4_CLASSPROJECT_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
#include <sstream>
#include <map>
#include <functional>
#include <random>

using namespace std;

class Project {
private:
    string name;
    string deadline;
    vector<int> budget;

public:

    Project();
    Project(const string& name, const string& deadline, const vector<int>& budget);
    Project(const Project& other);
    Project(const string& name);
    Project(string&& name, string&& deadline, vector<int>&& budget);

    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }
    string getDeadline() const { return deadline; }
    void setDeadline(const string& deadline) { this->deadline = deadline; }
    vector<int> getBudget() const { return budget; }
    void setBudget(const vector<int>& budget) { this->budget = budget; }

    double calculateAverageBudget() const;
    void generateRandomBudget(int size);

    friend ostream& operator<<(ostream& os, const Project& project);
    friend istream& operator>>(istream& is, Project& project);

    bool operator>(const Project& other) const;
    Project operator+(const Project& other) const;
    Project& operator++();
    Project operator++(int);
    Project& operator--();
    Project operator--(int);
    Project& operator=(const Project& other);
    int& operator[](int index);
    bool operator<(const Project& other) const;
    bool operator==(const Project& other) const;
    bool operator!=(const Project& other) const;
    Project operator*(const Project& other) const;
    
    ~Project();
};

#endif