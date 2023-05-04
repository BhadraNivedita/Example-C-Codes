/*
 Solver for first order Ordinary Differential Equations
 
 x'(t) = f1(x,t)   equation
 x(ti) = xi        initial condition
 
 Methods (select one by a key)
 key = 0; simple Euler
 key = 1; modified Euler (predictor-corrector)
 key = 2; 4-th order Runge-Kutta

 Alex Godunov. Last revision - March 2007
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

/* function prototypes */
double f1(double, double); 
double euler1d(double(*)(double, double), double, double, double);
double euler1m(double(*)(double, double), double, double, double);
double rk4_1st(double(*)(double, double), double, double, double);

int main()
{
    double xi, ti, xf, tf, dt, tmax;
    int key;
    const string method[3] = {"simple Euler","modified Euler","4th order Runge-Kutta"};

/* output: file and formats */
    ofstream file;
    file.open ("ode01.dat");
    file.precision(6);
    file.setf(ios::fixed | ios::showpoint);
    cout.precision(6);
    cout.setf(ios::fixed | ios::showpoint);

/* initial information */
    key = 2;              // select a method (key = 0, 1, 2)   
    ti = 0.0;             // initial value for variable
    xi = 1.0;             // initial value for function
    dt = 0.1;             // step size for integration
    tmax = 2.0 ;          // inegrate from ti till tmax

    file << setw(24) << method[key] << endl;
    file << setw(12) << "t" << setw(12) <<"x"<< endl;
    file << setw(12) << ti << setw(12) << xi << endl;

/* step 2: integration of ODE */
    while (ti <= tmax)
    {
        tf = ti + dt;
        if(key == 0) xf = euler1d(f1,ti,xi,tf);
        if(key == 1) xf = euler1m(f1,ti,xi,tf);
        if(key == 2) xf = rk4_1st(f1,ti,xi,tf);       
        file << setw(12) << tf << setw(12) << xf  << endl;
        ti = tf;
        xi = xf;
    }
    system ("pause");
    return 0;
}
/*
 *  Definition of the x'(t) = f1(t,x) in a first order ODE
*/
    double f1(double t, double x)
{
    double dx;
    dx = (-1.0)*x;
//    dx = 0.5*sin(2*t) - x*cos(t);
    return dx;
}

/*-----------------------------------------------------------------------
 Program to solve 1st order Ordinary Differential Equations
 x'(t) = f(t,x)
 method:    simple Euler method
 input ...
 f(t,x)- function supplied by a user
 ti  - initial value for an independent variable (t)
 xi  - initial value for a function x(t)
 tf  - find solution for this point t
 output ...
 xf  - solution at point tf, i.e. x(tf) 
-----------------------------------------------------------------------*/
double euler1d(double(*f)(double, double), double ti, double xi, double tf)
{
   double xf;
     xf = xi + f(ti,xi)*(tf-ti);
   return xf;
}


/*-----------------------------------------------------------------------
 Program to solve 1st order Ordinary Differential Equations
 x'(t) = f(t,x)
 method:    modified Euler method (predictor-corrector)
 input ...
 f(t,x)- function supplied by a user
 ti  - initial value for an independent variable (t)
 xi  - initial value for a function x(t)
 tf  - find solution for this point t
 output ...
 xf  - solution at point tf, i.e. x(tf)
-----------------------------------------------------------------------*/
double euler1m(double(*f)(double, double), double ti, double xi, double tf)
{
   double xf;
     xf = xi + f(ti,xi)*(tf-ti);
     xf = xi + (f(ti,xi)+f(tf,xf))*0.5*(tf-ti);
   return xf;
}

/*-----------------------------------------------------------------------
 Program to solve 1st order Ordinary Differential Equations
 x'(t) = f(t,x)
 method:  4th-order Runge-Kutta method
 input ...
 f(t,x)- function supplied by a user
 ti  - initial value for an independent variable (t)
 xi  - initial value for a function x(t)
 tf  - find solution for this point t
 output ...
 xf  - solution at point tf, i.e. x(tf)
-----------------------------------------------------------------------*/
double rk4_1st(double(*f)(double, double), double ti, double xi, double tf)
{
   double xf;
   double h,k1,k2,k3,k4;

   h  = tf-ti;

   k1 = h*f(ti,xi);
   k2 = h*f(ti+h/2.0,xi+k1/2.0);
   k3 = h*f(ti+h/2.0,xi+k2/2.0);
   k4 = h*f(ti+h,xi+k3);

   xf = xi + (k1 + 2.0*(k2+k3) + k4)/6.0; 
   return xf;         
}

/*   Test output for  x'(t) = (-1.0)*x
                      x(0)  = 1.0

            simple Euler               modified Euler        4th order Runge-Kutta
           t           x                t           x                t           x
    0.000000    1.000000         0.000000    1.000000         0.000000    1.000000
    0.100000    0.900000         0.100000    0.905000         0.100000    0.904837
    0.200000    0.810000         0.200000    0.819025         0.200000    0.818731
    0.300000    0.729000         0.300000    0.741218         0.300000    0.740818
    0.400000    0.656100         0.400000    0.670802         0.400000    0.670320
    0.500000    0.590490         0.500000    0.607076         0.500000    0.606531
    0.600000    0.531441         0.600000    0.549404         0.600000    0.548812
    0.700000    0.478297         0.700000    0.497210         0.700000    0.496586
    0.800000    0.430467         0.800000    0.449975         0.800000    0.449329
    0.900000    0.387420         0.900000    0.407228         0.900000    0.406570
    1.000000    0.348678         1.000000    0.368541         1.000000    0.367880
    1.100000    0.313811         1.100000    0.333530         1.100000    0.332871
    1.200000    0.282430         1.200000    0.301844         1.200000    0.301195
    1.300000    0.254187         1.300000    0.273169         1.300000    0.272532
    1.400000    0.228768         1.400000    0.247218         1.400000    0.246597
    1.500000    0.205891         1.500000    0.223732         1.500000    0.223130
    1.600000    0.185302         1.600000    0.202478         1.600000    0.201897
    1.700000    0.166772         1.700000    0.183242         1.700000    0.182684
    1.800000    0.150095         1.800000    0.165834         1.800000    0.165299
    1.900000    0.135085         1.900000    0.150080         1.900000    0.149569
    2.000000    0.121577         2.000000    0.135822         2.000000    0.135336
    
*/    
