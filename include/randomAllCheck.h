#ifndef _RANDOMALLCHECK_H_
#define _RANDOMALLCHECK_H_
#include <string>

enum TestType 
{
	OutFactory = 0,
	Bootup = 1,
	SingleTest = 2,
};


bool checkTestResult(TestType testtype, int* testRandomArray, int arraySize);
bool randomAllCheck(TestType testtype, int bits_length, std::string streamFile, int* testRandomArray, int arraySize);

#endif