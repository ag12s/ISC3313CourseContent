#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

namespace SciProgLib
{
	class RootFinding
	{
	public:
		static double Bisect(double a, double b, double tol, double (*f)(double m));
		static double NewtonRaphson(double x, double tol, int maxit, double(*f)(double x), double(*df)(double x));
		static double Secant(double x0, double x1, double tol, int maxit, double (*f)(double x));
	};

	class Optimization
	{
	public:
		static double GoldenSectionSearch(double xl, double xu, double tol, double (*f)(double x), bool min = true);
		static double ParabolicInterpolation(double x1, double x2, double x3, double tol, double (*f)(double x));
	};

	class Integration
	{
	public:
		static double CompositeTrapezoid(double a, double b, double n, double avgdf2, double tol, double (*f)(double x));
		static double CompositeSimpsons13(double a, double b, double n, double avgdf4, double tol, double (*f)(double x));
		static double DataSimpsons(double x[], double fx[], int n);
		static double DataTrapezoid(vector<double> x, vector<double> fx, int n);
		static double GaussLegendre(int n, double (*f)(double x));
	};

	class Differentiation
	{
	public:
		static double ForwardDifference(double x, double h, double (*f)(double x));
		static double BackwardDifference(double x, double h, double (*f)(double x));
		static double CenteredDifference(double x, double h, double (*f)(double x));
	};
}
