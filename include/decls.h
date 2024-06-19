
#ifndef _DECLS_H_
#define _DECLS_H_

#include <defs.h>
#include <stdio.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                   G L O B A L   D A T A  S T R U C T U R E S 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

extern BitSequence	*epsilon;				// BIT STREAM
extern TP			tp;						// TEST PARAMETER STRUCTURE
extern int		    bits_length;  // n
extern FILE		*stats[NUMOFTESTS+1];	// FILE OUTPUT STREAM
extern FILE		*results[NUMOFTESTS+1];	// FILE OUTPUT STREAM
extern FILE		*freqfp;				// FILE OUTPUT STREAM
extern FILE		*summary;				// FILE OUTPUT STREAM
extern int			testVector[NUMOFTESTS+1];
extern int			testResults[NUMOFTESTS+1];

extern char	generatorDir[NUMOFGENERATORS][20];
				
extern char	testNames[NUMOFTESTS+1][32];
#endif // _DECLS_H_