#include "M:\projects\LR_OOP\Sheverev_LR3-4_Class_Project\Sheverev_LR3-4_ClassProject.cpp"
#include "M:\projects\LR_OOP\Sheverev_LR3-4_Class_Project\Sheverev_LR3-4_Methods.h"

struct MenuItem {
    string title;
    function<void()> action;
};
int main(){
    map<int,MenuItem> menu = {
        {1, {"Add Project", addProject}},
        {2, {"Display Projects", displayProjects}},
        {3, {"Sort Projects by Budget", sortProjects}},
        {4, {"Demonstrate Constructors", demonstrateAllConstructors}},
        {5, {"Demonstrate Project Methods", demonstrateAllMethods}},
        {6, {"Generate Random Budget", generateRandomBudgets}},
        {7, {"Demonstrate Project Addition", demonstrateAddition}},
        {8, {"Demonstrate Prefix Increment", demonstratePrefixIncrement}},
        {9, {"Demonstrate Postfix Increment", demonstratePostfixIncrement}},
        {10, {"Demonstrate Assignment", demonstrateAssignment}}
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