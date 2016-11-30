#include <math.h>
#include <string.h>

void cholesky(int n, const double A[], double L[])
{
    // zero the decomposition matrix
    memset(L, 0, n*n*sizeof(double));
    
    // Cholesky decomposition
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < i + 1; ++j)
    {
        double s = 0;
        for(int k = 0; k < j; ++k)
            s += L[i*n+k]*L[j*n+k];
        L[i*n+j] = j < i ? (A[i*n+j] - s)/L[j*n+j] : sqrt(A[i*n+i] - s);
    }
}
