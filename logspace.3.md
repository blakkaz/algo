logspace(3) -- fill array with logarithmically spaced values
============================================================

## SYNOPSIS

    #include "logspace.h"
    
    double* logspace(double a, double b, int n, double u[]);

## ARGUMENTS

* double `a`, double `b`:
  endpoints of values
* int `n`   :
  number of values
* double `u`[]:
  array to be filled with logarithmically spaced values

## DESCRIPTION

The `logspace` function fills an array u[0], u[1], ..., u[n - 1] with
logarithmically spaced values, so that

    u[0] == pow(10., a)
    u[n - 1] == pow(10., b)
    u[i] == pow(10., a + i*c)

for c = (b - a)/(n - 1) always holds.

## RETURN VALUES

The `logspace` function returns a pointer to the array `u` on success or NULL
on error.

## EXAMPLE

    int err;
    int i;
    
    int nbins = 100;
    double bins[100];
    
    double a = 0.0;
    double b = 1.0;
    
    logspace(a, b, nbins, bins);
    
    for(i = 0; i < nbins; ++i)
        printf("bin %d: %f\n", i, bins[i]);

## COPYRIGHT

This implementation of the `logspace` function is in the public domain.

## SEE ALSO

linspace(3), [GitHub]
