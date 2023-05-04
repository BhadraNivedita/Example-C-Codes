//
// A single root of an equation f(x)=0
// Drive program: Secant method (starting search from x1)
//
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double root_sm(double(*)(double), double, double, double, int&);
double fzero(double);

int main()
{
    double x1, x2, root, eps;
    int flag;

    x1 = 1.0;                       // starting poin
    x2 = x1 - 0.01;                 // second point
    eps = 1.0e-6;

    root = root_sm(fzero, x1, x2, eps, flag);

    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(5);

    if (flag == 0 ) cout << " no root found, try to change x1" << endl;
    else
    { cout << " iterations" << "      root"       << endl;
      cout << setw(7) << flag << setw(14) << root << endl;}
    system ("pause");      
    return 0;
}
/*
 *  Function fzero(x)
*/
    double fzero(double x)
{
    double y;
//    y = exp(x)*log(x)-cos(x);
    y = exp(x)*log(x) - cos(x*x);
//    y = log(x*x+2.0)*cos(x) + sin(x);
//    y = 2.0*x*x*x + 6.0*x -21;
//    y = x*x - 6.0*x +9.0;
    return y;
}

    double root_sm(double(*f)(double), double x1, double x2, double eps, int& flag)
/*
====================================================================
 Program to find a single root of an equation f(x)=0
 using the method of secants
 written by: Alex Godunov
--------------------------------------------------------------------
 input ...
 f  - function which evaluates f(x) for any x in the interval a,b
 x1 - initial point
 x2 - second initial point
 eps    - desired uncertainity of the root

 output ...
 x3    - root of equation f(x)=0
 iflag - indicator of success
         0 - no solutions found for the secant method
         i - a single root found after i iterations

 Max number of allowed iterations is 1000
 Last revision: 31 January 2007
====================================================================
*/
{
    double x3;
    int i, iter=1000;
    i = 0;
    while (fabs(x2 - x1) >= eps)
    {
     i = i + 1;
     x3 = x2 - (f(x2)*(x2-x1))/(f(x2)-f(x1));
     x1 = x2;
     x2 = x3;
     if(i >= iter) break;
     }

    flag = i;
    if (i == iter) flag = 0;
    return x3;
}
