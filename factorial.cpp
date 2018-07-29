#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    else
    {
        return n*factorial(n-1);
    }
}

int main()
{
    int k, n;
    cout << "Enter a positive integer: ";
    cin >> k;
    n = factorial(k);
    cout << n;
    cout << "\n";
}