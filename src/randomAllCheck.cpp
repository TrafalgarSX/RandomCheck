#include "defs.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#include <decls.h>
#include <utilities.h>
#include <randomAllCheck.h>

std::array<int, 3> numsOfBitStreamsByType = {50, 20, 1};
std::array<int, 3> testSucessCount = {48, 49, 1};

bool checkTestResult(TestType testtype, int* testRandomArray, int arraySize) {
  bool result = true;


  for(int i = 0; i < arraySize; ++i) {
	if (testResults[testRandomArray[i]] < testSucessCount[testtype]) {
	  result = false;
	  break;
	}
  }
  return result;
}

bool randomAllCheck(TestType testtype, int bits_length, std::string streamFile, int* testRandomArray, int arraySize) {
  tp.n = bits_length;
  tp.blockFrequencyBlockLength = 100; // gm
  tp.overlappingTemplateBlockLength = 9;
  tp.approximateEntropyBlockLength = 10;
  tp.linearComplexitySequenceLength = 500;
  tp.numOfBitStreams = numsOfBitStreamsByType[testtype];    // arg 2

  // chooseTests
  std::fill_n(testVector, NUMOFTESTS+1, 0);

  if( arraySize == NUMOFTESTS) {
	testVector[0] = 1;
  }else
  {
	for (int i = 0; i < arraySize; i++) {
	  testVector[testRandomArray[i]] = 1;
	}
  }

  startTestSuite(streamFile.c_str(), 1);

  return checkTestResult(testtype, testRandomArray, arraySize);
}