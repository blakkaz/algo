#include <stddef.h>
#include <math.h>

int extrema(double (*f)(double), double a, double b, double dx, double eps,
            int* extc, double extv[])
{
    double x1, x2, xr, xe, xc, f1, f2, fr, fe, fc;
    int n, s;
    
    /* make sure there is room for extrema */
    if(*extc == 0)
        return 1;
    
    /* make sure integrand is given */
    if(f == NULL)
    {
        *extc = 0;
        return 1;
    }
    
    /* make sure bounds are sensible */
    if(b < a)
    {
        *extc = 0;
        return 1;
    }
    
    /* number of extrema found */
    n = 0;
    
    /* start at lower bound */
    extv[n++] = a;
    
    /* get initial simplex */
    x1 = a;
    x2 = a + dx;
    f1 = (*f)(x1);
    f2 = (*f)(x2);
    
    /* if function goes up we must start by searching for a maximum */
    s = f2 > f1 ? -1 : +1;
    
    /* traverse interval with Nelder-Mead */
    while(n < *extc)
    {
        /* check if simplex moved out of bounds */
        if(x1 > b)
        {
            /* add upper bound */
            extv[n++] = b;
            
            /* done */
            break;
        }
        
        /* check if simplex converged */
        if(fabs(x1 - x2) < eps)
        {
            /* add extremum */
            extv[n++] = x1;
            
            /* reset simplex */
            x1 = fmax(x1, x2) + dx;
            x2 = x1 + dx;
            
            /* change direction */
            s *= -1;
        }
        
        /* order exts */
        if(s*f1 > s*f2)
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
        if(s*fr < s*f1)
        {
            /* expansion point */
            xe = 3*x1 - 2*x2;
            
            /* function value at expansion point */
            fe = (*f)(xe);
            
            /* accept xe or xr */
            if(s*fe < s*fr)
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
            if(s*fr < s*f2)
            {
                /* outside contraction point */
                xc = 1.5*x1 - 0.5*x2;
                
                /* function value at contraction point */
                fc = (*f)(xc);
                
                /* accept xc or shrink */
                if(s*fc <= s*fr)
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
                if(s*fc < s*f2)
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
    
    /* store number of extrema found */
    *extc = n;
    
    /* success */
    return 0;
}
