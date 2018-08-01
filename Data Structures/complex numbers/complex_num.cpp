#include <iostream>
using namespace std;

class complex
{
    public:
        double r,i;
};

int main(){
    complex z,c;
    z.r = 3.5;
    z.i = 2;
    c.r = 4;
    c.i = 4;
    cout << "z is (" << z.r << ", " << z.i << ")\n";
    return(0);
}