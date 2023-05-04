/*
  A single root of an equation f(x)=0 in [a,b] interval
  Method: False Position 
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double root_fp(double(*)(double), double, double, double, int&);
double fzero(double);

int main()
{
    double a,b,root,eps;
    int flag;
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(5);

    a = 0.0;                    // left endpoint
    b = 4.0;                    // right endpoint
    eps = 1.0e-6;               // desired uncertainity of the root

    root = root_fp(fzero, a ,b ,eps, flag);

    if (flag == 0 ) cout << " no root for False position" << endl;
    else
    { cout << " iterations" << "      root"       << endl;
      cout << setw(7) << flag << setw(14) << root << endl;}
    system ("pause");
    return 0;
}
/*
 *  Function f(x) for the equation f(x)=0
*/
    double fzero(double x)
{
    double y;
//      y = x - cos(x);
//    y = exp(x)*log(x) - cos(x*x);
    y = log(x*x+2.0)*cos(x) + sin(x);
//    y = 2.0*x*x*x + 6.0*x -21;
//    y = x*x - 6.0*x +9.0;
//    y = exp(x) - sin(3.1415926*x/3.0);
    return y;
}

/* Test output
 iterations      root
     22       1.11303
*/

    double root_fp(double(*f)(double), double a, double b, double eps, int& flag)
/*
====================================================================
 Program to find a single root of an equation f(x)=0
 using the Bisectional method
 written by:    Alex Godunov
 Last revision: 31 January 2007
--------------------------------------------------------------------
 input ...
 f   - function which evaluates f(x) for any x in the interval a,b
 a   - left endpoint of initial interval
 b   - right endpoint of initial interval
 eps - desired uncertainity of the root

 output ...
 x0    - root of equation f(x)=0
 flag - indicator of success
        0 - no solutions for the Bisectional method
        i - a single root found after i iterations

 Limitations: a function f(x) must change sign between a and b
 Max number of allowed iterations is 1000 (accuracy (b-a)/2**1000)
====================================================================
*/
{
    double xl,x0,xr;
    int i, iter=100;           /* Max number of iterations */
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(5);

/* check the bisection condition */
    if(f(a)*f(b) > 0.0 )
    { flag = 0;
      return 0.0;}

/* finding a single root */
    i = 0;
    xl = a;
    xr = b;
    x0 = (xr + xl)/2.0;
    cout << "  i    a       f(a)      b       f(b)      c       f(c)  "<< endl;
    while (fabs(f(x0)) >= eps)
    {
     i = i + 1;
//     x0 = (xr + xl)/2.0;
     x0 = xr - f(xr)*(xr - xl)/(f(xr)-f(xl));
     cout << setw(3) << i << setw(9) << xl << setw(9) << f(xl)  
                          << setw(9) << xr << setw(9) << f(xr) 
                          << setw(9) << x0 << setw(9) << f(x0) << endl;
     if((f(xl) * f(x0)) <= 0.0 )
        xr = x0;
        else
        xl = x0;
     if(i >= iter) break;
     }
    flag = i;
    return x0;
}
