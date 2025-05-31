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

function<void()> EnterNumberInt(int& varLink, string label, istream & is = cin){
    return [&varLink, label, &is](){
        string raw_input;
        cout << label << " = ";
        getline(is,raw_input);
        while (!UserInputInt(raw_input))
        {
            cout << label << " = ";
            getline(is,raw_input);
        }
        varLink = stoi(raw_input);
    };
}

function<void()> EnterString(string& varLink,string label, istream & is = cin){
    return [&varLink,label, &is](){
        string raw_input = "";
        cout << label << " = ";
        getline(is,raw_input);
        while (!UserInputStr(raw_input))
        {
            cout << label << " = ";
            getline(is,raw_input);
        }
        varLink = raw_input;
    };
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
//  Разобраться что такое greater
vector<Project> getSortedProjectsByBudget(vector<Project> projectsToSort) {
    sort(projectsToSort.begin(), projectsToSort.end(), [](const Project& a, const Project& b) {
        return a.calculateAverageBudget() > b.calculateAverageBudget();
    });
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

// Запрос данных при работе конструкторов
void demonstrateDefaultConstructor() {
    cout << "\nDemonstrating Default Constructor:\n";
    Project project;
    cout << project << "\n";
    projects.push_back(project);
}
void demonstrateParameterizedConstructor() {
    cout << "\nDemonstrating Parameterized Constructor:\n";

    string name;
    EnterString(name, "Enter project name: ")();

    string deadline;
    EnterString(deadline, "Enter project deadline: ")();

    int budgetSize;
    EnterNumberInt(budgetSize, "Enter number of budget items: ")();

    Project project(name, deadline, {});
    project.generateRandomBudget(budgetSize);
    cout << project << "\n";
    projects.push_back(project);
}
void demonstrateCopyConstructor() {
    cout << "\nDemonstrating Copy Constructor:\n";
    if (projects.empty()) {
        cout << "Please add at least one project first.\n";
        return;
    }

    int index;
    EnterNumberInt(index, "Enter the index of the project to copy: ")();
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index. Please enter a valid index.\n";
        return;
    }

    Project project3 = projects[index];
    cout << "Copied Project:\n" << project3 << "\n";
    projects.push_back(project3);
}

void demonstrateConversionConstructor() {
    cout << "\nDemonstrating Conversion Constructor:\n";

    string projectName;
    EnterString(projectName, "Enter project name: ")();

    Project project4 = projectName;
    cout << project4 << "\n";
    projects.push_back(project4);
}

void generateRandomBudgets() {
    if (projects.empty()) {
        cout << "No projects available. Please add a project first.\n";
        return;
    }

    int i;
    EnterNumberInt(i, "Enter the index of the project to generate a random budget for: ")();
    if (i < 0 || i >= projects.size()) {
        cout << "Invalid index. Please enter a valid index.\n";
        return;
    }

    int budgetSize;
    EnterNumberInt(budgetSize, "Enter the size of the random budget: ")();
    projects[i].generateRandomBudget(budgetSize);

    cout << "Random budget generated for project at index " << i << ".\n";
    cout << projects[i];
}

void demonstrateAddition() {
    if (projects.size() < 2) {
        cout << "Please add at least two projects to demonstrate addition.\n";
        return;
    }

    int index1;
    EnterNumberInt(index1, "Enter the index of the first project to add: ")();
    if (index1 < 0 || index1 >= projects.size()) {
        cout << "Invalid index for the first project.\n";
        return;
    }

    int index2;
    EnterNumberInt(index2, "Enter the index of the second project to add: ")();
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
    EnterNumberInt(index, "Enter the index of the project to increment: ")();
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index for the project.\n";
        return;
    }

    cout << "Incrementing project at index " << index << " (prefix)...\n";
    cout <<  projects[index] << endl;
    cout  << ++projects[index] << endl;
}

