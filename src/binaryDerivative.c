#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <externs.h>
#include <utilities.h>
#include <cephes.h>
#include <stdbool.h>

bool BinaryDerivative(int k, int n)
{
	int i = 0;
	int j = 0;
	double sum = 0.0;
	double dPValue = 0.0;
	double dSqrt2 = 1.41421356237309504880;
	unsigned char* newSequence = NULL;
	
	//create new Sequence
    newSequence = (unsigned char*)calloc(n, sizeof(unsigned char));
	if(newSequence == NULL)
	{
        printf("BinaryDerivative Test: Insufficient memory for calloc!");
		return false;
	}
	
	//copy binary stream
	for(i = 0;i < n; ++i)
	{
		newSequence[i] = epsilon[i];
	}
	
	for(i = 0;i < k; ++i)
	{
		for(j = 0;j < (n - k - 1); ++j)
		{
			newSequence[j] = newSequence[j] ^ newSequence[j + 1];
		}
	}
	
	for(i = 0;i < n - k; ++i)
	{
		sum += newSequence[i] ? (1) : (-1);
	}
	
	//free tmp pbsStream
	if(newSequence != NULL)
	{
		free(newSequence);
		newSequence = NULL;
	}
	
	
	sum = fabs(sum);
	
	sum = sum / sqrt(n - k);
	
	dPValue = erfc(fabs(sum) / dSqrt2);

    return dPValue < ALPHA ? false : true;
}