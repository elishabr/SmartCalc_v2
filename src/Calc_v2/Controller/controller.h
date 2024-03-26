#ifndef CONTROLLER_CONTROLLER_H
#define CONTROLLER_CONTROLLER_H

#include <QString>
#include <QVector>

#include "../Model/credit.h"
#include "../Model/model.h"

namespace s21 {
class Controller {
 public:
  Controller(s21::Model *m1, s21::Credit *m2);
  void CalcCredit(const int type_credit, const int type_period,
                  double amountCredit, double period_in, double interestRate);
  const QString &GetResult(const QString &expression, long double x);
  s21::ErrorType GetErrorType();

  QString GetFirstDifferentPayments();
  QString GetLastDifferentPayments();
  QString GetDiffTotalAmount();
  QString GetDiffOverpayment();
  QString GetAnnuityPayment();
  QString GetAnnuityOverpament();
  QString GetAnnuityTotalAmount();

  static const int different_payment = 0;
  static const int annuity_payment = 1;
  static const int year = 0;
  static const int month = 1;

 private:
  s21::Model *model_calc{};
  s21::Credit *model_credit{};
  QString result{};
  s21::ErrorType et = s21::OK;
};
}  // namespace s21
#endif  // CONTROLLER_CONTROLLER_H
