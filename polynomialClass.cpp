#include <stdlib.h>
#include <iostream>
using namespace std;

// A class for polynomials //

class Polynomial
{
private:
    double *coefficients; //this will be the array where we store the coefficients       
    int degree; //this is the degree of the polynomial (i.e. one less then the length of the array of coefficients)

public:
    Polynomial(); //the default constructor to initialize a polynomial equal to 0
    Polynomial(double coeffs[] , int nterms); //the constructor to initialize a polynomial with the given coefficient array and degree
    Polynomial(Polynomial&); //the copy constructor
    Polynomial(double); //the constructor to initialize a polynomial equal to the given constant
    ~Polynomial() { delete coefficients; } //the deconstructor to clear up the allocated memory
    int print_polynomial();

    //Operations on polynomials

    // Addition of two polynomials
    Polynomial operator+(Polynomial p){
        Polynomial q;
         q.degree = this->degree;
         q.coefficients = new double[q.degree];
         for (int i = 0; i < q.degree; i++){
             q.coefficients[i] = p.coefficients[i] + this->coefficients[i];
         }
         return q;
    }

    // Difference of two polynomials
    Polynomial operator-(Polynomial p){
        Polynomial q;
         q.degree = this->degree;
         q.coefficients = new double[q.degree];
         for (int i = 0; i < q.degree; i++){
             q.coefficients[i] = this->coefficients[i] -p.coefficients[i];
         }
         return q;
    }

     // Multiplication of two polynomials
    Polynomial operator*(Polynomial p){
        Polynomial q;
        q.degree = this->degree + p.degree;
        q.coefficients = new double[q.degree];
        for (int i = 0; i < q.degree; i++){
            double sum = 0;
            for (int k = 0; k < i; k++){
                sum += p.coefficients[k]*this->coefficients[i-k];
            }
            q.coefficients[i] = sum;
        }
        return q;
    }
};

//This is the default constructor 
Polynomial::Polynomial() {
    degree = 0;
    coefficients = new double[degree + 1];
    coefficients[0] = 0;
}

//Initialize a polynomial with the given coefficient array and degree
Polynomial::Polynomial(double coeffs[], int nterms){
    degree = nterms-1;
    coefficients = new double[nterms]; //array to hold coefficient values
    for(int i = 0; i < nterms; i++)
        coefficients[i] = coeffs[i];
}

int Polynomial::print_polynomial(){
    cout << "The degree is " << this->degree << '\n';
    for (int k = 0; k < this->degree+1; k++){
        cout << this->coefficients[k] << "(x_" << k << ")";
        if (k != this->degree){
            cout << "+";
        }
    }
    cout << "\n";
    return(0);
}

int main(){
    double coeffQ[3] = {1,2,3};
    double coeffP[3] = {1,4,9};
    Polynomial Q(coeffQ,3);
    Polynomial P(coeffP,3);
    P.print_polynomial();
    Q.print_polynomial();
    return(0);
}