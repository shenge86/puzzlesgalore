#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  // int money;
  int num, guess, tries = 0;
  const int maxnum {1000};
  const long long distance_to_alpha_centauri {9'461'000'000'000};

  srand(time(0)); // seed random number generator
  num = rand() % maxnum + 1; // random number between 1 and 1000
  cout << "Guess Number Game\n\n";
  cout << "This code may give some interesting numbers and you may learn something new.\n\n";
  cout << "For instance: Distance to alpha centauri is: " << distance_to_alpha_centauri << "\n";
  cout << "===================================================================================\n";
  // cout << "Let us presume you start with: " << money << endl;

  do
  {
    cout << "Enter a # between 1 and 1000: ";    
    cin >> guess;

    if (guess > maxnum)
      cout << "Number must be smaller than " << maxnum << "!\n";
    else if (guess < 1)
      cout << "Number must be greater than 1!\n";    
    else if (guess > num) {
      cout << "Too high!\n\n";
      tries++;
    } else if (guess < num) {
      cout << "Too low!\n\n";
      tries++;
    } else
      cout << "\nCorrect! Just " << tries << "!\n";      
  } while (guess != num);

  return 0;
}

