
#include "../Calc_v2/Model/parser.h"

#ifndef TEST_CALC_V2_MAIN
#include <gtest/gtest.h>
#define TEST_CALC_V2_MAIN
#endif

TEST(Parser, ContructorDef) {
  s21::Parser res;
  EXPECT_EQ(res.GetX(), 0);
  EXPECT_EQ(res.GetInfix(), "");
}

TEST(Parser, Contructor) {
  s21::Parser res("gggggggg", 10);
  EXPECT_EQ(res.GetX(), 10.0);
  EXPECT_EQ(res.GetInfix(), "gggggggg");
}

TEST(Parser, PushValueIt) {
  s21::Parser res("1.999e+2", 0);
  EXPECT_EQ(res.ParserIt(), s21::OK);
  std::stack<s21::Elem> s = res.GetStack();
  EXPECT_EQ(s.top().value, 1.999E+2L);
}

TEST(Parser, Test1) {
  s21::Parser res("1.999e+2+x", 0);
  EXPECT_EQ(res.ParserIt(), s21::OK);
  std::stack<s21::Elem> s = res.GetStack();
  EXPECT_EQ(s.top().value, 1.999E+2L);
  s.pop();
  EXPECT_EQ(s.top().value_type, s21::kX);
  s.pop();
  EXPECT_EQ(s.top().operatorOrFunc, s21::kPlus);
  s.pop();
}

TEST(Parser, Test2) {  // 2 30+180 / sin 1.999E+2+x+
  s21::Parser res("sin((2+30)/180)+1.999e+2+x", 0);
  EXPECT_EQ(res.ParserIt(), s21::OK);
  std::stack<s21::Elem> s = res.GetStack();
  EXPECT_EQ(s.top().value, 2.0L);
  s.pop();
  EXPECT_EQ(s.top().value, 30.0L);
  s.pop();
  EXPECT_EQ(s.top().operatorOrFunc, s21::kPlus);
  s.pop();
  EXPECT_EQ(s.top().value, 180.0L);
  s.pop();
  EXPECT_EQ(s.top().operatorOrFunc, s21::kDiv);
  s.pop();
  EXPECT_EQ(s.top().operatorOrFunc, s21::kSin);
  s.pop();
  EXPECT_EQ(s.top().value, 1.999E+2L);
  s.pop();
  EXPECT_EQ(s.top().operatorOrFunc, s21::kPlus);
  s.pop();
  EXPECT_EQ(s.top().value_type, s21::kX);
  s.pop();
  EXPECT_EQ(s.top().operatorOrFunc, s21::kPlus);
  s.pop();
}

TEST(Parser, Test3) {  // 3 3 ^
  s21::Parser res("3^3", 0);
  EXPECT_EQ(res.ParserIt(), s21::OK);
  std::stack<s21::Elem> s = res.GetStack();
  EXPECT_EQ(s.top().value, 3.0L);
  s.pop();
  EXPECT_EQ(s.top().value, 3.0L);
  s.pop();
  EXPECT_EQ(s.top().operatorOrFunc, s21::kDegree);
  s.pop();
}

TEST(Parser, Test4) {  // 3 3 %
  s21::Parser res("3%3", 0);
  EXPECT_EQ(res.ParserIt(), s21::OK);
  std::stack<s21::Elem> s = res.GetStack();
  std::cout << s.top().value << std::endl;
  EXPECT_EQ(s.top().value, 3.0L);
  s.pop();
  std::cout << s.top().value << std::endl;
  EXPECT_EQ(s.top().value, 3.0L);
  s.pop();
  std::cout << s.top().operatorOrFunc << std::endl;
  EXPECT_EQ(s.top().operatorOrFunc, s21::kMod);
  s.pop();
}
