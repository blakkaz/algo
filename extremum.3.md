extremum(3) -- find extremum of a function
==========================================

## SYNOPSIS

    #include "extremum.h"
    
    int extremum(double (*f)(double), double* x, double x0, int k,
                 double dx, double eps, int maxiter);

## ARGUMENTS

* double (`*f`)(double):
  pointer to function
* double* `x`:
  pointer to return extremum, can point to `x0`
* double `x0`:
  starting point for search
* int `k`    :
  negative for minimum or positive for maximum
* double `dx`:
  initial simplex size
* double `eps`:
  epsilon simplex size to determine convergence
* int `maxiter`:
  maximum number of iterations, or 0 for no limit

## DESCRIPTION

The `extremum` function finds either a minimum or maximum of `f` around `x0`
and returns it through `x`. The sign of `k` determines whether a minimum or
maximum is found.

The initial size `dx` of the simplex should be chosen according to the typical
length scales of `f` around `x0`. The `eps` argument determines convergence of
a solution; it should be chosen small enough to not contain any additional
extrema of the function.

## RETURN VALUES

The `extremum` function returns

* `0`:
  on success,
* `1`:
  when invalid arguments where given, and
* `2`:
  if the maximum number of iterations was reached.

The extremum is returned through the `x` pointer.

## ALGORITHM

The `extremum` function uses the one-dimensional Nelder-Mead algorithm (*Nelder
and Mead*, 1965, as described by *Lagarias et al.*, 1998) to find the minimum 
or maximum of the given function, depending on the `k` argument. The initial
simplex is given by `x1 = x0` and `x2 = x0 + dx`. The search will terminate if
the simplex size `fabs(x2 - x1)` falls below `eps`, or after a number `maxiter`
of iterations have been performed.

## EXAMPLE

    /* double f(double x) */
    
    int err;
    
    double x = 0.0;
    
    double min, max;
    
    printf("find minimum and maximum of f(x) around x = %f\n", x);
    
    err = 0;
    err |= extremum(&f, &min, x, -1, 0.01, 1e-6, 0);
    err |= extremum(&f, &max, x, +1, 0.01, 1e-6, 0);
    
    if(err != 0)
    {
        printf("ERROR");
        return err;
    }
    
    printf("minimum: %f\n", min);
    printf("maximum: %f\n", max);

## COPYRIGHT

This implementation of the `extremum` function is in the public domain.

## SEE ALSO

extrema(3), [GitHub]
