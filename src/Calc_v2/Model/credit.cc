#include "credit.h"

void s21::Credit::CalculateDifferentPayment(double amountCredit,
                                            double period_in_month,
                                            double interestRate) {
  diff_overpayment_ = amountCredit;
  double interestRate_in_month = interestRate / (12.0 * 100.0);
  double mainDebt = amountCredit / period_in_month;
  for (int i = 0; i < period_in_month; i++) {
    double payment = mainDebt + amountCredit * interestRate_in_month;
    different_payments_.push_back(payment);
    amountCredit -= mainDebt;
    diff_total_amount_ += payment;
  }
  diff_overpayment_ = diff_total_amount_ - diff_overpayment_;
}

void s21::Credit::CalculateAnnuityPayment(double amountCredit,
                                          double period_in_month,
                                          double interestRate) {
  double interestRate_in_month = interestRate / (12.0 * 100.0);
  annuity_payment_ = amountCredit *
                     (interestRate_in_month *
                      pow(1 + interestRate_in_month, period_in_month)) /
                     (pow(1 + interestRate_in_month, period_in_month) - 1);
  annuity_total_amount_ = annuity_payment_ * period_in_month;
  annuity_overpayment_ = annuity_total_amount_ - amountCredit;
}
