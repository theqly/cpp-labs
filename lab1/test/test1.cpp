#include "bitarray.h"
#include "../src/bitarray.cpp"
#include <gtest/gtest.h>

TEST(StandartConstr, Constrs){
  BitArray arr = BitArray();
  EXPECT_EQ(arr.size(), 0);
}

TEST(CapacityConstr, Constrs){
  BitArray arr = BitArray(5);
  EXPECT_EQ(arr[3], 0);
}

TEST(CopyConstr, Constrs){
  BitArray arr1 = BitArray(15);
  arr1.reset(10);
  EXPECT_EQ(arr1[10], 0);
  arr1.reset();
  BitArray arr2 = BitArray(arr1);
  EXPECT_EQ(arr2[12], 0);
}

TEST(Swap, Swap){
  BitArray arr1 = BitArray(14);
  BitArray arr2= BitArray(8);
  arr1.swap(arr2);
  EXPECT_EQ(arr1.size(), 8);
  EXPECT_EQ(arr2.size(), 14);
}

TEST(CopyOperator, Operators){
  BitArray arr1 = BitArray(15);
  arr1.set();
  BitArray arr2 = BitArray(13);
  arr2.reset();
  EXPECT_EQ(arr2.size(), 13);
  EXPECT_EQ(arr2[8], 0);
  arr2 = arr1;
  EXPECT_EQ(arr2.size(), 15);
  EXPECT_EQ(arr2[8], 1);
}

TEST(Resize, Resize){
  BitArray arr1 = BitArray(14);
  arr1.set();
  arr1.resize(17);
  EXPECT_EQ(arr1.size(), 17);
  EXPECT_EQ(arr1[13], 1);
}

TEST(Clear, Clear){
  BitArray arr1 = BitArray(14);
  arr1.set();
  EXPECT_EQ(arr1.empty(), 0);
  arr1.clear();
  EXPECT_EQ(arr1.empty(), 1);
}

TEST(Pushing, Pushing){
  BitArray arr1 = BitArray(15);
  arr1.set();
  arr1.push_back(false);
  EXPECT_EQ(arr1[15], 0);
  arr1.push_back(true);
  EXPECT_EQ(arr1[16], 1);
}

TEST(BitAnd, BitOperators){
  BitArray arr1 = BitArray(8);
  BitArray arr2 = BitArray(8);
  arr1.reset();
  arr2.set();
  arr2 &= arr1;
  for(size_t i = 0; i < 8; ++i){
    EXPECT_EQ(arr2[i], 0);
  }
  arr1.set(3, true);
  arr2.set();
  arr2 &= arr1;
  EXPECT_EQ(arr2[3], 1); //WHY FALSE
  EXPECT_EQ(arr2[2], 0);
}

TEST(Any, Any){
  BitArray arr1 = BitArray(8);
  arr1.reset();
  EXPECT_EQ(arr1.any(), 0);
  arr1.set(7, true);
  EXPECT_EQ(arr1.any(), 1);
}

TEST(None, None){
  BitArray arr1 = BitArray(8);
  arr1.reset();
  EXPECT_EQ(arr1.none(), 1);
  arr1.set(7, true);
  EXPECT_EQ(arr1.none(), 0);
}

TEST(Inversion, BitOperators){
  BitArray arr1 = BitArray(8);
  arr1.set();
  EXPECT_EQ(arr1[2], 1);
  EXPECT_EQ(arr1[3], 1);
  arr1 = ~arr1;
  EXPECT_EQ(arr1[2], 0);
  EXPECT_EQ(arr1[3], 0);
}

TEST(Counter, Counter){
  BitArray arr1 = BitArray(8);
  EXPECT_EQ(arr1.count(), 0);
  arr1.set(3, true);
  EXPECT_EQ(arr1.count(), 1);
  arr1.set(4, true);
  arr1.set(5, true);
  EXPECT_EQ(arr1.count(), 3);
}

TEST(To_string, To_string){
  BitArray arr1 = BitArray(8);
  arr1.set(3, true);
  arr1.set(4, true);
  arr1.set(5, true);
  std::string str1 = arr1.to_string();
  std::string str2 = "00011100";
  EXPECT_TRUE(str1 == str2 || str2 == str1);
}

TEST(babab, BasicAssertions){
  BitArray arr = BitArray(5);
  EXPECT_EQ(arr[3], 0);
  arr.set();
  EXPECT_EQ(arr[3], 1);
  arr.set(3, false);
  EXPECT_EQ(arr[3], 0);
}