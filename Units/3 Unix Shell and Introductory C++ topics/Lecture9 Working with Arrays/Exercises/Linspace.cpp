#include <iostream>
using namespace std;

// create a function called linspace to do all the hard work
// it takes as arguments a pointer to an array, the lower and upper bounds
// and the number of cells you want to divide the domain into
void linspace(double* x, double xa, double xb, int n)
{
    // compute the width of each element
    double dx = (xb - xa) / n;

    // 'x' is now an array so loop through its elements
    for (int i = 0; i <= n; i++)
    {
        // now update the element 'i' of the array 'x'
        x[i] = xa + i * dx;
    }
    //let's check our results
    //loop through the elements of x
    for (int i = 0; i <= n; i++)
    {
        // let's print it to screen to check our result
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}


int main()
{
    // number of cells in the domain
    int n = 10;

    // bounds of the domain (must be of type double)
    double xa = 2;
    double xb = 3;

    // create an array (dynamic)
    double* x = new double[n+1];

    // call the linspace function
    linspace(x,xa,xb,n);

    //Don't forget to clean up your memory!
    delete[] x;

    // you always need this at end of main routine
    return 0;
}
