/*==============================================================
    Numerical integration of f(x) on [a,b]
    method: trapezoid rule
    written by: Alex Godunov (February 2007)
----------------------------------------------------------------
input:
    f   - a single argument real function (supplied by the user)
    a,b - the two end-points of the interval of integration
    n   - number of intervals
output:
    r - result of integration
================================================================*/

    double trapezoid(double(*f)(double), double a, double b, int n)
{
    double r, dx, x;
    r = 0.0;
    dx = (b-a)/static_cast<float>(n);
    for (int i = 1; i <= n-1; i=i+1)
    {
        x = a + static_cast<float>(i)*dx;
        r = r + f(x);
    }
    r = (r + (f(a)+f(b))/2.0)*dx;
    return r;
}
