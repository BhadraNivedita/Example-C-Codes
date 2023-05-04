/*
 Integration of a function f(x) on [a,b]
 Method: Monte Carlo integration
 AG (February 2007)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double int_mc1(double(*)(double), double&, double, double, int);
double f(double); 

int main()
{
    double a, b, mc, errest;
    int i, n;
    int ntimes;
    const double pi = 3.1415926;
      
    cout.precision(6);
    cout.setf(ios::fixed | ios::showpoint);

/* initial information */    
    a = 0.0;              // left endpoint
    b = pi;               // right endpoint
    n = 2;                // initial number of intervals
    ntimes = 16;          // number of interval doublings with nmax=2^ntimes
    
    cout << "    Points    "<<"Integral   " <<  " error"<< endl;    
    
/* step 2: integration for various number of random points */
    for (i=0; i <=ntimes; i=i+1)
    {
        mc = int_mc1(f, errest, a, b, n);

        cout << setw(10)  << n << setw(12) << mc << setw(12) << errest <<endl;

        n = n*2;
    }    

    system ("pause");
    return 0;
}

/*
 *  Function for integration
*/
    double f(double x)
{
    const double pi = 3.1415926;
    double y;
    y = sin(x);
//    y = cos(x);
//    y = x*x;
//    y = 2.0*sqrt(x)/((x+1.0)*(x+1.0));
//    y = 0.2/(pow((x-6.0),2.0) + 0.02);
//    y = x*cos(10.0*pow(x,2.0))/(pow(x,2.0) + 1.0);
//    y = sqrt(x)/(x*x + 1.0);
//    y = sin(pi*x*x)/((x-pi)*(x-pi)+1);
    return y;
}    

/*==============================================================
    Numerical integration of f(x) on [a,b]
    method: Monte-Carlo method
    written by: Alex Godunov (February 2007)
----------------------------------------------------------------
input:
    f   - a single argument real function (supplied by the user)
    a,b - the two end-points of the interval of integration
    n   - number of random points for xi
output:
    r      - result of integration
    errest - estimated error
Comments:
    be sure that following headers are included
    #include <cstdlib>
    #include <ctime>     
================================================================*/

    double int_mc1(double(*f)(double), double& errest, double a, double b, int n)
{
    double r, x, u, f2s, fs;
/* variables fs and f2s are used to estimate an error of integration */    
    
    srand(time(NULL));               /* initial seed value (use system time) */

    fs  = 0.0;
    f2s = 0.0;

    for (int i = 1; i <= n; i=i+1)
    {
        u = 1.0*rand()/(RAND_MAX+1); /* random number between 0.0 and 1.0 */
        x = a + (b-a)*u;
        fs = fs + f(x);
        f2s= f2s+ f(x)*f(x);
    }
    r = fs*(b-a)/n;
/* evaluate integration error */
    fs = fs/n;
    f2s = f2s/n;
    errest = (b-a)*sqrt((f2s - fs*fs)/n);
    return r;
}

/* Test output
   since the initial seed vary with time the results
   may also vary

    Points    Integral    error
         2    3.056593    0.060104
         4    2.568663    0.448068
         8    2.464222    0.372089
        16    2.193879    0.268019
        32    2.159471    0.186191
        64    2.105398    0.133286
       128    2.037806    0.091681
       256    2.105015    0.061158
       512    2.025399    0.044061
      1024    1.995596    0.030734
      2048    1.999651    0.021449
      4096    1.996467    0.015042
      8192    2.007557    0.010586
     16384    2.008869    0.007518
     32768    1.998001    0.005349
     65536    1.994598    0.003789
    131072    1.994946    0.002681
    
 */   
