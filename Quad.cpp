/*==============================================================
    Solution for a quadratic equation ax^2 + bx + c = 0
    Demo program for students
    method: analytic solutions
    written by: Alex Godunov (February 2007) 
----------------------------------------------------------------
input:
    a, b, c - coefficiants of equation (supplied by the user)
output:
    x1, x2 - roots
================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

main()
{
    double a, b, c, x1, x2, xr, xi, D, D2;

    cout << "solution of the quadratic equation ax^2 + bx + c = 0" <<endl;
    cout << "enter a  b  c (as floats separated by space)" << endl;
    cin >> a >> b >> c;

    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(5);
    
    if(a == 0.0) 
      {
       if(b == 0.0)       // case c = 0 (no solutions)
         {cout << " no solution for a = 0 and b = 0" << endl;}
       else               // case bx + c = 0
         {x1 = -c/b;
          cout <<  " x = " << x1  << endl;}
      }
     else                 // general case ax^2 + bx + c = 0
     {D2 = b*b - 4.0*a*c;
     if (D2 >= 0.0) 
       {D = sqrt(D2);
        x1 = ((-1.0)*b + D)/(2.0*a);
        x2 = ((-1.0)*b - D)/(2.0*a);
        cout << " real roots"   << endl;
        cout << " x1 = " << x1  << endl;
        cout << " x2 = " << x2  << endl;
       }
     else
      {D = sqrt(-1.0*D2);
       xr = b/(2.0*a);
       xi = D/(2.0*a);
       cout << " complex roots" << endl;
       cout << " x1 = " << xr << " + "<< xi << "i" <<endl;
       cout << " x2 = " << xr << " - "<< xi << "i" <<endl;}
      }
    system("pause");
    return 0;
}



