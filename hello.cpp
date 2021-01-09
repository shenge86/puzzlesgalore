#include <iostream>
using namespace std;

int num1 = 10; // C-like initialization
int num2 {3}; // C++11 list initialization syntax <- RECOMMENDED
double num3 (21.1); // Constructor initialization

int main() 
{    
    cout << "Initial numbers have values: " << num1 << " and " << num2 << endl;

    cout << "Enter 2 integers separated with a space: ";
    cin >> num1 >> num2;
    cout << "You entered " << num1 << " and " << num2 << endl;
    
    return 0;
}
