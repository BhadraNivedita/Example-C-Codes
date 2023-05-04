/*
 Linear interpolation (demo program)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double interp_1(double, double[], double[], int);  //function prototype

int main ()
{
    const int isize = 5;                           // size of an arrays for interpolation
 	double xi[isize] = {1.0, 2.0, 3.0, 4.0, 5.0};  // given xi points
 	double yi[isize] = {2.0, 3.0, 1.0, 2.0, 1.0};  // given yi points
 	double x, y;

    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(5); 	

    x = 3.2;    // we are loking for a linear interpolation for this x 
    
    y = interp_1(x, xi, yi, isize);   // call for linear interpolation

    cout << "x = " << x << " y = " << y << endl;
    system ("pause");
	return 0;
}

double interp_1(double x, double xi[], double yi[], int imax)
/*
====================================================================
 Linear interpolation  
 Alex Godunov (demo for Phys420)
--------------------------------------------------------------------
 input ...
 x   - the abscissa at which the linear interpolation is to be evaluated
 xi[]- the arrays of data abscissas
 yi[]- the arrays of data ordinates
 imax- size of the arrays xi[] and yi[]

 output ...
 y    - interpolated value
====================================================================
*/
{
    double y;
    int j;
// if x is ouside the xi[] interval take a boundary value (left or right)
    if (x <= xi[0])      return y = yi[0];
    if (x >= xi[imax-1]) return y = yi[imax-1];    
// loop to find j so that x[j-1] < x < x[j]
    j = 0;
    while (j <= imax-1)
    {
     if (xi[j] >= x) break;
     j = j + 1;
     }
    y = yi[j-1] + (yi[j] - yi[j-1])*(x - xi[j-1])/(xi[j]-xi[j-1]);
    return y;
}

/* Test output

x = 3.20000 y = 1.20000

*/
