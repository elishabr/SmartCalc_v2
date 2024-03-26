#include "../Calc_v2/Model/model.h"

#ifndef TEST_CALC_V2_MAIN
#include <gtest/gtest.h>
#define TEST_CALC_V2_MAIN
#endif

TEST(Model, CalcTest1) {
  s21::Model m;
  std::string s = "1+2+3*2";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), 9.0L);
}

TEST(Model, CalcTest2) {
  s21::Model m;
  std::string s = "3^3";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), 27.0L);
}

TEST(Model, CalcTest3) {
  s21::Model m;
  std::string s = "1-2";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), -1.0L);
}

TEST(Model, CalcTest4) {
  s21::Model m;
  std::string s = "-1/2";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), -0.5L);
}

TEST(Model, CalcTest5) {
  s21::Model m;
  std::string s = "-1%2";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), -1.0L);
}

TEST(Model, CalcTest6) {
  s21::Model m;
  std::string s = "-1*2.2";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), -2.2L);
}

TEST(Model, CalcTest7) {
  s21::Model m;
  std::string s = "sin(30)";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), std::sin(30.0L));
}

TEST(Model, CalcTest8) {
  s21::Model m;
  std::string s = "cos(30)";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), std::cos(30.0L));
}

TEST(Model, CalcTest9) {
  s21::Model m;
  std::string s = "acos(0.5)";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), std::acos(0.5L));
}

TEST(Model, CalcTest10) {
  s21::Model m;
  std::string s = "sin(30/180*3.14)";
  m.SetInfixAndX(s);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), std::sin(30.0L / 180 * 3.14L));
}

TEST(Model, CalcTest11) {
  s21::Model m;
  std::string s = "sin(x/180*3.14)";
  m.SetInfixAndX(s, 30.0L);
  EXPECT_EQ(m.NotationCalc(), s21::OK);
  std::cout << m.GetResult() << std::endl;
  EXPECT_EQ(m.GetResult(), std::sin(30.0L / 180 * 3.14L));
}