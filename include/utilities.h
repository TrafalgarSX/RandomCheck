/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
              U T I L I T Y  F U N C T I O N  P R O T O T Y P E S 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

int		displayGeneratorOptions();
int		generatorOptions(char** streamFile);
void	chooseTests();
void	fixParameters();
bool	fileBasedBitStreams(const char *streamFile, int mode);
void	readBinaryDigitsInASCIIFormat(FILE *fp, const char *streamFile);
bool	readHexDigitsInBinaryFormat(FILE *fp);
int		convertToBits(uint8_t *x, int xBitLength, int bitsNeeded, int *num_0s, int *num_1s, int *bitsRead);
void	openOutputStreams(int option);
void	invokeTestSuite(int option, const char *streamFile, int mode);
void	nist_test_suite();

bool    startTestSuite(const char *streamFile, int mode);

#ifdef __cplusplus
}
#endif

#endif // _UTILITIES_H_