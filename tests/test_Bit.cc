#include <iostream>
#include "gtest/gtest.h"
#include "Bit.h"
#include <fstream>
#include <climits>  

using namespace std;
using namespace meng;
TEST(Bit, Bit_bitmap1) {
  std::string str("1111111111111111111111111111111111111111111111111111111111111111");
  BitMap bits = meng::Building_Character_Bitmaps(str, '1');
  ASSERT_EQ(bits[0], -1);
  ASSERT_EQ(bits.length(), 1);
}

TEST(Bit, Bit_bitmap2) {
  std::string str("11111111111111111111111111111111111111111111111111111111111111101");
  BitMap bits = meng::Building_Character_Bitmaps(str, '1');
  ASSERT_EQ(bits[0], -2);
  ASSERT_EQ(bits.length(), 2);
}

TEST(Bit, Bit_bitmap3) {
  string str;
  ifstream fin("../tests/test.json");
  fin>>str;
  BitMap bits = meng::Building_Character_Bitmaps(str, '}');
  ASSERT_EQ(1, (bits[0] >> (64 - 17)));
  bits = meng::Building_Character_Bitmaps(str, '{');
  ASSERT_EQ((1<<16), (bits[0] >> (64 - 17)));
  bits = meng::Building_Character_Bitmaps(str, '\\');
  ASSERT_EQ(((1<<3) + (1<<6)), (bits[0] >> (64 - 17)));
}

TEST(Bit, Bit_R) {
  ASSERT_EQ(R(-1), -2);
  ASSERT_EQ(R(-2), -4);
  ASSERT_EQ(R(1), 0);
  ASSERT_EQ(R(2), 0);
  ASSERT_EQ(R(3), 2);
  ASSERT_EQ(R(5), 4);
}

TEST(Bit, Bit_E) {
  ASSERT_EQ(E(-1), 1);
  ASSERT_EQ(E(-2), 2);
  ASSERT_EQ(E(3), 1);
  ASSERT_EQ(E(4), 4);
  ASSERT_EQ(E(6), 2);
}

TEST(Bit, Bit_S) {
  ASSERT_EQ(S(-1), 1);
  ASSERT_EQ(S(-2), 3);
  ASSERT_EQ(S(2), 3);
  ASSERT_EQ(S(3), 1);
  ASSERT_EQ(S(6), 3);
}