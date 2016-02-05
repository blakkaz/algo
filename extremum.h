#pragma once

int extremum(double (*f)(double), double* x, double x0, int k, double dx,
             double eps, int maxiter);
