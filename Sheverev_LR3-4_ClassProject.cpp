#include "M:\projects\LR_OOP\Sheverev_LR3-4_Class_Project\Sheverev_LR3-4_ClassProject.h"
#include "M:\projects\LR_OOP\Sheverev_LR3-4_Class_Project\Sheverev_LR3-4_Methods.h"

Project::Project() : name("Unknown"), deadline("TBD"), budget(vector<int>()) {}

Project::Project(const string& name, const string& deadline, const vector<int>& budget) :
    name(name), deadline(deadline), budget(budget) {}

Project::Project(const Project& other) :
    name(other.name), deadline(other.deadline), budget(other.budget) {}

Project::Project(const string& name) : name(name), deadline("TBD"), budget(vector<int>()) {}

Project::Project(string&& name, string&& deadline, vector<int>&& budget):
    name(move(name)),
    deadline(move(deadline)),
    budget(move(budget)){}

double Project::calculateAverageBudget() const {
    if (budget.empty()) {
        return 0.0;
    }
    double sum = accumulate(budget.begin(), budget.end(), 0);
    return static_cast<double>(sum) / budget.size();
}

void Project::generateRandomBudget(int size) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(nullptr));
        seeded = true;
    }
    budget.resize(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 100000);

    for (int i = 0; i < size; i++) {
        budget[i] = dis(gen);
    }
}

ostream& operator<<(ostream& os, const Project& project) {
    os << "Name: " << project.name << "\n";
    os << "Deadline: " << project.deadline << "\n";
    os << "Budget: ";
    for (int b : project.budget) {
        os << b << " ";
    }
    os << "\n";
    return os;
}

istream& operator>>(istream& is, Project& project) {
    cout << "Enter name: ";
    getline(is >> ws, project.name);

    cout << "Enter deadline: ";
    getline(is >> ws, project.deadline);

    int budgetSize;
    cout << "Enter budget size: ";
    is >> budgetSize;
    project.budget.resize(budgetSize);

    cout << "Enter budget values: ";
    for (int i = 0; i < budgetSize; ++i) {
        is >> project.budget[i];
    }

    return is;
}

bool Project::operator>(const Project& other) const {
    return calculateAverageBudget() > other.calculateAverageBudget();
}

bool Project::operator<(const Project& other) const {
    return calculateAverageBudget() < other.calculateAverageBudget();
}

bool Project::operator==(const Project& other) const {
    return calculateAverageBudget() == other.calculateAverageBudget();
}

bool Project::operator!=(const Project& other) const {
    return calculateAverageBudget() != other.calculateAverageBudget();
}

Project Project::operator+(const Project& other) const {
    Project result = *this;
    result.budget.insert(result.budget.end(), other.budget.begin(), other.budget.end());
    return result;
}

Project& Project::operator++() {
    for (int& b : budget) {
        b = static_cast<int>(round(b * 1.10));
    }
    return *this;
}

Project Project::operator++(int) {
    Project temp = *this;
    ++(*this);
    return temp;
}

Project& Project::operator--(){
     for (int& b : budget) {
        b = static_cast<int>(round(b * 0.90));
    }
    return *this;
}

Project Project::operator--(int){
    Project temp = *this;
    --(*this);
    return temp;
}

Project& Project::operator=(const Project& other) {
    if (this == &other) {
        return *this;
    }
    name = other.name;
    deadline = other.deadline;
    budget = other.budget;
    return *this;
}

int& Project::operator[](int index) {
    if (index >= 0 && index < budget.size()) {
        return budget[index];
    }
    else{
        throw out_of_range("Index out of range");
    }
}

Project Project::operator*(const Project& other) const{
    Project result = *this;
    for(size_t i = 0; i < result.budget.size() && i < other.budget.size(); ++i){
        result.budget[i] *= other.budget[i];
    }
    return result;
}

Project::~Project() {}