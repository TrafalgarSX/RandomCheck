#include <iostream>
#include <array>
#include <vector>

#include <cmath>
#include <cstdlib>
#include <cstring>

#include <randomAllCheck.h>
#include "defs.h"

std::string streamFile = "/home/trafalgar/RandomCheck/test.dat";

void testOutFactory() {
  // std::array<int, NUMOFTESTS> testRandomArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  std::vector<int> testRandomArray{1, 5, 6, 9, 10, 12, 13, 14, 15};
  

  if(randomAllCheck(OutFactory, 1000000, streamFile, testRandomArray.data(), testRandomArray.size())) {
    std::cout << "test passed" << std::endl;
  }else{
    std::cout << "test failed" << std::endl;
  }
}

void testBootup() {
  std::array<int, NUMOFTESTS> testRandomArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  if(randomAllCheck(Bootup, 1000000,streamFile, testRandomArray.data(), testRandomArray.size())) {
    std::cout << "test passed" << std::endl;
  }else{
    std::cout << "test failed" << std::endl;
  }
}

void testSingleTest() {
  std::array<int, NUMOFTESTS> testRandomArray = {11};

  if(randomAllCheck(Bootup, 256,streamFile, testRandomArray.data(), testRandomArray.size())) {
    std::cout << "test passed" << std::endl;
  }else{
    std::cout << "test failed" << std::endl;
  }
}


int main(int argc, const char **argv) {

  int test = std::atoi(argv[1]);

  switch (test) {
    case 1:{
      testOutFactory();
      break;
    }
    case 2:{
      testBootup();
      break;
    }
    case 3:{
      testSingleTest();
      break;
    }
    default:
      break;
  }
  return 0;
}