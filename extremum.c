#include <stddef.h>
#include <limits.h>
#include <math.h>

enum {
    ERR_SUCC = 0,
    ERR_ARGS = 1,
    ERR_ITER = 2
};

int extremum(double (*f)(double), double* x, double x0, int k, double dx,
             double eps, int maxiter)
{
    double x1, x2, xr, xe, xc, f1, f2, fr, fe, fc;
    int n;
    
    /* make sure f and x are given */
    if(f == NULL || x == NULL)
        return ERR_ARGS;
    
    /* get absolute value of eps */
    eps = fabs(eps);
    
    /* get initial simplex */
    x1 = x0;
    x2 = x0 + dx;
    f1 = (*f)(x1);
    f2 = (*f)(x2);
    
    /* search for maximum if mode is positive */
    k = k > 0 ? -1 : +1;
    
    /* maximum number of iterations, or unlimited if <= 0 */
    if(maxiter <= 0)
        maxiter = INT_MAX;
    
    /* Nelder-Mead */
    for(n = 0; n < maxiter; ++n)
    {
        /* simplex converged */
        if(fabs(x1 - x2) < eps)
            break;
        
        /* order simplex */
        if(k*f1 > k*f2)
        {
            xr = x1; fr = f1;
            x1 = x2; f1 = f2;
            x2 = xr; f2 = fr;
        }
        
        /* reflection point */
        xr = 2*x1 - x2;
        
        /* function value at reflection point */
        fr = (*f)(xr);
        
        /* expand or contract */
        if(k*fr < k*f1)
        {
            /* expansion point */
            xe = 3*x1 - 2*x2;
            
            /* function value at expansion point */
            fe = (*f)(xe);
            
            /* accept xe or xr */
            if(k*fe < k*fr)
            {
                x2 = xe;
                f2 = fe;
            }
            else
            {
                x2 = xr;
                f2 = fr;
            }
        }
        else
        {
            /* outside or inside contraction */
            if(k*fr < k*f2)
            {
                /* outside contraction point */
                xc = 1.5*x1 - 0.5*x2;
                
                /* function value at contraction point */
                fc = (*f)(xc);
                
                /* accept xc or shrink */
                if(k*fc <= k*fr)
                {
                    x2 = xc;
                    f2 = fc;
                }
                else
                {
                    x2 = x1 + 0.5*(x2 - x1);
                    f2 = (*f)(x2);
                }
            }
            else
            {
                /* inside contraction point */
                xc = 0.5*x1 + 0.5*x2;
                
                /* function value at contraction point */
                fc = (*f)(xc);
                
                /* accept xc or shrink */
                if(k*fc < k*f2)
                {
                    x2 = xc;
                    f2 = fc;
                }
                else
                {
                    x2 = x1 + 0.5*(x2 - x1);
                    f2 = (*f)(x2);
                }
            }
        }
    }
    
    /* check if maxiter was hit */
    if(n == maxiter)
        return ERR_ITER;
    
    /* store extremum */
    *x = x1;
    
    /* success */
    return ERR_SUCC;
}
