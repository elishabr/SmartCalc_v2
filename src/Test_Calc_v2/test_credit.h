#include "../Calc_v2/Model/credit.h"

#ifndef TEST_CALC_V2_MAIN
#include <gtest/gtest.h>
#define TEST_CALC_V2_MAIN
#endif

TEST(Credit, CalculateDifferentPayment) {
  s21::Credit c;
  c.CalculateDifferentPayment(5000.0, 12, 16.6);
  EXPECT_NEAR(c.GetDiffTotalAmount(), 5449.58, 0.01);
  std::cout << c.GetDiffTotalAmount() << std::endl;
  EXPECT_NEAR(c.GetDiffOverpayment(), 449.58, 0.01);
  std::cout << c.GetDiffOverpayment() << std::endl;
  for (auto v : c.GetDifferentPayments()) {
    std::cout << "-- " << v << std::endl;
  }
}

TEST(Credit, CalculateAnnuityPayment) {
  s21::Credit c;
  c.CalculateAnnuityPayment(5000.0, 12, 16.6);
  EXPECT_NEAR(c.GetAnnuityTotalAmount(), 5460.90, 0.01);
  std::cout << "---" << c.GetAnnuityTotalAmount() << std::endl;
  EXPECT_NEAR(c.GetAnnuityOverpament(), 460.90, 0.01);
  std::cout << "---" << c.GetAnnuityOverpament() << std::endl;
  EXPECT_NEAR(c.GetAnnuityPayment(), 455.075, 0.01);
  std::cout << "---" << c.GetAnnuityPayment() << std::endl;
}