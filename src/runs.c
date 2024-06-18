#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <externs.h>
#include <cephes.h>
#include <stdbool.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                              R U N S  T E S T 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

bool
Runs(int n)
{
	int		S, k;
	double	pi, V, erfc_arg, p_value;

	S = 0;
	for ( k=0; k<n; k++ )
		if ( epsilon[k] )
			S++;
	pi = (double)S / (double)n;

	if ( fabs(pi - 0.5) > (2.0 / sqrt(n)) ) {
		fprintf(stats[TEST_RUNS], "\t\t\t\tRUNS TEST\n");
		fprintf(stats[TEST_RUNS], "\t\t------------------------------------------\n");
		fprintf(stats[TEST_RUNS], "\t\tPI ESTIMATOR CRITERIA NOT MET! PI = %f\n", pi);
		p_value = 0.0;
	}
	else {

		V = 1;
		for ( k=1; k<n; k++ )
			if ( epsilon[k] != epsilon[k-1] )
				V++;
	
		erfc_arg = fabs(V - 2.0 * n * pi * (1-pi)) / (2.0 * pi * (1-pi) * sqrt(2*n));
		p_value = erfc(erfc_arg);

		if ( isNegative(p_value) || isGreaterThanOne(p_value) ) {
			fprintf(stats[TEST_RUNS], "WARNING:  P_VALUE IS OUT OF RANGE.\n");
            return false;
        }
	}

    return p_value < ALPHA ? false : true;
}
