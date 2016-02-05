#pragma once

int extrema(double (*f)(double), double a, double b, double dx, double eps,
            int* extc, double extv[]);
