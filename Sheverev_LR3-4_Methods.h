#ifndef SHEVEREV_LR3_4_METHODS_H
#define SHEVEREV_LR3_4_METHODS_H

#include "M:\projects\LR_OOP\Sheverev_LR3-4_Class_Project\Sheverev_LR3-4_ClassProject.h"

vector<Project> projects;


bool UserInputInt(string input){
    if(input.empty()) return false;

    try
    {
        int number = stoi(input);
        if (number < 0) return false;
        
    }
    catch(const std::exception& e)
    { return false;}

    return true;
}

bool UserInputStr(string input){
    if(input.empty()) return false;
    else return true;
}

function<void()> EnterNumberInt(int& varLink, string label){
    return [&varLink, label](){
        string raw_input;
        cout << label << " = ";
        getline(cin,raw_input);
        while (!UserInputInt(raw_input))
        {
            cout << label << " = ";
            getline(cin,raw_input);
        }
        varLink = stoi(raw_input);
    };
}

function<void()> EnterString(string& varLink,string label){
    return [&varLink,label](){
        string raw_input = "";
        cout << label << " = ";
        getline(cin,raw_input);
        while (!UserInputStr(raw_input))
        {
            cout << label << " = ";
            getline(cin,raw_input);
        }
        varLink = raw_input;
    };
}

string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}


void displayAllProjects(const vector<Project>& projects) {
    if (projects.empty()) {
        cout << "No projects to display.\n";
        return;
    }
    for (const auto& project : projects) {
        cout << project << "\n";
    }
}

vector<Project> getSortedProjectsByBudget(vector<Project> projectsToSort) {
    sort(projectsToSort.begin(), projectsToSort.end(), greater<Project>());
    return projectsToSort;
}

void addProject() {
    Project newProject;
    cin >> newProject;
    projects.push_back(newProject);
}

void displayProjects() {
    displayAllProjects(projects);
}

void sortProjects() {
    vector<Project> sortedProjects = getSortedProjectsByBudget(projects);
    displayAllProjects(sortedProjects);
}

void demonstrateAllConstructors() {
   cout << "\nDemonstrating Constructors:\n";

    Project project1;
    cout << "Default Constructor:\n" << project1 << "\n";

    vector<int> budget = {100000, 200000, 300000};
    Project project2("New Project", "2024-12-31", budget);
    cout << "Parameterized Constructor:\n" << project2 << "\n";

    Project project3 = project2;
    cout << "Copy Constructor:\n" << project3 << "\n";

    Project project4("Simple Project");
    cout << "Conversion Constructor:\n" << project4 << "\n";
}

void demonstrateAllMethods() {
    cout << "\nDemonstrating Project Methods:\n";

    Project project("Test Project", "2024-12-31", {50000, 75000, 100000});
    cout << "Initial Project:\n" << project << "\n";

    cout << "Average Budget: " << project.calculateAverageBudget() << "\n";

    project.setName("Updated Project Name");
    project.setDeadline("2025-06-30");
    project.setBudget({60000, 85000, 110000});
    cout << "Updated Project:\n" << project << "\n";
}

void generateRandomBudgets() {
    if (projects.empty()) {
        cout << "No projects available. Please add a project first.\n";
        return;
    }

    int index;
    EnterNumberInt(index, "Enter the index of the project to generate a random budget for: ");
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index. Please enter a valid index.\n";
        return;
    }

    int budgetSize;
    EnterNumberInt(budgetSize, "Enter the size of the random budget: ");
    projects[index].generateRandomBudget(budgetSize);

    cout << "Random budget generated for project at index " << index << ".\n";
    cout << projects[index];
}

void demonstrateAddition() {
    if (projects.size() < 2) {
        cout << "Please add at least two projects to demonstrate addition.\n";
        return;
    }

    int index1;
    EnterNumberInt(index1, "Enter the index of the first project to add: ");
    if (index1 < 0 || index1 >= projects.size()) {
        cout << "Invalid index for the first project.\n";
        return;
    }

    int index2;
    EnterNumberInt(index2, "Enter the index of the second project to add: ");
    if (index2 < 0 || index2 >= projects.size()) {
        cout << "Invalid index for the second project.\n";
        return;
    }

    cout << "Adding project at index " << index1 << " and project at index " << index2 << "...\n";
    Project result = projects[index1] + projects[index2];
    cout << "Resulting project:\n" << result;
}

void demonstratePrefixIncrement() {
    if (projects.empty()) {
        cout << "Please add at least one project to demonstrate prefix increment.\n";
        return;
    }

    int index;
    EnterNumberInt(index, "Enter the index of the project to increment: ");
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index for the project.\n";
        return;
    }

    cout << "Incrementing project at index " << index << " (prefix)...\n";
    ++projects[index];
    cout << "Resulting project:\n" << projects[index];
}

void demonstratePostfixIncrement() {
    if (projects.empty()) {
        cout << "Please add at least one project to demonstrate postfix increment.\n";
        return;
    }

    int index;
    EnterNumberInt(index, "Enter the index of the project to increment: ");
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index for the project.\n";
        return;
    }

    cout << "Incrementing project at index " << index << " (postfix)...\n";
    Project temp = projects[index]++;
    cout << "Original project (after increment):\n" << projects[index];
    cout << "Copy of project (before increment):\n" << temp;
}

void demonstrateAssignment() {
    if (projects.size() < 2) {
        cout << "Please add at least two projects to demonstrate assignment.\n";
        return;
    }

    int index1;
    EnterNumberInt(index1, "Enter the index of the project to assign to: ");
    if (index1 < 0 || index1 >= projects.size()) {
        cout << "Invalid index for the target project.\n";
        return;
    }

    int index2;
    EnterNumberInt(index2, "Enter the index of the project to assign from: ");
    if (index2 < 0 || index2 >= projects.size()) {
        cout << "Invalid index for the source project.\n";
        return;
    }

    cout << "Assigning project at index " << index2 << " to project at index " << index1 << "...\n";
    projects[index1] = projects[index2];
    cout << "Project at index " << index1 << " (after assignment):\n" << projects[index1];
}

#endif