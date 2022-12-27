#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int num, guess, tries = 0;
  srand(time(0)); // seed random number generator
  num = rand() % 1000 + 1; // random number between 1 and 1000
  cout << "Guess Number Game\n\n";

  do
  {
    cout << "Enter a # between 1 and 1000: ";
    cin >> guess;
    tries++;

    if (guess > num)
      cout << "Too high!\n\n";
    else if (guess < num)
      cout << "Too low!\n\n";
    else
      cout << "\nCorrect! Just " << tries << "!\n";
  } while (guess != num);

  return 0;
}

