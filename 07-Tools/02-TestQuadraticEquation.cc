extern "C" {
#include "02-SolveQuadraticEquation.h"
}

#include "gtest/gtest.h"


TEST(TestQuadraticEquation, Sanity) {
  float x1, x2;
  EXPECT_TRUE(solve_qe(
      1.f, 2.f, 1.f, &x1, &x2));

  EXPECT_FLOAT_EQ(x1, -1.0f);
  EXPECT_FLOAT_EQ(x2, -1.0f);
}


TEST(TestQuadraticEquation, Failure) {
  float x1 = -100500.f, x2 = -100501.f;
  EXPECT_FALSE(solve_qe(
      1.f, 2.f, 1.000001f, &x1, &x2));

  EXPECT_EQ(x1, -100500.f);
  EXPECT_EQ(x2, -100501.f);
}


TEST(TestQuadraticEquation, Overflow) {
  float x1, x2;
  EXPECT_TRUE(solve_qe(0.f, 1.f, 0.f,
                       &x1, &x2));

  EXPECT_FLOAT_EQ(x1, 0.0f);
  EXPECT_FLOAT_EQ(x2, 0.0f);
}
