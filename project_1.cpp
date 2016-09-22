#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <armadillo>
using namespace std;

/* This program solves the general one-dimensional Poisson equation.
Using Dirichlet boundary condition, rewriting it to a set of linear equations.*/


int main(int argc, char* argv[]) {

    // Defining variables.
    int n;
    cout <<"Give an integer: ";
    cin >> n;

    //n = atoi(argv[1]);

    double* a_i = new double[n];
    double* b_i = new double[n];
    double* c_i = new double[n];
    double* v_i = new double[n];
    double* f_i = new double[n];

    int i, k;
    double x_i;
    double h;
    double factor;


    h = 1.0/(n+1.0);

    for (i=0; i < n; i++) {
        x_i = (i+1)*h;
        f_i[i] = 100*exp(-10*x_i)*h*h;
        //cout << x_i << endl;


    }

    for (k=0; k < n; k++) { a_i[k] = -1.0; }

    for (k=0; k < n; k++) { b_i[k] = 2.0; }

    for (k=0; k < n; k++) { c_i[k] = -1.0; }


    // Starting clock
    clock_t start, finish;
    start = clock();



    // Forward substitution
    for (i=0; i < n-1; i++) {

        factor = a_i[i+1]/b_i[i];
        //cout << b_i[i] << endl;

        b_i[i+1] = b_i[i+1] - c_i[i]*factor;
        f_i[i+1] = f_i[i+1] - f_i[i]*factor;
        //cout << b_i[i+1] << endl;

    }

    //The first row of the backward sub is very simple
    v_i[n-1] = f_i[n-1]/b_i[n-1];
    //cout << v_i[n-1] << endl;



    // Backward substitution
    for (i=n-2; i >= 0; i--) {

        v_i[i] = (f_i[i] - c_i[i]*v_i[i+1])/b_i[i];
        //cout << b_i[i] << endl;

    }


    // Finishing clock
    finish = clock();
    cout << (finish - start)/(double) CLOCKS_PER_SEC << endl;


    fstream outFile;
    outFile.open("data.dat", ios::out);

    outFile << n << endl;
    for (i=0; i < n; i++) {
        outFile << v_i[i] << endl;

    }
    outFile.close();
    return 0;

}

