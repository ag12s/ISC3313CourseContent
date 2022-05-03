#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	//declace variables a, b and c.
	double a;
	double b;
	double c;
	//set variables a and b via user input
	cout << "Please enter your first number: ";
	cin >> a;
	cout << "Please enter your second number: ";
	cin >> b;
	//set the variable c to be the product of a and b
	c = a*b;
	//output c to the screen.
	cout << "The product of your two numbers is: " << c << endl;

}
