bessel(3) -- Bessel functions of the first and second kind
==========================================

## SYNOPSIS

    #include "bessel.h"
    
    // Bessel function J_0(x)
    double j0(double x);
    
    // Bessel function J_1(x)
    double j1(double x);
    
    // Bessel function J_n(x)
    double jn(int n, double x);
    
    // Bessel function Y_0(x)
    double y0(double x);
    
    // Bessel function Y_1(x)
    double y1(double x);
    
    // Bessel function Y_n(x)
    double yn(int n, double x);

## ARGUMENTS

* double `x`:
  argument to Bessel function
* int `n`:
  order of Bessel function

## DESCRIPTION

The functions `j0`, `j1` and `jn` are the Bessel functions of the first kind of
order zero, one, and n, respectively. The functions `y0`, `y1` and `yn` are the
Bessel functions of the second kind of order zero, one and n, respectively.

## RETURN VALUES

The functions return the value of the Bessel function for the given argument
and order.

## ALGORITHM

The algorithms used to compute the various Bessel functions are described in
the `bessel.c` source file.

## COPYRIGHT

This implementation is based on FreeBSD libm code by Sun Microsystems.

Original copyright notice:

    Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    
    Developed at SunSoft, a Sun Microsystems, Inc. business.
    Permission to use, copy, modify, and distribute this
    software is freely granted, provided that this notice 
    is preserved.

## SEE ALSO

[GitHub]
