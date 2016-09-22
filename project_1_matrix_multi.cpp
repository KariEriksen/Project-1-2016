#include <iostream>
#include <time.h>
#include <armadillo>
#include "lib.cpp"
using namespace std;
using namespace arma;

// This program calculates two matrices togheter

int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);
    int i, j, k;
    mat A = zeros<mat> (n,n);
    mat B = randu<mat> (n,n);
    mat C = randu<mat> (n,n);


    // Starting clock
    clock_t start, finish;
    start = clock();

    // Multiplying matrix B and C, A = BC
    for (i=0; i < n; i++) {
        for (j=0; j < n; j++) {
            for (k=0; k < n; k++) {

                A(i,j) += B(i,k)*C(k,j);
            }
        }
    }

    // Finishing clock
    finish = clock();
    cout << (finish - start)/(double) CLOCKS_PER_SEC << endl;



}
