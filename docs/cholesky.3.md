cholesky(3) -- Cholesky matrix decomposition
============================================

## SYNOPSIS

    #include "cholesky.h"
    
    // Cholesky decomposition A = LL' of n-by-n positive definite matrix
    void chol(int n, const double A[], double L[]);
    
    // Cholesky decomposition A = LL' of n-by-n pos. semi-definite matrix
    void chol_eps(int n, const double A[], double eps, double L[]);

## ARGUMENTS

* int `n`:
  size of matrix
* const double `A`[]:
  positive definite or semi-definite `n`-by-`n` matrix
* double `L`[]:
  result of the `n`-by-`n` matrix decomposition `A = LL'`
* double `eps`:
  small constant to be added to the diagonal of `A`

## DESCRIPTION

Performs the Cholesky decomposition `A = LL'` for the given n-by-n matrix `A`
and stores the result in `L`. The decomposition can be performed in place, thus
`A` and `L` can point to the same array.

The Cholesky decomposition requires the matrix `A` to be positive definite.
However, the Cholesky decomposition of `A + eps I` converges to that of `A` as
`eps` goes to zero. Therefore, the decomposition for a positive semi-definite
matrix `A` can be computed by adding a small constant `eps` to the diagonal of
the matrix. This is performed by the `chol_eps` function.

## RETURN VALUES

The `chol` and `chol_eps` functions do not return a value.

## ALGORITHM

The function uses the standard algorithm that can be found, for example, on
[Wikipedia](https://en.wikipedia.org/wiki/Cholesky_decomposition) or
[Rosetta Code](https://rosettacode.org/wiki/Cholesky_decomposition).

## EXAMPLE

    #include "cholesky.h"
    
    void print_matrix(int n, const double A[])
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                printf("  %8.4f", A[i*n+j]);
            printf("\n");
        }
    }
    
    // ...
    
    // positive definite matrix
    double A[4*4] = {
         10, 1.2, 1.3, 1.4,
        1.2,  20, 2.3, 2.4,
        1.3, 2.3,  30, 3.4,
        1.4, 2.4, 3.4,  40
    };
    
    double L[4*4];
    
    // normal operation
    chol(4, A, L);
    
    printf("normal operation\n");
    print_matrix(4, L);
    printf("\n");
    
    // output:
    // 3.1623    0.0000    0.0000    0.0000
    // 0.3795    4.4560    0.0000    0.0000
    // 0.4111    0.4811    5.4405    0.0000
    // 0.4427    0.5009    0.5472    6.2653
    
    // in-place operation
    chol(4, A, A);
    
    printf("in-place operation\n");
    print_matrix(4, A);
    printf("\n");
    
    // output:
    // 3.1623    0.0000    0.0000    0.0000
    // 0.3795    4.4560    0.0000    0.0000
    // 0.4111    0.4811    5.4405    0.0000
    // 0.4427    0.5009    0.5472    6.2653
    
    // positive semi-definite matrix
    double Ax[5*5] = {
          10, 1.2,   0, 1.3, 1.4,
         1.2,  20,   0, 2.3, 2.4,
           0,   0,   0,   0,   0,
         1.3, 2.3,   0,  30, 3.4,
         1.4, 2.4,   0, 3.4,  40
    };
    
    double Lx[5*5];
    
    // semi-definite with epsilon
    chol_eps(5, Ax, DBL_MIN, Lx);
    
    printf("semi-definite with epsilon\n");
    print_matrix(5, Lx);
    printf("\n");
    
    // output:
    // 3.1623    0.0000    0.0000    0.0000    0.0000
    // 0.3795    4.4560    0.0000    0.0000    0.0000
    // 0.0000    0.0000    0.0000    0.0000    0.0000
    // 0.4111    0.4811    0.0000    5.4405    0.0000
    // 0.4427    0.5009    0.0000    0.5472    6.2653

## COPYRIGHT

This implementation of the `chol` and `chol_eps` functions is in the public
domain.

## SEE ALSO

[GitHub]
