extrema(3) -- find extrema of a function in a given interval
============================================================

## SYNOPSIS

    #include "extrema.h"
    
    int extrema(double (*f)(double), double a, double b, double dx,
                double eps, int* extc, double extv[]);

## ARGUMENTS

* double (`*f`)(double):
  pointer to function
* double `a`:
  lower bound of interval
* double `b`:
  upper bound of interval
* double `dx`:
  initial simplex size
* double `eps`:
  epsilon simplex size to determine convergence
* int* `extc`:
  pointer to int containing the size of `extv`,
  contains number of extrema on return
* double `extv`[]:
  array that will be filled with extrema

## DESCRIPTION

The `extrema` function finds all points of extreme values of a function `f` in
the interval [`a`,`b`]. The number of extrema found is stored in the `extc`
argument. The extrema are written sequentially into the `extv` array so that

    a = extv[0] < extv[1] < ... < extv[extc-1] = b ,

i.e. the first and last entries in the array correspond to the interval bounds.
If there are more than `extc` extrema in the interval, the array is truncated.

## RETURN VALUES

Returns 0 on success, or a non-zero value on error.

## ALGORITHM

The `extrema` function uses the Nelder-Mead algorithm in one dimension (*Nelder
and Mead*, 1965, as described by *Lagarias et al.*, 1998) to alternate between
finding the minima and maxima of the given function. The search mode (minimum
or maximum) is initially given by the sign of `f(a + dx) - f(a)`. Whenever an
extremum is found, the search mode is reversed. In this way, the search will
progress through the interval by alternating between climbing up and down the
function. The algorithm terminates when either the upper bound `b` is reached
or then the maximum number `extc` of extrema is stored.

## EXAMPLE

    /* double f(double x) */
    
    int err;
    
    int extc = 100;
    double extv[100];
    
    double a = 0.0;
    double b = 10.0;
    
    printf("find extrema of f(x) in [%f, %f]\n", a, b);
    
    err = extrema(&f, a, b, 0.01, 1e-6, &extc, extv);
    
    if(err != 0)
    {
        printf("ERROR");
        return err;
    }
    
    printf("extrema:\n");
    for(n = 0; n < extc; ++n)
        printf("%4i  %20.16f\n", n, extv[n]);

## COPYRIGHT

This implementation of the `extrema` function is in the public domain.

## SEE ALSO

extremum(3), [GitHub]
