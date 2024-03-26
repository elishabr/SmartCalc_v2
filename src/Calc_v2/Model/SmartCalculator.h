#ifndef MODEL_SMART_CAL_CULATOR_H
#define MODEL_SMART_CAL_CULATOR_H

#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

namespace s21 {
enum OperationAndFunction : char {
  kNotFunc = 0,
  kPlus,
  kMinus,
  kMul,
  kDiv,
  kDegree,
  kSin,
  kCos,
  kTan,
  kAsin,
  kAcos,
  kAtan,
  kSqrt,
  kLn,
  kLog,
  kMod,
  kUnMinus,
  kUnPlus
};
// x = kFirst, +- = kSecond, */ = kThird, ^ = kFourth, sin.. = kFifth, -+un =
// kSixth
enum PriorityOperation : char {
  kFirst = 0,
  kSecond,
  kThird,
  kFourth,
  kFifth,
  kSixth
};

enum ValueType : char { kNumbe = 0, kX, kOperation, kFunction, kOpenBracket };

enum ErrorType : char {
  UNKNOWN_ERROR = 0,
  OK,
  OPERATOR_ERROR,
  NUMBER_ERROR,
  BRACKETS_ERROR,
  CALCULATION_ERROR,
  DIAPOSON_ERROR,
  FUNCTION_ERROR
};

struct Elem {
  ValueType value_type = kNumbe;
  PriorityOperation priority = kFirst;
  OperationAndFunction operatorOrFunc = kNotFunc;
  long double value{};
};

const std::map<std::string, OperationAndFunction> math_func = {
    {"sin", kSin},   {"cos", kCos},   {"tan", kTan},   {"asin", kAsin},
    {"acos", kAcos}, {"atan", kAtan}, {"sqrt", kSqrt}, {"ln", kLn},
    {"log", kLog},   {"%", kMod}};

const std::map<char, OperationAndFunction> operators = {
    {'+', kPlus}, {'-', kMinus}, {'^', kDegree}, {'*', kMul}, {'/', kDiv}};

const std::map<OperationAndFunction, long double (*)(long double)> v_func{
    {kSin, std::sin},   {kCos, std::cos},   {kTan, std::tan},
    {kAsin, std::asin}, {kAcos, std::acos}, {kAtan, std::atan},
    {kSqrt, std::sqrt}, {kLn, std::log},    {kLog, std::log10}};

const std::map<OperationAndFunction,
               std::function<long double(long double, long double)>>
    v_lxm = {
        {kPlus, std::plus<long double>()},
        {kMinus, std::minus<long double>()},
        {kMul, std::multiplies<long double>()},
        {kDiv, std::divides<long double>()},
        {kDegree, [](long double x, long double y) { return std::pow(x, y); }},
        {kMod,
         [](long double x, long double y) { return std::remainder(x, y); }}};

}  // namespace s21

#endif  // MODEL_SMART_CAL_CULATOR_H
