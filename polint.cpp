
/*==========================================================================
 Lagrange interpolation: straightforward application (demo version)
 written by: Alex Godunov (February 2007)
----------------------------------------------------------------------------
 input ...
 x     - the abscissa at which the linear interpolation is to be evaluated
 xi[]  - the arrays of data abscissas
 yi[]  - the arrays of data ordinates
 n - size of the arrays xi[] and yi[]
 nint - number of points for interpolation (order of interpolation = nint-1)

 output ...
 y    - interpolated value

 comments:
 if (nint > n) nint = n;
 there is a more efficient version of Lagrange interpolation,
 i.e. Neville’s algorithm that works faster.
============================================================================*/

  double polint(double x, double xi[], double yi[], int n, int nint)
{
    double lambda[n];
    double y;
    int i, j, k, js, jl;
// check order of interpolation
    if (nint > n) nint = n;
// if x is ouside the xi[0]-xi[n-1] interval take a boundary value
    if (x <= xi[0])   return y = yi[0];
    if (x >= xi[n-1]) return y = yi[n-1];

//  a binary (bisectional) search to find i so that x[i-1] < x < x[i]
    i = 0;
    j = n;
    while (j > i+1)
    {
       k = (i+j)/2;
       if (x < xi[k-1]) j = k;
       else i = k;
    }

// shift i that will correspond to n-th order of interpolation
     i = i - nint/2;

// check boundaries: if i is ouside of the range [0, ... n-1] -> shift i
     if (i < 0) i=0;
     if (i + nint - 1 > n -1 ) i = n - nint;

// interpolation
     y = 0.0;
     for (js = i; js <= i+nint-1; js = js+1)
     {
         lambda[js] = 1.0;
         for (jl = i; jl <= i+ nint-1; jl = jl + 1)
         {
             if(jl != js) lambda[js] = lambda[js]*(x-xi[jl])/(xi[js]-xi[jl]);
         }
         y = y + yi[js]*lambda[js];
     }
    return y;
}


