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
  BitArray arr1 = BitArray(24);
  BitArray arr2 = BitArray(24);
  arr1.reset();
  arr2.set();
  arr2 &= arr1;
  for(size_t i = 0; i < 24; ++i){
    EXPECT_EQ(arr2[i], 0);
  }
  arr1.set(3, true);
  arr1.set(13, true);
  arr1.set(16, true);
  arr1.set(20, true);
  arr1.set(23, true);
  arr2.set();
  arr2 &= arr1;
  EXPECT_EQ(arr2[3], 1);
  EXPECT_EQ(arr2[13], 1);
  EXPECT_EQ(arr2[16], 1);
  EXPECT_EQ(arr2[20], 1);
  EXPECT_EQ(arr2[23], 1);
}

TEST(BitOr, BitOperators){
  BitArray arr1 = BitArray(24);
  BitArray arr2 = BitArray(24);
  arr1.reset();
  arr2.set();
  arr2 |= arr1;
  for(size_t i = 0; i < 24; ++i){
    EXPECT_EQ(arr2[i], 1);
  }
  arr1.set(3, true);
  arr1.set(13, true);
  arr1.set(16, true);
  arr1.set(20, true);
  arr1.set(23, true);
  arr2 |= arr1;
  EXPECT_EQ(arr2[3], 1);
  EXPECT_EQ(arr2[13], 1);
  EXPECT_EQ(arr2[16], 1);
  EXPECT_EQ(arr2[20], 1);
  EXPECT_EQ(arr2[23], 1);
}

TEST(BitXor, BitOperators){
  BitArray arr1 = BitArray(24);
  BitArray arr2 = BitArray(24);
  arr1.reset();
  arr2.set();
  arr2 ^= arr1;
  for(size_t i = 0; i < 24; ++i){
    EXPECT_EQ(arr2[i], 1);
  }
  arr1.set(3, true);
  arr1.set(13, true);
  arr1.set(16, true);
  arr1.set(20, true);
  arr1.set(23, true);
  arr2.reset();
  arr2 ^= arr1;
  EXPECT_EQ(arr2[2], 0);
  EXPECT_EQ(arr2[3], 1);
  EXPECT_EQ(arr2[4], 0);
  EXPECT_EQ(arr2[12], 0);
  EXPECT_EQ(arr2[13], 1);
  EXPECT_EQ(arr2[14], 0);
  EXPECT_EQ(arr2[15], 0);
  EXPECT_EQ(arr2[16], 1);
  EXPECT_EQ(arr2[17], 0);
  EXPECT_EQ(arr2[19], 0);
  EXPECT_EQ(arr2[20], 1);
  EXPECT_EQ(arr2[21], 0);
  EXPECT_EQ(arr2[22], 0);
  EXPECT_EQ(arr2[23], 1);
}

TEST(SelfBitLeftShift, BitShifts){
  BitArray arr1 = BitArray(24);
  arr1.set();
  arr1.set(20, false);
  arr1 <<= 16;
  EXPECT_EQ(arr1[7], 1);
  EXPECT_EQ(arr1[8], 0);
  EXPECT_EQ(arr1[4], 0);
  arr1.reset();
  arr1.set(8, true);
  arr1.set(11, true);
  arr1.set(20, true);
  arr1 <<= 8;
  EXPECT_EQ(arr1[0], 1);
  EXPECT_EQ(arr1[3], 1);
  EXPECT_EQ(arr1[12], 1);
}

TEST(SelfBitRightShift, BitShifts){
  BitArray arr1 = BitArray(24);
  arr1.set();
  arr1.set(4, false);
  arr1 >>= 16;
  EXPECT_EQ(arr1[16], 1);
  EXPECT_EQ(arr1[17], 1);
  EXPECT_EQ(arr1[15], 0);
  EXPECT_EQ(arr1[20], 0);
  arr1.reset();
  arr1.set(4, true);
  arr1.set(7, true);
  arr1 >>= 8;
  EXPECT_EQ(arr1[12], 1);
  EXPECT_EQ(arr1[15], 1);
}

TEST(BitRightShift, BitShifts){
  BitArray arr1 = BitArray(32);
  arr1.reset();
  arr1.set(0, true);
  arr1.set(5, true);
  arr1.set(12, true);
  arr1.set(15, true);
  BitArray arr2 = arr1 >> 16;
  EXPECT_EQ(arr2[0], 0);
  EXPECT_EQ(arr2[5], 0);
  EXPECT_EQ(arr2[12], 0);
  EXPECT_EQ(arr2[15], 0);
  EXPECT_EQ(arr2[16], 1);
  EXPECT_EQ(arr2[21], 1);
  EXPECT_EQ(arr2[28], 1);
  EXPECT_EQ(arr2[31], 1);
}

TEST(BitLeftShift, BitShifts){
  BitArray arr1 = BitArray(32);
  arr1.reset();
  arr1.set(31, true);
  arr1.set(28, true);
  arr1.set(21, true);
  arr1.set(16, true);
  BitArray arr2 = arr1 << 16;
  EXPECT_EQ(arr2[0], 1);
  EXPECT_EQ(arr2[5], 1);
  EXPECT_EQ(arr2[12], 1);
  EXPECT_EQ(arr2[15], 1);
  EXPECT_EQ(arr2[16], 0);
  EXPECT_EQ(arr2[21], 0);
  EXPECT_EQ(arr2[28], 0);
  EXPECT_EQ(arr2[31], 0);
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

TEST(Iterator, Iterator){
  BitArray arr1(16);
  arr1.set();
  for(auto it : arr1){
    EXPECT_EQ(it, 1);
  }
  arr1.reset();
  for(auto it : arr1){
    EXPECT_EQ(it, 0);
  }

  for(auto it : arr1){
    it = true;
  }

  for(auto it = arr1.begin(); it != arr1.end(); ++it){
    it = true;
  }
  for(auto it : arr1){
    EXPECT_EQ(it, 1);
  }
}
