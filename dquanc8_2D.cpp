/*
  2D integration of f(x,y) on using quanc8.cpp twice
  AG: February 2007 (demo version)
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "quanc8.cpp"

using namespace std;

double f1(double);       // first function
double f2(double);       // second function
double x1;               // global variable (from the first integral)

int main ()
{
    double a, b;
    double result, errest, flag;
    int nofun;
    const double abserr=0.0, relerr=1.0e-8;

    cout.precision(6);
    cout.setf(ios::fixed | ios::showpoint);

    a = 0.0;
    b = 1.0;
    
    quanc8(f1, a, b, abserr, relerr, result, errest, nofun, flag);

//    cout << setw(12) << "nofun = "    << setw(10) << nofun << endl;
    cout << setw(12) << "integral = " << setw(10) << result << endl;

    system ("pause");
    return 0;
}
//===================================================================
    double f1(double x)
{
    double y;
    double a, b;
    double result, errest, flag;
    int nofun;
    const double abserr=0.0, relerr=1.0e-8;

    a = 0.0;
    b = 1.0;
    x1 = x;
 
    quanc8(f2, a, b, abserr, relerr, result, errest, nofun, flag);    
 
    y = result;
    
    return y;
}

//===================================================================
    double f2(double x2)
{
    double y;
    y = pow((x1 + x2),2);
    return y;
}

/* Test output:
         
 integral =   1.166667

*/   
