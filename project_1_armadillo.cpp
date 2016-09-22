#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <armadillo>
#include "lib.cpp"
using namespace std;
using namespace arma;

// LU decomposition

int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);
    int i, j;
    double h;
    double x_i;
    vec z = zeros<vec> (n);
    vec v = zeros<vec> (n);
    vec f = randu<vec> (n);
    mat A = randu<mat> (n,n);
    mat L, U, P;

    h = 1.0/(n+1.0);

    // The inhomogenous term
    for (i=0; i < n; i++) {
        x_i = (1+i)*h;
        f(i) = 100*exp(-10*x_i)*h*h;
        //cout << x_i << endl;
    }


    // Setting up the matrix A
    for (i=0; i < n; i++){
        for (j=0; j < n; j++){

            if (j == i) {
                A(i,j) = 2.0;

            }
            else if (j == i+1){
                A(i,j) = -1.0;
            }

            else if (j == i-1){
                A(i,j) = -1.0;

            }

            else {
                A(i,j) = 0.0;
            }
        }

    }

    // Starting clock
    clock_t start, finish;
    start = clock();


    // Here we solve the equation, first LU decomposition
    // Then we solve the equations Lz = y, ux = z, where v is the discrete values of u
    lu(L, U, P, A);

    z = inv(L)*f;
    v = inv(U)*z;


    // Finishing clock
    finish = clock();
    cout << (finish - start)/(double) CLOCKS_PER_SEC << endl;



}
