#include "SciProgLib.h"

namespace SciProgLib
{
	//==============================   Root Finding   ==============================
	double RootFinding::Bisect(double a, double b, double tol, double (*f)(double m))
	{
		// Check that there is a root in the chosen domain
		if (f(a) * f(b) >= 0)
		{
			cout << "This interval has no roots." << endl;
			// exit if no root is found
			return 0;
		}

		double error = 100.0;
		double c_old = 0;
		double c_new;
		int counter = 0;
		while (error > tol)
		{
			c_new = (a + b) / 2;

			if (f(a) * f(c_new) < 0)
				b = c_new;
			else
				a = c_new;

			error = abs((c_new - c_old) / c_new);
			c_old = c_new;
			counter++;
		}
		cout << "The number of iterations required for the \nBisection method to converge is:\t\t " << counter << endl;
		return c_new;
	}

	double RootFinding::NewtonRaphson(double x, double tol, int maxit, double(*f)(double x), double(*df)(double x))
	{
		int i = 0; //Counter for our while loop
		double error = 2 * tol; //set the error to be bigger than the tolerance
		double x_new;	//declare x_new, which is x_i+1. x is x_i

		//we want to iterate while the iteration counter is less than the iteration cap
		//and also while the function value isn't close to 0
		while (i < maxit && abs(f(x)) > tol)
		{
			//Newton-Raphson formula
			x_new = x - f(x) / df(x);//remember x is x_i here and x_new is x_i+1.
			//update iteration counter
			i++;
			//compute the error. Break the loop if the error is less than your tolerance
			if (abs(x_new - x) < tol)
				break;
			else
				x = x_new;
		}

		cout << "The number of iterations required for the \nNewton-Raphson method to converge is:\t\t " << i << endl;
		return x;
	}

	double RootFinding::Secant(double x0, double x1, double tol, int maxit, double (*f)(double x))
	{
		int i = 0; //Counter for our while loop
		double error = 2 * tol; //set the error to be bigger than the tolerance
		double x_new = 0;	//declare x_new, which is x_i+1. x is x_i
		//we want to iterate while the iteration counter is less than the iteration cap
		//and also while the function value isn't close to 0
		double h = 0; //don't declare it in the loop every time. 
		while (i < maxit && abs(f(x1)) > tol)
		{
			//Newton-Raphson formula

			h = x1 - x0;
			x_new = x1 - f(x1)/Differentiation::ForwardDifference(x1, h, f);//remember x is x_i here and x_new is x_i+1.
			//update iteration counter
			i++;
			//compute the error. Break the loop if the error is less than your tolerance
			if (abs(x_new - x1) < tol)
				break;
			else
				x0 = x1;
				x1 = x_new;
		}
		cout << "The number of iterations required for the \nsecant method to converge is:\t\t\t " << i << endl;
		return x1;
	}

	//==============================   Optimization   ==============================
	double Optimization::GoldenSectionSearch(double xl, double xu, double tol, double (*f)(double x), bool min)
	{
		double phi = 1.61803398874989;
		double x1, x2, d, xopt = 0;
		double error = 2 * tol;

		d = (phi - 1) * (xu - xl);
		x1 = xl + d;
		x2 = xu - d;

		double coef = 1;
		if (!min)
			coef = -1;

		while (error > tol)
		{
			if (coef * f(x1) < coef * f(x2))
			{
				xl = x2;
				x2 = x1;
				d = (phi - 1) * (xu - xl);
				x1 = xl + d;
				xopt = x1;
			}
			else
			{
				xu = x1;
				x1 = x2;
				d = (phi - 1) * (xu - xl);
				x2 = xu - d;
				xopt = x2;
			}
			error = (2 - phi) * abs((xu - xl) / xopt);
		}
		return xopt;
	}

	double Optimization::ParabolicInterpolation(double x1, double x2, double x3, double tol, double (*f)(double x))
	{
		double x4old = 0;
		double error = 2 * tol;
		double num = pow(x2 - x1, 2) * (f(x2) - f(x3)) - pow(x2 - x3, 2) * (f(x2) - f(x1));
		double den = (x2 - x1) * (f(x2) - f(x3)) - (x2 - x3) * (f(x2) - f(x1));
		if (den == 0)
			den = numeric_limits<double>::min();
		double x4 = x2 - 0.5 * num / den;

		while (error > tol)
		{
			x4old = x4;
			if (x2 > x4)
			{
				x3 = x2;
				x2 = x4;
			}
			else
			{
				x1 = x2;
				x2 = x4;
			}

			num = pow(x2 - x1, 2) * (f(x2) - f(x3)) - pow(x2 - x3, 2) * (f(x2) - f(x1));
			den = (x2 - x1) * (f(x2) - f(x3)) - (x2 - x3) * (f(x2) - f(x1));
			if (den == 0)
				den = numeric_limits<double>::min();
			x4 = x2 - 0.5 * num / den;
			error = abs((x4 - x4old) / x4);
		}

		return x4;
	}

	//==============================   Integration    ==============================
	double Integration::CompositeTrapezoid(double a, double b, double n, double avgdf2, double tol, double (*f)(double x))
	{
		double error = -pow(b - a, 3) / (12 * pow(n, 2)) * avgdf2;
		if (abs(error) > tol)
		{
			n *= 2;
			return CompositeTrapezoid(a, b, n, avgdf2, tol, f);
		}

		double h = (b - a) / n;
		double sum = (h / 2) * (f(a) + f(b));
		double xi = a + h;

		for (int i = 1; i < n; i++)
		{
			sum += h * f(xi);
			xi += h;
		}
		//cout << "The number of segments required to reach the tolerance was " << n << endl;
		return sum;
	}

