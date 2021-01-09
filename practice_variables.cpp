#include <iostream>
#include <string>
using namespace std;

// function prototypes
void employee_profile();

void employee_profile() {
    
    //----WRITE YOUR CODE BELOW THIS LINE----
    int age {0};
    double hourly_wage {23.50};
    string name {"h"};

    cout << "Age: ";
    cin >> age;

    cout << "\nName: ";
    cin >> name;
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << name << " " << age << " " << hourly_wage;    
}

int main() {
    employee_profile();

    return 0;
}