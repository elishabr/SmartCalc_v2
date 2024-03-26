#ifndef MODEL_PARSER_H
#define MODEL_PARSER_H

#include "SmartCalculator.h"

namespace s21 {
class Parser {
 public:
  Parser(){};
  Parser(const std::string &infix, double x);
  ~Parser(){};

  long double GetX() const;
  std::string GetInfix() const;
  std::stack<s21::Elem> GetStack() const;

  s21::ErrorType ParserIt();

 private:
  void RemoveSpaces();
  void ProcessInfixExpression();
  void PushValueIt(std::string::iterator &it);
  void PushUnaryMinus(std::string::iterator &it);
  void PushFunction(std::string::iterator &it);
  void PushOperator(s21::Elem el);
  s21::Elem DefiningOperator(std::string::iterator &it);
  void HandleCloseBracket();
  void StackReverse();

  long double x_{};
  std::string infix_{};
  std::stack<s21::Elem> stack_1_{};
  std::stack<s21::Elem> stack_2_{};
  std::stack<s21::Elem> stack_out_{};
  s21::ErrorType res_of_pars_ = s21::OK;
};
}  // namespace s21

#endif  // MODEL_PARSER_H
