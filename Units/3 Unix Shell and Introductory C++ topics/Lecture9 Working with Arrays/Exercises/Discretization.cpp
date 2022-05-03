#include <iostream>
using namespace std;

int main()
{
    // number of elements in the domain
    int n = 20;

    // bounds of the domain (must be of type double)
    double xa = 0;
    double xb = 20;

    // compute the width of each element (also a double)
    double dx = (xb - xa) / n;

    // declare a pointer to a group of 'n+1' elements created by 'new'
    // NOTE that the pointer must be of type double
    // and also that we need n+1 because if there are 20 elements then there are 21
    // points
    double* x = new double[n+1];

    // 'x' is now an array so loop through its elements and compute the
    // coordinates
    for (int i = 0; i <= n; i++)
    {
        // now update the element 'i' of the array 'x'
        x[i] = i * dx;

        // let's print it to screen to check our result
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    // don't forget to clean up the memory created by 'new'
    delete[] x;

    // you always need this at end of main routine
    return 0;
}
