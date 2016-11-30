cholesky(3) -- Cholesky matrix decomposition
============================================

## SYNOPSIS

    #include "cholesky.h"
    
    // Cholesky decomposition of n-by-n matrix A = LL'
    void cholesky(int n, const double A[], double L[]);

## ARGUMENTS

* int `n`:
  size of matrix
* double `A`[]:
  the `n`-by-`n` matrix to be decomposed
* double `L`[]:
  result of the `n`-by-`n` matrix decomposition `A = LL'`

## DESCRIPTION

Performs the Cholesky decomposition `A = LL'` for the given n-by-n matrix `A`
and stores the result in `L`.

## RETURN VALUES

The `cholesky` function does not return a value.

## ALGORITHM

The function uses the standard algorithm that can be found, for example, on
[Wikipedia](https://en.wikipedia.org/wiki/Cholesky_decomposition) or
[Rosetta Code](https://rosettacode.org/wiki/Cholesky_decomposition).

## EXAMPLE

    #include "cholesky.h"
    
    // ...
    
    int n = 4;
    
    double A[4*4] = {
         10, 1.2, 1.3, 1.4,
        1.2,  20, 2.3, 2.4,
        1.3, 2.3,  30, 3.4,
        1.4, 2.4, 3.4,  40
    };
    
    double L[4*4] = {0};
    
    cholesky(n, A, L);
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            printf("  %8.4f", L[i*4+j]);
        printf("\n");
    }
    
    // output
    // ------
    // 3.1623    0.0000    0.0000    0.0000
    // 0.3795    4.4560    0.0000    0.0000
    // 0.4111    0.4811    5.4405    0.0000
    // 0.4427    0.5009    0.5472    6.2653

## COPYRIGHT

This implementation of the `cholesky` function is in the public domain.

## SEE ALSO

[GitHub]
