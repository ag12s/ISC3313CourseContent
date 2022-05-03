#include "SciProgLib.h"

#include <iomanip>
#include <fstream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>


double bungee(double m)
{
	double v = 36;
	double g = 9.81;
	double t = 4;
	double dc = 0.25;

	return sqrt(g * m / dc) * tanh(sqrt(g * dc / m) * t) - v;
}

double dbungee(double m)
{
	double v = 36;
	double g = 9.81;
	double t = 4;
	double dc = 0.25;

	return 0.5 * sqrt(g / (m * dc)) * tanh(sqrt(g * dc / m) * t) - g * t / (2 * m) * (1 - pow(tanh(sqrt(g * dc / m) * t), 2));
}

double f1c(double x)
{
	return pow(x, 10) - 1;
}

double df1c(double x)
{
	return 10 * pow(x, 9);
}

double f2b(double x)
{
	return sin(x);
}

double f2c(double x)
{
	return -pow(x, 5) + 2 * pow(x, 2) + 1;
}

double f3b(double x)
{
	return 0.4 * (0.2 + 25 * (0.4 - 0.4 * x) - 200 * pow(0.4 - 0.4 * x, 2) + 675 * pow(0.4 - 0.4 * x, 3) - 900 * pow(0.4 - 0.4 * x, 4) + 400 * pow(0.4 - 0.4 * x, 5));
}

double y(double x)
{
	return sin(x);
}

double dy(double x)
{
	return cos(x);
}

double avgdy2 = -2 / M_PI;
double avgdy4 = 2 / M_PI;



int main()
{
	double tol = 0.0001;
	double root;
	double optima;
	double sum;
	double df;

	// 1.b. Secant Method Test
	cout << "\n1.b. Secant Method Test:" << endl;
	cout << string(80, '*') << endl;
	root = SciProgLib::RootFinding::Secant(40, 50, tol, 1000, bungee);
	cout << "Secant bungee: \t\t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << root << endl;
	root = SciProgLib::RootFinding::NewtonRaphson(50, tol, 1000, bungee, dbungee);
	cout << "Newton-Raphson bungee: \t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << root << endl;
	root = SciProgLib::RootFinding::Bisect(40, 250, tol, bungee);
    cout << "Bisection bungee: \t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << root << endl;

	// 1.c. Case Study - Newton-Raphson and the Bisection Method
	cout << "\n1.c. Case Study - Newton-Raphson and the Bisection Method:" << endl;
	cout << string(80, '*') << endl;
	root = SciProgLib::RootFinding::Bisect(0.5, 1.1, tol, f1c);
	cout << "Bisect f1c: \t\t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << root << endl;
	root = SciProgLib::RootFinding::NewtonRaphson(0.5, tol, 1000, f1c, df1c);
	cout << "Newton-Raphson f1c: \t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << root << endl;

	// 2.b. Golden-Section Search Test
	cout << "\n2.b. Golden-Section Search Test:" << endl;
	cout << string(80, '*') << endl;
	optima = SciProgLib::Optimization::GoldenSectionSearch(0, 2 * M_PI, tol, f2b);
	cout << "Golden Section Search f2b min: \t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << optima << endl;
	optima = SciProgLib::Optimization::GoldenSectionSearch(0, 2 * M_PI, tol, f2b, false);
	cout << "Golden Section Search f2b max: \t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << optima << endl;

	// 2.c. The optima is 0
	cout << "\n2.c. The optima is 0:" << endl;
	cout << string(80, '*') << endl;
	optima = SciProgLib::Optimization::ParabolicInterpolation(-0.7, 0.5, 1, tol, f2c);
	cout << "Parabolic Interpolation f2c: \t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << optima << endl;
	optima = SciProgLib::Optimization::GoldenSectionSearch(-0.7, 0.5, tol, f2c);
	cout << "Golden Section Search f2c: \t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << optima << endl;
	
	// 3.b. Gauss Quadrature test
	cout << "\n3.b. Gauss Quadrature Test:" << endl;
	cout << string(80, '*') << endl;
	double relError;
	cout << "n \t\t\t I \t\t\t  % Relative Error " << endl;
	cout << string(70, '-') << endl;
	for (int n = 1; n <= 6; n++)
	{
		sum = SciProgLib::Integration::GaussLegendre(n, f3b);
		relError = abs(sum - 1.640533333333341) / 1.640533333333341 * 100;
		cout << n << ": \t\t" << sum << " \t\t" << relError << "%" << endl;
	}

	// 4. Library
	cout << "\n4. Library:" << endl;
	cout << string(80, '*') << endl;
	root = SciProgLib::RootFinding::Bisect(2, 4, tol, y);
	cout << "Bisect: \t\t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << root << endl;
	root = SciProgLib::RootFinding::NewtonRaphson(2, tol, 1000, y, dy);
	cout << "Newton-Raphson: \t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << root << endl;

	sum = SciProgLib::Integration::CompositeTrapezoid(0, M_PI, 2, avgdy2, tol, y);
	cout << "\nComposite Trapezoid Rule: \t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << sum << endl;
	sum = SciProgLib::Integration::CompositeSimpsons13(0, M_PI, 2, avgdy4, tol, y);
	cout << "Composite Simpsons 1/3 Rule: \t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << sum << endl;
	
	double x1[11]{ 0, 0.314, 0.628, 0.942, 1.257, 1.571, 1.885, 2.199, 2.513, 2.827, 3.141 };
	double fx1[11]{ 0, 0.309, 0.589, 0.809, 0.951, 1, 0.951, 0.809, 0.589, 0.309, 0 };
	sum = SciProgLib::Integration::DataSimpsons(x1, fx1, 10);
	cout << "\nData Simpsons Rule: \t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << sum << endl;
	vector<double> x2{ 0, 0.314, 0.628, 0.942, 1.257, 1.571, 1.885, 2.199, 2.513, 2.827, 3.141 };
	vector<double> fx2{ 0, 0.309, 0.589, 0.809, 0.951, 1, 0.951, 0.809, 0.589, 0.309, 0 };
	sum = SciProgLib::Integration::DataTrapezoid(x2, fx2, 10);
	cout << "Data Trapezoid Rule: \t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << sum << endl;

	df = SciProgLib::Differentiation::ForwardDifference(0, 0.5, y);
	cout << "\nForward Difference: \t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << df << endl;
	df = SciProgLib::Differentiation::BackwardDifference(0, 0.5, y);
	cout << "Backward Difference: \t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << df << endl;
	df = SciProgLib::Differentiation::CenteredDifference(0, 0.5, y);
	cout << "Centered Difference: \t\t\t\t" << fixed << setprecision(numeric_limits<double>::max_digits10) << df << endl;

	return 0;
}