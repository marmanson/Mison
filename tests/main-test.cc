#include <iostream>
#include "gtest/gtest.h"
#include "Bit.h"
#include <cassert>
using namespace std;
int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  assert(ret==0);
  return 0;
}