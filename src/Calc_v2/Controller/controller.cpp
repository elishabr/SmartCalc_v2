#include "controller.h"

#include <iomanip>
#include <sstream>

s21::Controller::Controller(Model *m1, Credit *m2)
    : model_calc(m1), model_credit(m2) {}

void s21::Controller::CalcCredit(const int type_credit, const int type_period,
                                 double amountCredit, double period_in,
                                 double interestRate) {
  double period_in_month = (type_period == year ? period_in * 12 : period_in);
  if (type_credit == annuity_payment) {
    model_credit->CalculateAnnuityPayment(amountCredit, period_in_month,
                                          interestRate);
  } else if (type_credit == different_payment) {
    model_credit->CalculateDifferentPayment(amountCredit, period_in_month,
                                            interestRate);
  }
}

const QString &s21::Controller::GetResult(const QString &expression,
                                          long double x) {
  std::string s = expression.toStdString();
  model_calc->SetInfixAndX(s, x);
  et = model_calc->NotationCalc();
  // Установка точности
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(8) << model_calc->GetResult();
  result = QString::fromStdString(stream.str());
  return result;
}

s21::ErrorType s21::Controller::GetErrorType() { return et; }

QString s21::Controller::GetFirstDifferentPayments() {
  double payments = model_credit->GetDifferentPayments().front();
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2) << payments;
  result = QString::fromStdString(stream.str());
  return result;
}

QString s21::Controller::GetLastDifferentPayments() {
  double payments = model_credit->GetDifferentPayments().back();
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2) << payments;
  result = QString::fromStdString(stream.str());
  return result;
}

QString s21::Controller::GetDiffTotalAmount() {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2)
         << model_credit->GetDiffTotalAmount();
  result = QString::fromStdString(stream.str());
  return result;
}

QString s21::Controller::GetDiffOverpayment() {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2)
         << model_credit->GetDiffOverpayment();
  result = QString::fromStdString(stream.str());
  return result;
}

QString s21::Controller::GetAnnuityPayment() {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2)
         << model_credit->GetAnnuityPayment();
  result = QString::fromStdString(stream.str());
  return result;
}

QString s21::Controller::GetAnnuityOverpament() {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2)
         << model_credit->GetAnnuityOverpament();
  result = QString::fromStdString(stream.str());
  return result;
}

QString s21::Controller::GetAnnuityTotalAmount() {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2)
         << model_credit->GetAnnuityTotalAmount();
  result = QString::fromStdString(stream.str());
  return result;
}
