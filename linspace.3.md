linspace(3) -- fill array with linearly spaced values
=====================================================

## SYNOPSIS

    #include "linspace.h"
    
    double* linspace(double a, double b, int n, double u[]);

## ARGUMENTS

* double `a`, double `b`:
  endpoints of values
* int `n`   :
  number of values
* double `u`[]:
  array to be filled with linearly spaced values

## DESCRIPTION

The `linspace` function fills an array u[0], u[1], ..., u[n - 1] with linearly
spaced values, so that

    u[0] == a
    u[n - 1] == b
    u[i] == a + i*c

for c = (b - a)/(n - 1) always holds.

## RETURN VALUES

The `linspace` function returns a pointer to the array `u` on success or NULL
on error.

## EXAMPLE

    int err;
    int i;
    
    int nbins = 100;
    double bins[100];
    
    double a = 0.0;
    double b = 1.0;
    
    linspace(a, b, nbins, bins);
    
    for(i = 0; i < nbins; ++i)
        printf("bin %d: %f\n", i, bins[i]);

## COPYRIGHT

This implementation of the `linspace` function is in the public domain.

## SEE ALSO

logspace(3), [GitHub]
