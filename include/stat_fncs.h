
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     S T A T I S T I C A L  T E S T  F U N C T I O N  P R O T O T Y P E S 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef _STAT_FNS_H_
#define _STAT_FNS_H_


 #include <stdbool.h>

bool	Frequency(int n);
bool	BlockFrequency(int M, int n);
bool	CumulativeSums(int n);
bool	Runs(int n);
bool	LongestRunOfOnes(int n);
bool	Rank(int n);
bool	DiscreteFourierTransform(int n);
bool	NonOverlappingTemplateMatchings(int m, int n);
bool	OverlappingTemplateMatchings(int m, int n);
bool	Universal(int n);
bool	ApproximateEntropy(int m, int n);
bool	RandomExcursions(int n);
bool	RandomExcursionsVariant(int n);
bool	LinearComplexity(int M, int n);
bool	Serial(int m, int n);

bool Poker(int m, int n);
bool RunsDistribution(int n);
bool BinaryDerivative(int k, int n);
bool AutoCorrelation(int d, int n);


#endif // _STAT_FNS_H_