#include "model.h"

// ------public------

void s21::Model::SetInfixAndX(std::string &str, long double x) {
  x_ = x;
  infix_ = str;
  stack_out_ = {};
  s21::Parser parser(infix_, x_);
  res_of_calc_ = parser.ParserIt();
  stack_postfix_ = parser.GetStack();
}

long double s21::Model::GetResult() const { return stack_out_.top(); }

s21::ErrorType s21::Model::NotationCalc() {
  while (!stack_postfix_.empty()) {
    s21::Elem element = stack_postfix_.top();
    stack_postfix_.pop();
    if (element.value_type == s21::kNumbe) {
      stack_out_.push(element.value);
    } else if (element.value_type == s21::kOperation) {
      MathOperation(element);
    } else if (element.value_type == s21::kFunction) {
      MathFunction(element);
    } else if (element.value_type == kX) {
      stack_out_.push(x_);
    }
  }
  return res_of_calc_;
}

// ------private------

void s21::Model::MathOperation(s21::Elem el) {
  if (stack_out_.size() < 2) {
    res_of_calc_ = s21::CALCULATION_ERROR;
    return;
  }
  long double r_value = stack_out_.top();
  stack_out_.pop();
  long double l_value = stack_out_.top();
  stack_out_.pop();
  long double result = v_lxm.find(el.operatorOrFunc)->second(l_value, r_value);
  stack_out_.push(result);
}

void s21::Model::MathFunction(s21::Elem el) {
  if (stack_out_.size() < 1) {
    res_of_calc_ = s21::CALCULATION_ERROR;
    return;
  }
  long double value = stack_out_.top();
  stack_out_.pop();
  long double result = v_func.find(el.operatorOrFunc)->second(value);
  stack_out_.push(result);
}