#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//define our function fm
double f(double x)
{
        return tanh(pow(x,2)-9.0);
}

//define our function for the derivative of fm
double df(double x)
{
        return 2*x*(1.0-pow(tanh(pow(x,2)-9.0),2));

}	

void NewtonRaphson(double x)
{
	//have the user define the tolerance and the maximum number of iterations
	double tol=0.01;
	int Maxit;
	cout<<"Maximum iterations? ";
	cin>>Maxit;

	int i = 0; //Counter for our while loop
	double error = 2*tol; //set the error to be bigger than the tolerance
	double x_new = 0.1;	//declare x_new, which is x_i+1. x is x_i

	//we want to iterate while the iteration counter is less than the iteration cap
	//and also while the function value isn't close to 0
	while(i<Maxit && abs(f(x))>tol)
	{
		//Newton-Raphson formula
		x_new = x - f(x)/df(x);//remember x is x_i here and x_new is x_i+1.
		//update iteration counter
		i++;
		//compute the error. Break the loop if the error is less than your tolerance
		if(abs((x_new-x)/x_new)<tol)
		{
			cout<<setprecision(9)<<"The root is "<<x<<endl;
			return;
		}
		else
		{
			//update x to be x_new
			x = x_new;
	        }
	}
	//print the value of the root to the screen
	cout<<setprecision(9)<<"The root is "<<x<<endl;
}


int main()
{
	double x; //declare x
	//ask user for initial guess
	cout<<"What is your initial guess?";
	cin>>x;
	//call Newton-Raphson
	NewtonRaphson(x);
}

