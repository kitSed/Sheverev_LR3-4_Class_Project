#include "M:\projects\LR_OOP\Sheverev_LR3-4_Class_Project\Sheverev_LR3-4_ClassProject.cpp"

struct MenuItem {
    string title;
    function<void()> action;
};
int main(){
    map<int,MenuItem> menu = {
        {1, {"Add Project", addProject}},
        {2, {"Display Projects", displayProjects}},
        {3, {"Sort Projects by Budget", sortProjects}},
        {4, {"Demonstrate Default Constructor", demonstrateDefaultConstructor}},
        {5, {"Demonstrate Parameterized Constructor", demonstrateParameterizedConstructor}},
        {6, {"Demonstrate Copy Constructor", demonstrateCopyConstructor}},
        {7, {"Demonstrate Conversion Constructor", demonstrateConversionConstructor}},
        {8, {"Demonstrate Set Name", demonstrateSetName}},
        {9, {"Demonstrate Set Deadline", demonstrateSetDeadline}},
        {10, {"Demonstrate Set Budget", demonstrateSetBudget}},
        {11, {"Demonstrate Calculate Average Budget", demonstrateCalculateAverageBudget}},
        {12, {"Demonstrate Comparison", demonstrateComparison}},
        {13, {"Demonstrate Project Addition", demonstrateAddition}},
        {14, {"Demonstrate Prefix Increment", demonstratePrefixIncrement}},
        {15, {"Demonstrate Postfix Increment", demonstratePostfixIncrement}},
        {16, {"Demonstrate Assignment", demonstrateAssignment}}
    };
    int choice = 0;

    while(true) {
        cout << "Menu:" << endl;
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Exit" << endl;
        
        EnterNumberInt(choice, "Enter number task: ")();
        
        if(choice == 0) {
            cout << "@ 2025 Sheverev" << endl;
            break;
        }
        cout << endl;

        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Incorrect input.";
        }
        cout << endl << endl;
    }
return 0;
}