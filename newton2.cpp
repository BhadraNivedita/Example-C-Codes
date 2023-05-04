//
// Finding roots for a system of two nonlinear equations
// f(x,y) = 0
// g(x,y) = 0
// Method: call Newton method (starting search from x1,y1)
//
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
 *  Functions f(x,y), g(x,y) and their derivatives at (x,y)
*/
    void fg(double x, double y, double& f, double& g, 
    double& fx, double& fy, double& gx, double& gy) 
{
    f = y*y*(1.0-x)-x*x*x;
	g = x*x + y*y -1.0;
	fx = (-1.0)*(y*y + 3.0*x*x);
	fy = 2.0*y*(1.0-x);
	gx = 2.0*x;
	gy = 2.0*y;
}

    void newton2(double& x1, double& y1, double eps, int& i)
/*
====================================================================
 Program to find solutions for nonlinear equations
 f(x,y) = 0
 g(x,y) = 0
 using Newton's method 
 written by:    Alex Godunov
 last revision: 29 January 2008
--------------------------------------------------------------------
 input ...
 f(x,y), g(x,y) and their derivatives
 x1, y1, - initial points
 eps    - desired uncertainity of the root

 output ...
 x1, y1   - roots

 Max number of allowed iterations is 99
====================================================================
*/
{
	double     f1, g1, fx, fy, gx, gy;
	double     del, x2, y2, dx, dy;
	int iter = 99;
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(5);

    i = 0;
    do {
        i = i + 1;
        fg(x1, y1, f1, g1, fx, fy, gx, gy);
		del = fx*gy - fy*gx;
		dx=(fy*g1-f1*gy)/del;
		dy=(f1*gx-fx*g1)/del;
		x2=x1+dx;
		y2=y1+dy;
		cout <<setw(3)<< i <<setw(10)<< x1 <<setw(10)<< y1 <<setw(10)<< f1 
                           <<setw(10)<< g1 <<setw(10)<< dx <<setw(10)<< dy
                           <<endl;
		x1=x2;
		y1=y2;
        if(i >= iter) break;		
        } while (fabs(dx) >= eps && fabs(dy) >=eps);    
        i = i+1;
}


int main()
{
	double     x1, y1, eps;
	double     f1, g1, fx, fy, gx, gy;
	int        i;

    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(5);
    
	x1 =  2.0;
	y1 =  4.0;
	eps = 1.0e-6;
	
    cout << "Newtons method for two coupled nonlinear equations" <<endl;	
    cout << "  i     x         y         f         g         dx        dy " <<endl;
    
    newton2(x1, y1, eps, i);
    fg(x1, y1, f1, g1, fx, fy, gx, gy);
    cout << endl;  
    cout << setw(3) << i << setw(10)<< x1 << setw(10) << y1 
                         << setw(10)<< f1 << setw(10) << g1 <<endl; 
    system ("pause");      
    return 0;
}


/* Test output
Newtons method for two coupled nonlinear equations
  i     x         y         f         g         dx        dy
  1   2.00000   4.00000 -24.00000  19.00000  -0.20833  -2.27083
  2   1.79167   1.72917  -8.11847   5.20009  -0.40903  -1.07982
  3   1.38263   0.64934  -2.80449   1.33332  -0.44999  -0.06852
  4   0.93265   0.58083  -0.78852   0.20719  -0.26118   0.24103
  5   0.67146   0.82186  -0.08083   0.12631  -0.04954  -0.03637
  6   0.62192   0.78549  -0.00728   0.00378  -0.00388   0.00066
  7   0.61805   0.78615  -0.00002   0.00002  -0.00001   0.00000

  8   0.61803   0.78615  -0.00000   0.00000
*/

