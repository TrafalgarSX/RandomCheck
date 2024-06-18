#include <iostream>

#include <cmath>
#include <cstdlib>
#include <cstring>


#include <cephes.h>
#include <decls.h>
#include <utilities.h>


int main(int argc, const char **argv) {

  bits_length = std::atoi(argv[1]); // arg2
  std::string streamFile = argv[2]; // arg 1

//   tp.blockFrequencyBlockLength = 128; // nist
  tp.blockFrequencyBlockLength = 100; // gm
  tp.overlappingTemplateBlockLength = 9;
  tp.approximateEntropyBlockLength = 10;
  tp.linearComplexitySequenceLength = 500;
  tp.numOfBitStreams = 1;    // arg 2

  int option = 0;

  // chooseTests
  // 目前每个都测试
  for (int i = 1; i <= NUMOFTESTS; i++) {
    testVector[i] = 1;
  }
//   fixParameters();  // 暂时都用默认的
  openOutputStreams(option);
	invokeTestSuite(option, streamFile.c_str());
	fclose(freqfp);
  return 0;
}