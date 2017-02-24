#include <math.h>

void chol_eps(int n, const double A[], double eps, double L[])
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < i + 1; ++j)
        {
            double s = 0;
            for(int k = 0; k < j; ++k)
                s += L[i*n+k]*L[j*n+k];
            if(j < i)
                L[i*n+j] = (A[i*n+j] - s)/L[j*n+j];
            else
                L[i*n+j] = sqrt(A[i*n+i] + eps - s);
        }
        for(int j = i + 1; j < n; ++j)
            L[i*n+j] = 0;
    }
}

void chol(int n, const double A[], double L[])
{
    chol_eps(n, A, 0, L);
}
