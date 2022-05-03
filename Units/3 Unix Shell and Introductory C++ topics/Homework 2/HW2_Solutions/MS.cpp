#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>

// Defining the known value of PI with high accuracy
#define MYPI 3.141592653589793238

int main()
{
    // declaring variables "error", "current_err", and "pi"
    double error;
    double current_err;
    double pi;
    // asking for user's input and assigning it to variable "error"
    std::cout << "Enter the desired accuracy for the value of pi: ";
    std::cin >> error;
    // initializing Nhit, Ntot
    int Nhit = 0;
    int Ntot = 0;
    // initializing the current_err to be larger than the error
    current_err = 1000.0;
    srand((unsigned) time(0));

    while (current_err >= error) // checks for the desired accuracy
    {
        // set random numbers in the box - Think of these random numbers as coordinates
        // for wher your dart landed. Therefor, x and y need to be a ranom number 
        // between 0 and 1 - the domain of our box.
        Ntot++; //increments Ntot by 1
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        // check if the random numbers lie in the circle using the formula in the slides, 
        if (sqrt(pow(x - 0.5, 2) + pow(y - 0.5, 2)) < 0.5) { Nhit++; }
       // std::cout<<Nhit<<std::endl;
        pi = 4.0 * (double)Nhit / (double)Ntot; // calculates the value of pi
//        current_err = abs(pi - MYPI)/pi; // calculates current_err
        current_err = abs(MYPI - pi)/MYPI;
        std::cout<<current_err<<std::endl;
        std::cout<<pi<<std::endl;
        std::cout<<MYPI<<std::endl;   
    }
    std::cout<< pi << std::endl; // prints out the value of pi
}

