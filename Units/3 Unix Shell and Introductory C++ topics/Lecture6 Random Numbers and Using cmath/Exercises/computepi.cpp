#include <iostream>
#include <random>
#include <ctime>
#include <cmath>

//Use Define to define the total number of darts to throw using the variable Ntot
#define ...
int main()
{
    // Initialize the number of darts that make it inside the circle, Nhit 
    int Nhit =  ...  // HINT: This starts at zero

    // initialize random seed in the next line
    srand((unsigned) time(0));
    // Now we are going to start "throwing darts". We will do this using a for
    // loop. Look back at out HelloWorld5_* examples to fill in the loop below.
    // Set this loop to run over all the darts (while i is less than Ntot)
    for ()
    {
        // set random numbers in the box - Think of these random numbers as coordinates
	// for where your dart landed. Therefor, x and y need to be a ranom number 
	// between 0 and 1 - the domain of our box. NOTE the (double) casts the integer type
	// to a double so that we do not just get 0 and 1.
        double x = (double) ...
        double y = (double) ...

        // check if the random numbers lie in the circle using the formula in the slides, 
	if (...)
	{
	// if the dart landed in the circle increase the number of darts that made it in the 
	// circle by 1
	   ...       

        }
    }

    // compute pi using the formula from the slides when multipying by 4, make sure 4 is a double! 
    // Remember, Nhit and Ntot here are integers and we want pi to be a double. 
    double pi = ...// insert formula

    // print the result to your screen using cout

    return 0;
       

}
