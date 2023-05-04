/*
 Numerical integration of f(x) on [a,b] using 3 following methodss:
 # Trapezoid approximation
 # Simpson's rule
 # 8-panel newton-cotes rule (quanc8.cpp)
 time of integration is calculated and printed
 AG - Februaru 2007
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "trapezoid.cpp"
#include "simpson.cpp"
#include "quanc8.cpp"

using namespace std;

double f(double);                              //function prototype

int main()
{
    double a, b, trap, simp;
    double nc8, errest, flag;
    int i, n, nofun;
    int ntimes;
    const double pi = 3.1415926;
    const double abserr=0.0, relerr=1.0e-10;  //see quanc8.cpp
       
    cout.precision(6);
    cout.setf(ios::fixed | ios::showpoint);

// current time in seconds (begin calculations)
    time_t seconds_i;
    seconds_i = time (NULL);

/* initial information */    
    a = 0.0;              // left endpoint
    b = pi;               // right endpoint
    n = 2;                // initial number of intervals
    ntimes = 12;          // number of interval doublings with nmax=2^(ntimes)

    cout << " Intervals  "<<"Trapez.   "<<"Simpson     "<< endl;

/* step 2: integration with trapezoid and simpson */
    for (i=1; i <=ntimes; i=i+1)
    {
        trap = trapezoid(f, a, b, n);
        simp = simpson(f, a, b, n);
        cout << setw(10)  << n << setw(10) << trap << setw(10) << simp <<endl;
        n = n*2;
    }

/* step 3: 8-panel newton-cotes rule */
    quanc8(f, a, b, abserr, relerr, nc8, errest, nofun, flag);

    cout << endl     << "    result from quanc8 " << endl;
    cout << setw(12) << "nofun = "    << setw(10) << nofun << endl;
    cout << setw(12) << "integral = " << setw(10) << nc8   << endl;
    cout << setw(12) << "est.error = "<< setw(10) << errest << endl;
    cout << setw(12) << "flag = "     << setw(10) << flag   << endl;    

// current time in seconds (end of calculations)
    time_t seconds_f;
    seconds_f = time (NULL);
    cout << endl << "total elapsed time = " 
         << seconds_f - seconds_i << " seconds" << endl << endl;
  
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
    y = sin(x);                                    // int (1)
//    y = sin(pi*x*x)/((x-pi)*(x-pi)+1.0);             // int (2)
    return y;
}

/* Test output for f(x) = sin(x) on [0.0,pi]

 Intervals  Trapez.   Simpson
         2  1.570796  2.094395
         4  1.896119  2.004560
         8  1.974232  2.000269
        16  1.993570  2.000017
        32  1.998393  2.000001
        64  1.999598  2.000000
       128  1.999900  2.000000
       256  1.999975  2.000000
       512  1.999994  2.000000
      1024  1.999998  2.000000
      2048  2.000000  2.000000
      4096  2.000000  2.000000

    result from quanc8
    nofun =         33
 integral =   2.000000
est.error =   0.000000
     flag =   0.000000

*/

/* Test output for f(x) = sin(pi*x*x)/((x-pi)*(x-pi)+1.0) on [0.0,2.0*pi]

 Intervals  Trapez.   Simpson
         2 -1.395444 -1.764472
         4  0.026751  0.500817
         8 -0.747037 -1.004966
        16 -0.297934 -0.148234
        32  0.225043  0.399368
        64  0.042146 -0.018819
       128  0.042308  0.042362
       256  0.042339  0.042349
       512  0.042346  0.042348
      1024  0.042348  0.042348
      2048  0.042348  0.042348
      4096  0.042348  0.042348

    result from quanc8
    nofun =       1153
 integral =   0.042348
est.error =   0.000000
     flag =   0.000000

*/
