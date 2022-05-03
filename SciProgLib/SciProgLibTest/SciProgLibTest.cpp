#include "pch.h"
#include "CppUnitTest.h"
#include "SciProgLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

double tol = 0.0001;

namespace SciProgLibTest
{
	TEST_CLASS(Q1b)
	{
	public:
		TEST_METHOD(Secant)
		{
			double root = SciProgLib::RootFinding::Secant(40, 50, tol, 1000, bungee);
			Assert::IsTrue(root == 142.73286307109916038 || root == 142.73716496818195765 || root == 142.73282639363591784); //Backward, centered, forward diff approx
		}

		TEST_METHOD(NewtonRaphson)
		{
			double root = SciProgLib::RootFinding::NewtonRaphson(50, tol, 1000, bungee, dbungee);
			Assert::AreEqual(142.73762725391955541, root, tol);
		}
	};

	TEST_CLASS(Q1c)
	{
	public:
		TEST_METHOD(Bisect)
		{
			double root = SciProgLib::RootFinding::Bisect(0.5, 1.1, tol, f1c);
			Assert::AreEqual(1.00002441406250009, root, tol);
		}

		TEST_METHOD(NewtonRaphson)
		{
			double root = SciProgLib::RootFinding::NewtonRaphson(0.5, tol, 1000, f1c, df1c);
			Assert::AreEqual(1.00002393429083547, root, tol);
		}
	};

	TEST_CLASS(Q2b)
	{
	public:
		TEST_METHOD(GoldenSectionSearchMin)
		{
			double optima = SciProgLib::Optimization::GoldenSectionSearch(0, 2 * M_PI, tol, f2b, true);
			Assert::AreEqual(4.71198876823169588, optima, tol);
		}

		TEST_METHOD(GoldenSectionSearchMax)
		{
			double optima = SciProgLib::Optimization::GoldenSectionSearch(0, 2 * M_PI, tol, f2b, false);
			Assert::AreEqual(1.57084177720077456, optima, tol);
		}
	};

	TEST_CLASS(Q2c)
	{
		TEST_METHOD(ParabolicInterp)
		{
			double optima = SciProgLib::Optimization::ParabolicInterpolation(-0.7, 0.5, 1, tol, f2c);
			Assert::AreEqual(0.00000000088569751, optima, tol);
		}

		TEST_METHOD(GoldenSectionSearch)
		{
			double optima = SciProgLib::Optimization::GoldenSectionSearch(-0.7, 0.5, tol, f2c, true);
			Assert::AreEqual(-0.00000000745068719, optima, tol);
			//Assert::IsTrue(optima == 0.00000000745005601 || optima == -0.00000000745068719);
		}
	};

	TEST_CLASS(Q3b)
	{
		TEST_METHOD(GaussLegendre1)
		{
			double sum = SciProgLib::Integration::GaussLegendre(1, f3b);
			Assert::AreEqual(1.96480000000000032, sum, tol);
		}

		TEST_METHOD(GaussLegendre2)
		{
			double sum = SciProgLib::Integration::GaussLegendre(2, f3b);
			Assert::AreEqual(1.82257777777777719, sum, tol);
		}

		TEST_METHOD(GaussLegendre3)
		{
			double sum = SciProgLib::Integration::GaussLegendre(3, f3b);
			Assert::AreEqual(1.64053333333332896, sum, tol);
		}

		TEST_METHOD(GaussLegendre4)
		{
			double sum = SciProgLib::Integration::GaussLegendre(4, f3b);
			Assert::AreEqual(1.64053333333333073, sum, tol);
		}

		TEST_METHOD(GaussLegendre5)
		{
			double sum = SciProgLib::Integration::GaussLegendre(5, f3b);
			Assert::AreEqual(1.64053333333332985, sum, tol);
		}

		TEST_METHOD(GaussLegendre6)
		{
			double sum = SciProgLib::Integration::GaussLegendre(6, f3b);
			Assert::AreEqual(1.64053333333333007, sum, tol);
		}
	};

	TEST_CLASS(Library)
	{
		TEST_METHOD(CompositeTrapRule)
		{
			double sum = SciProgLib::Integration::CompositeTrapezoid(0, M_PI, 2, avgdy2, tol, y);
			Assert::AreEqual(1.99997490023505842, sum, tol);
		}

		TEST_METHOD(CompositeSimps13)
		{
			double sum = SciProgLib::Integration::CompositeSimpsons13(0, M_PI, 2, avgdy4, tol, y);
			Assert::AreEqual(2.00001659104793506, sum, tol);
		}

		TEST_METHOD(DataSimpsonsRule)
		{
			double x1[11]{ 0, 0.314, 0.628, 0.942, 1.257, 1.571, 1.885, 2.199, 2.513, 2.827, 3.141 };
			double fx1[11]{ 0, 0.309, 0.589, 0.809, 0.951, 1, 0.951, 0.809, 0.589, 0.309, 0 };
			double sum = SciProgLib::Integration::DataSimpsons(x1, fx1, 10);
			Assert::AreEqual(2.00018880000000010, sum, tol);
		}

		TEST_METHOD(DataTrapezoidalRule)
		{
			vector<double> x2{ 0, 0.314, 0.628, 0.942, 1.257, 1.571, 1.885, 2.199, 2.513, 2.827, 3.141 };
			vector<double> fx2{ 0, 0.309, 0.589, 0.809, 0.951, 1, 0.951, 0.809, 0.589, 0.309, 0 };
			double sum = SciProgLib::Integration::DataTrapezoid(x2, fx2, 10);
			Assert::AreEqual(1.98410400000000009, sum, tol);
		}

		TEST_METHOD(ForwardDifference)
		{
			double df = SciProgLib::Differentiation::ForwardDifference(0, 0.5, y);
			Assert::AreEqual(0.95885107720840601, df, tol);
		}

		TEST_METHOD(BackwardDifference)
		{
			double df = SciProgLib::Differentiation::BackwardDifference(0, 0.5, y);
			Assert::AreEqual(0.95885107720840601, df, tol);
		}

		TEST_METHOD(CenteredDifference)
		{
			double df = SciProgLib::Differentiation::CenteredDifference(0, 0.5, y);
			Assert::AreEqual(0.95885107720840601, df, tol);
		}
	};
}