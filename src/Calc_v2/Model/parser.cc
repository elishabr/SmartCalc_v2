#include "parser.h"

// ------public------

s21::Parser::Parser(const std::string &infix, double x)
    : x_(x), infix_(infix) {}

long double s21::Parser::GetX() const { return x_; }

std::string s21::Parser::GetInfix() const { return infix_; }

std::stack<s21::Elem> s21::Parser::GetStack() const { return stack_out_; }

s21::ErrorType s21::Parser::ParserIt() {
  RemoveSpaces();
  char symbol_beg = '(';
  char symbol_end = ')';
  infix_ = symbol_beg + infix_ + symbol_end;
  ProcessInfixExpression();
  StackReverse();
  return res_of_pars_;
}

// ------private------

/**
 * @brief Function to remove all spaces from strings.
 * @param str Source string.
 * @return New line without spaces.
 */
void s21::Parser::RemoveSpaces() {
  std::string result{};
  std::remove_copy(infix_.begin(), infix_.end(), std::back_inserter(result),
                   ' ');
  infix_ = result;
}

void s21::Parser::ProcessInfixExpression() {
  for (auto it = infix_.begin(); it != infix_.end(); ++it) {
    if (*it >= '0' && *it <= '9') {
      PushValueIt(it);
      --it;
    } else if (*it == 'x') {
      stack_1_.push({s21::kX, s21::kFirst, kNotFunc, 0.0L});
    } else if (*it == '(' && (*(it + 1) == '-' || *(it + 1) == '+')) {
      PushUnaryMinus(++it);
    } else if (*it == '(') {
      stack_2_.push({s21::kOpenBracket, s21::kFirst, s21::kNotFunc, 0});
    } else if ((*it >= 'a' && *it <= 'z') || *it == '%') {
      PushFunction(it);
    } else if (*it == '+' || *it == '-' || *it == '*' || *it == '^' ||
               *it == '/') {
      s21::Elem el = DefiningOperator(it);
      PushOperator(el);
    } else if (*it == ')') {
      HandleCloseBracket();
    } else {
      it = infix_.end();
      res_of_pars_ = s21::UNKNOWN_ERROR;
    }
  }
}

void s21::Parser::PushValueIt(std::string::iterator &it) {
  std::string help_str{};
  while ((*it >= '0' && *it <= '9') || *it == '.' ||
         (*it == 'e' && (*(it + 1) == '+' || *(it + 1) == '-')) ||
         (*(it - 1) == 'e' && (*it == '+' || *it == '-'))) {
    help_str.push_back(*it++);
  }
  try {
    stack_1_.push({s21::kNumbe, s21::kFirst, kNotFunc, std::stold(help_str)});
  } catch (...) {
    res_of_pars_ = s21::NUMBER_ERROR;
  }
}

void s21::Parser::PushUnaryMinus(std::string::iterator &it) {
  stack_2_.push({s21::kOpenBracket, s21::kFirst, s21::kNotFunc, 0});
  if (*it == '-') {
    stack_2_.push({s21::kOperation, s21::kSixth, s21::kMinus, 0});
  } else {
    stack_2_.push({s21::kOperation, s21::kSixth, s21::kPlus, 0});
  }
  stack_1_.push({s21::kNumbe, s21::kFirst, s21::kNotFunc, 0});
}

void s21::Parser::PushFunction(std::string::iterator &it) {
  res_of_pars_ = s21::FUNCTION_ERROR;
  for (auto iter = math_func.begin(); iter != math_func.end(); ++iter) {
    if (*it == '%' && (*iter).first[0] == *it) {
      stack_2_.push({s21::kOperation, s21::kThird, (*iter).second, 0});
      // std::cout << "++++"<<(*iter).second <<s21::kMod<<std::endl;
      res_of_pars_ = s21::OK;
    } else if ((*iter).first[0] == *it && (*iter).first[1] == *(it + 1)) {
      stack_2_.push({s21::kFunction, s21::kFifth, (*iter).second, 0});
      for (size_t i = 0; i < (*iter).first.size() - 1; ++i, ++it)
        ;
      res_of_pars_ = s21::OK;
    }
  }
}

s21::Elem s21::Parser::DefiningOperator(std::string::iterator &it) {
  s21::Elem oper{};
  res_of_pars_ = s21::OPERATOR_ERROR;
  for (auto iter = operators.begin(); iter != operators.end(); ++iter) {
    if ((*iter).first == *it) {
      if (*it == '+' || *it == '-') {
        oper = {s21::kOperation, s21::kSecond, (*iter).second, 0};
      } else if (*it == '*' || *it == '/') {
        oper = {s21::kOperation, s21::kThird, (*iter).second, 0};
      } else if (*it == '^') {
        oper = {s21::kOperation, s21::kFourth, (*iter).second, 0};
      }
      res_of_pars_ = s21::OK;
    }
  }
  return oper;
}

void s21::Parser::PushOperator(s21::Elem el) {
  while (!stack_2_.empty() && el.priority <= stack_2_.top().priority) {
    s21::Elem priority_el = stack_2_.top();
    stack_2_.pop();
    stack_1_.push(priority_el);
  }
  stack_2_.push(el);
}

void s21::Parser::HandleCloseBracket() {
  s21::Elem el = stack_2_.top();
  stack_2_.pop();
  while (!stack_2_.empty() && el.value_type != s21::kOpenBracket) {
    stack_1_.push(el);
    el = stack_2_.top();
    stack_2_.pop();
  }
  if (!stack_2_.empty() && stack_2_.top().value_type == kFunction) {
    el = stack_2_.top();
    stack_2_.pop();
    stack_1_.push(el);
  }
}

void s21::Parser::StackReverse() {
  while (!stack_1_.empty()) {
    s21::Elem el = stack_1_.top();
    stack_1_.pop();
    stack_out_.push(el);
  }
}
