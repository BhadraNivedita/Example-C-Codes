//
// A single root of an equation f(x)=0
// Method: call Newton method (starting search from x1)
//
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double root_nm(void(*)(double, double&, double&), double, double, int&);
void   fzero(double, double&, double&);

int main()
{
    double x, root, eps;
    int flag;
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(5);
    
    x = 1.0;                       // starting poin
    eps = 1.0e-6;

    root = root_nm(fzero, x, eps, flag);

    if (flag == 0 ) cout << " no root found, try to change x1" << endl;
    else
    { cout << " iterations" << "      root"       << endl;
      cout << setw(7) << flag << setw(14) << root << endl;}
    system ("pause");      
    return 0;
}
/*
 *  Function fzero(x)
 *  provides f(x) and f'(x) at point x.
*/
    void fzero(double x, double& fx, double& fpx)
{
//    fx = exp(x)*log(x) - cos(x*x);
//    fpx= exp(x)*log(x) + exp(x)/x + 2.0*x*sin(x*x);
    fx = x - cos(x);
    fpx= 1.0 + sin(x);
}

/* Test output
 iterations      root
      4       1.11302
*/

    double root_nm(void(*f)(double, double&, double&), 
                   double x, double eps, int& flag)
/*
====================================================================
 Program to find a single root of an equation f(x)=0
 using Newton's method 
 written by:    Alex Godunov
 last revision: 21 January 2008
--------------------------------------------------------------------
 input ...
 f - function which evaluates f(x) for any x in the interval a,b
 x - initial point
 eps    - desired uncertainity of the root

 output ...
 xc    - root of equation f(x)=0
 iflag - indicator of success
         0 - no solutions found for the secant method
         i - a single root found after i iterations

 Max number of allowed iterations is 1000
====================================================================
*/
{
    double fx, fpx, xc;
    int i, iter=1000;
    i = 0;
    do {
        i = i + 1;
        f(x,fx,fpx);
        xc = x - fx/fpx;
        x = xc;
        if(i >= iter) break;
        } while (fabs(fx) >= eps);    
    
    flag = i;
    if (i == iter) flag = 0;
    return xc;
}
