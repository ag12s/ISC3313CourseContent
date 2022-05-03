#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;
//Use #define to define the tru pi to high accuracy
#define MYPI 3.141592653589793238 
int main()
{
    // Initialize the total number of darts thrown. This is also a counter for 
    // our while loop.
    int Ntot = 0; //Starts at 0.
    // Initialize the number of darts that make it inside the circle, Nhit 
    int Nhit =  0;   //This starts at zero
    // Initialize the tolerance specified by the user
    double tol;
    // Initialize the error that will be calculated in the loop
    double err = 1000.00; //this error can be whatever you want, it just has to
                          //be bigger than the tolerance so your loop runs.    
    // We also need to initialize pi outside of the while loop so we can print it after
    double pi;
    // initialize random seed in the next line
    srand((unsigned) time(0));
  
    //Ask the user to set their tolerance
    cout << "please set your tolerance:";
    cin >> tol;  
 
    // Now we are going to start "throwing darts". We will do this using a while
    // loop. 
    // we set this loop to run until our error is less than or equal to the user
    // specified tolerance. The = isn't neccessary because it wasn't explicitly 
    // stated in the problem, but it will give you more accuracy.
    while (err >= tol) 
    {
        //Count the number of darts thrown by adding one to Ntot     
        Ntot++;
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
       //compute pi using the formula
       pi = 4.0*(double)Nhit/(double)Ntot;
       //compute the error
       err = abs(MYPI-pi)/MYPI; //order here doesn't matter. You can switch MYPI and pi
    }

    // print the result to your screen
    cout<<"the approximate value for pi is:"<<pi<<endl;
    cout<<"Ntot ="<<Ntot<<endl;

}