	double Integration::CompositeSimpsons13(double a, double b, double n, double avgdf4, double tol, double (*f)(double x))
	{
		double error = -pow(b - a, 5) / (180 * pow(n, 4)) * avgdf4;
		if (abs(error) > tol)
		{
			n *= 2;
			return CompositeSimpsons13(a, b, n, avgdf4, tol, f);
		}

		double h = (b - a) / n;
		double sum = (h / 3) * (f(a) + f(b));
		double xi = a + h;

		for (int i = 1; i < n; i++)
		{
			if (i % 2 == 0)
				sum += 2 * h / 3 * f(xi);
			else
				sum += 4 * h / 3 * f(xi);

			xi += h;
		}
		//cout << "The number of segments required to reach the tolerance was " << n << endl;
		return sum;
	}

	double Integration::DataSimpsons(double x[], double fx[], int n)
	{
		double h = (x[n] - x[0]) / n;
		double sum = 0;

		if (n % 2 == 0)
		{
			// Case 1: n is even
			sum = (h / 3) * (fx[0] + fx[n]);
			for (int i = 1; i < n; i++)
			{
				if (i % 2 == 0)
					sum += 2 * h / 3 * fx[i];
				else
					sum += 4 * h / 3 * fx[i];
			}
		}
		else if (n % 3 == 0)
		{
			// Case 2: n is odd and divisible by 3
			sum = (3 * h / 8) * (fx[0] + fx[n]);
			for (int i = 1; i < n; i++)
				sum += (3 * h / 8) * 3 * fx[i];
		}
		else
		{
			// Case 3: n is odd and not divisible by 3
			sum = (h / 3) * (fx[0] + fx[n - 3]);
			for (int i = 1; i < n - 3; i++)
			{
				if (i % 2 == 0)
					sum += 2 * h / 3 * fx[i];
				else
					sum += 4 * h / 3 * fx[i];
			}

			sum += (3 * h / 8) * (fx[n - 3] + fx[n]);
			for (int i = n - 2; i < n; i++)
				sum += (3 * h / 8) * 3 * fx[i];
		}

		return sum;
	}

	double Integration::DataTrapezoid(vector<double> x, vector<double> fx, int n)
	{
		double h = 0;
		double sum = 0;

		for (int i = 1; i <= n; i++)
		{
			h = x[i] - x[i - 1];
			sum += (h / 2) * (fx[i - 1] + fx[i]);
		}

		return sum;
	}

	double Integration::GaussLegendre(int n, double (*f)(double x))
	{
		vector<double> coefs;
		vector<double> args;

		switch (n)
		{
		case 1:
			coefs = { 2 };
			args = { 0 };
			break;
		case 2:
			coefs = { 
				1,
				1 
			};
			args = { 
				-1 / sqrt(3), 
				1 / sqrt(3) 
			};
			break;
		case 3:
			coefs = { 
				5 / 9.,
				8 / 9.,
				5 / 9. 
			};
			args = { 
				-sqrt(3 / 5.), 
				0, 
				sqrt(3 / 5.) 
			};
			break;
		case 4:
			coefs = { 
				(18 - sqrt(30)) / 36, 
				(18 + sqrt(30)) / 36, 
				(18 + sqrt(30)) / 36, 
				(18 - sqrt(30)) / 36 
			};
			args = { 
				-sqrt(525 + 70 * sqrt(30)) / 35, 
				-sqrt(525 - 70 * sqrt(30)) / 35, 
				sqrt(525 - 70 * sqrt(30)) / 35, 
				sqrt(525 + 70 * sqrt(30)) / 35 
			};
			break;
		case 5:
			coefs = {
				(322 - 13 * sqrt(70)) / 900,
				(322 + 13 * sqrt(70)) / 900,
				128 / 225.,
				(322 + 13 * sqrt(70)) / 900,
				(322 - 13 * sqrt(70)) / 900 
			};
			args = {
				-sqrt(245 + 14 * sqrt(70)) / 21,
				-sqrt(245 - 14 * sqrt(70)) / 21,
				0,
				sqrt(245 - 14 * sqrt(70)) / 21,
				sqrt(245 + 14 * sqrt(70)) / 21 
			};
			break;
		case 6:
			coefs = {
				0.171324492379170,
				0.360761573048139,
				0.467913934572691,
				0.467913934572691,
				0.360761573048139,
				0.171324492379170
			};
			args = {
				-0.932469514203152,
				-0.661209386466265,
				-0.238619186083197,
				0.238619186083197,
				0.661209386466265,
				0.932469514203152
			};
		}

		double I = 0;

		for (int i = 0; i < n; i++)
			I += coefs[i] * f(args[i]);

		return I;
	}

	//==============================   Differentiation    ==============================
	double Differentiation::ForwardDifference(double x, double h, double (*f)(double x))
	{
		return (f(x + h) - f(x)) / h;
	}

	double Differentiation::BackwardDifference(double x, double h, double (*f)(double x))
	{
		return (f(x) - f(x - h)) / h;
	}

	double Differentiation::CenteredDifference(double x, double h, double (*f)(double x))
	{
		return (f(x + h) - f(x - h)) / (2 * h);
	}
}