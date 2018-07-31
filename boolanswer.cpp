#include <iostream>
using namespace std;

bool accept()
{
    cout << "How about y or n?\n";
    char answer;
    cin >> answer;
    if (answer == 'y') return true;
    return false;
}

