#ifndef MODEL_CREDIT_H
#define MODEL_CREDIT_H

#include "SmartCalculator.h"

namespace s21 {
class Credit {
 public:
  Credit(){};
  ~Credit(){};

  void CalculateDifferentPayment(double amountCredit, double period_in_month,
                                 double interestRate);
  void CalculateAnnuityPayment(double amountCredit, double period_in_month,
                               double interestRate);
  const std::vector<double>& GetDifferentPayments() {
    return different_payments_;
  }
  double GetDiffTotalAmount() { return diff_total_amount_; }
  double GetDiffOverpayment() { return diff_overpayment_; }
  double GetAnnuityPayment() { return annuity_payment_; }
  double GetAnnuityOverpament() { return annuity_overpayment_; }
  double GetAnnuityTotalAmount() { return annuity_total_amount_; }

 private:
  std::vector<double> different_payments_{};
  double diff_total_amount_ = 0.0;
  double diff_overpayment_ = 0.0;

  double annuity_payment_ = 0.0;
  double annuity_overpayment_ = 0.0;
  double annuity_total_amount_ = 0.0;
};
}  // namespace s21

#endif  // MODEL_CREDIT_H