void demonstratePostfixIncrement() {
    if (projects.empty()) {
        cout << "Please add at least one project to demonstrate postfix increment.\n";
        return;
    }

    int index;
    EnterNumberInt(index, "Enter the index of the project to increment: ")();
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index for the project.\n";
        return;
    }

    cout << "Incrementing project at index " << index << " (postfix)...\n";
    cout << projects[index] << endl;
    cout << projects[index]++ << endl;
    cout << projects[index] << endl;
}

void demonstrateAssignment() {
    if (projects.size() < 2) {
        cout << "Please add at least two projects to demonstrate assignment.\n";
        return;
    }

    int index1;
    EnterNumberInt(index1, "Enter the index of the project to assign to: ")();
    if (index1 < 0 || index1 >= projects.size()) {
        cout << "Invalid index for the target project.\n";
        return;
    }

    int index2;
    EnterNumberInt(index2, "Enter the index of the project to assign from: ")();
    if (index2 < 0 || index2 >= projects.size()) {
        cout << "Invalid index for the source project.\n";
        return;
    }

    cout << "Assigning project at index " << index2 << " to project at index " << index1 << "...\n";
    projects[index1] = projects[index2];
    cout << "Project at index " << index1 << " (after assignment):\n" << projects[index1];
}

void demonstrateSetName() {
    int index;
    EnterNumberInt(index, "Enter the index of the project to set name: ")();
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index. Please enter a valid index.\n";
        return;
    }
    string newName;
    EnterString(newName, "Enter the new name: ")();
    projects[index].setName(newName);
    cout << "Updated Project:\n" << projects[index] << "\n";
}

void demonstrateSetDeadline() {
    int index;
    EnterNumberInt(index, "Enter the index of the project to set deadline: ")();
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index. Please enter a valid index.\n";
        return;
    }
    string newDeadline;
    EnterString(newDeadline, "Enter the new deadline: ")();
    projects[index].setDeadline(newDeadline);
    cout << "Updated Project:\n" << projects[index] << "\n";
}

void demonstrateSetBudget() {
    int index;
    EnterNumberInt(index, "Enter the index of the project to set budget: ")();
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index. Please enter a valid index.\n";
        return;
    }

    int budgetSize;
    EnterNumberInt(budgetSize, "Enter the size of the new budget: ")();

    vector<int> newBudget(budgetSize);
    for (int i = 0; i < budgetSize; ++i) {
        EnterNumberInt(newBudget[i], "Enter budget item " + to_string(i + 1) + ": ")();
    }
    projects[index].setBudget(newBudget);
    cout << "Updated Project:\n" << projects[index] << "\n";
}

void demonstrateCalculateAverageBudget() {
    int index;
    EnterNumberInt(index, "Enter the index of the project to calculate average budget: ")();
    if (index < 0 || index >= projects.size()) {
        cout << "Invalid index. Please enter a valid index.\n";
        return;
    }
    cout << "Average Budget: " << projects[index].calculateAverageBudget() << "\n";
}

void demonstrateComparison() {
        if (projects.size() < 2) {
        cout << "Please add at least two projects for demonstrate comparision.\n";
        return;
    }
    int index1;
    EnterNumberInt(index1, "Enter the index of the first project to compare: ")();
    if (index1 < 0 || index1 >= projects.size()) {
        cout << "Invalid index. Please enter a valid index.\n";
        return;
    }

        int index2;
    EnterNumberInt(index2, "Enter the index of the second project to compare: ")();
    if (index2 < 0 || index2 >= projects.size()) {
        cout << "Invalid index. Please enter a valid index.\n";
        return;
    }

        if (projects[index1] > projects[index2])
        {
            cout << "Project " << index1 << " > Project " << index2 << endl;
        } else if(projects[index1] < projects[index2]){
             cout << "Project " << index1 << " < Project " << index2 << endl;
        } else{
             cout << "Project " << index1 << " == Project " << index2 << endl;
        }
        
}
#endif