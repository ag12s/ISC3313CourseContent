#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

double fm(double cd) 
{
	//Define all your variables
	double v = 46.0;
	double g = 9.81;
	double m = 95.0;
	double t = 9;
	//return the function value f(m)
	return sqrt(g*m/cd)*tanh(sqrt(g*cd/m)*t)-v;
}

void Bisect(double a, double b)
{
	//Check that there is a root in the chosen domain. 
	if (fm(a)*fm(b) >= 0)
	{
		cout << "This interval has no roots."<<endl;
		//exit if no root is found
		return;
	}
	
	int i = 0;
	double error = 100.0;
	double c_old = 0;
	double c_new;
	double tol = 0.01;
	while (error > tol)
	{
		c_new = (a+b)/2;
		if (fm(a)*fm(c_new) < 0)
		{
			b = c_new;
		}
		else 
		{
			a = c_new;
		}
		error = abs((c_new - c_old)/c_new);
		c_old = c_new;
		i++;
	}
	cout <<"The root is " << setprecision(9) << c_new <<" after "<<i<<" iterations "<<endl;

}


int main()
{
	//cout<<fm(142.7377);
	Bisect(0.2, 0.5);

}
