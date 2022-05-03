#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>

//Use Define to define the total number of darts to throw using the variable Ntot
#define Ntot 1e6
int main()
{
    // Initialize the number of darts that make it inside the circle, Nhit 
    int Nhit =  0;   // HINT: This starts at zero

    // initialize random seed in the next line
    srand((unsigned) time(0));
    // Now we are going to start "throwing darts". We will do this using a for
    // loop. Look back at out HelloWorld5_* examples to fill in the loop below.
    // set this loop to run over all the darts (while i is less than Ntot)
    for (int i = 0; i < Ntot; i++)
    {
        // set random numbers in the box - Think of these random numbers as coordinates
	// for wher your dart landed. Therefor, x and y need to be a ranom number 
	// between 0 and 1 - the domain of our box.
        double x = (double) rand()/RAND_MAX;
        double y = (double) rand()/RAND_MAX;

        // check if the random numbers lie in the circle using the formula in the slides, 
	if (sqrt(pow(x-0.5,2.0)+pow(y-0.5,2.0))<0.5)
	{
	// if the dart landed in the circle increase the number of darts that made it in the 
	// circle by 1           
	    Nhit++;
        }
    }

    // compute pi using the formula from the slides
    double pi = 4.0*(double) Nhit/ (double) Ntot;// insert formula

    // print the result to your screen
    printf("%f\n",pi);

}
