#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cephes.h>
#include <externs.h>
#include <stdbool.h>

bool AutoCorrelation(int d, int n)
{
	int i = 0;
	double sum = 0.0;
	double dPValue = 0.0;
	double dSqrt2 = 1.41421356237309504880;
	
	for(i = 0;i < n - d; ++i)
	{
		sum += epsilon[i] ^ epsilon[i + d];
	}

	sum -= (n - d) / 2;
	sum *= 2;
	sum /= sqrt(n - d);
	dPValue = cephes_erfc(fabs(sum) / dSqrt2);

    return dPValue < ALPHA ? false : true;
}