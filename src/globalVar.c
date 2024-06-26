
#include <defs.h>
#include <stdio.h>

BitSequence	*epsilon;				// BIT STREAM
TP			tp;						// TEST PARAMETER STRUCTURE
int		    bits_length;  // n
FILE		*stats[NUMOFTESTS+1];	// FILE OUTPUT STREAM
FILE		*results[NUMOFTESTS+1];	// FILE OUTPUT STREAM
FILE		*freqfp;				// FILE OUTPUT STREAM
FILE		*summary;				// FILE OUTPUT STREAM
int			testVector[NUMOFTESTS+1];
int			testResults[NUMOFTESTS+1] = {0};

char	generatorDir[NUMOFGENERATORS][20] = { "AlgorithmTesting", "LCG", "QCG1", "QCG2","CCG", "XOR",
			"MODEXP", "BBS", "MS", "G-SHA1" };
				
char	testNames[NUMOFTESTS+1][32] = { " ", "Frequency", "BlockFrequency", "CumulativeSums", "Runs", "LongestRun", "Rank",
			"FFT", "OverlappingTemplate", "Universal", "ApproximateEntropy", "LinearComplexity",
            "POKER", "AUTOCORELATION", "BINARYDERIVATIVE", "RUNSDISTRIBUTION" };