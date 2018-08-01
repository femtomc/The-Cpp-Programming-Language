#include <iostream>
using namespace std;

class complex
{
    public:
        double get_r() {return r; }
        void set_r (double newr) { r = newr ;}
        double get_i() {return i; }
        void set_i (double newi) { i = newi ;}

    private:
        double r,i;
};

int main(){
    complex z,c;
    z.set_r(3.5);
    z.set_i(2);
    c.set_r(4);
    c.set_i(4);
    cout << "z is (" << z.get_r()<< ", " << z.get_i() << ")\n";
    return(0);
}