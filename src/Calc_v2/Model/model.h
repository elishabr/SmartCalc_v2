#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "parser.h"

namespace s21 {
class Model {
 public:
  Model(){};
  ~Model(){};

  long double GetResult() const;
  void SetInfixAndX(std::string &str, long double x = 0);
  s21::ErrorType NotationCalc();

 private:
  void MathOperation(s21::Elem el);
  void MathFunction(s21::Elem el);

  long double x_{};
  std::string infix_{};
  std::stack<long double> stack_out_{};
  std::stack<s21::Elem> stack_postfix_{};
  s21::ErrorType res_of_calc_ = s21::OK;
};
}  // namespace s21

#endif  // MODEL_MODEL_H
