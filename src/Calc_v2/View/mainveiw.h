#ifndef VIEW_MAINVEIW_H
#define VIEW_MAINVEIW_H

#include <QDebug>
#include <QFile>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QUndoStack>
#include <QUndoView>
#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>

#include "../Controller/controller.h"
#include "../Lib/qcustomplot.h"
#include "custombutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainVeiw;
}
QT_END_NAMESPACE

class MainVeiw : public QMainWindow {
  Q_OBJECT

 public:
  MainVeiw(s21::Controller *controller_m, QWidget *parent = nullptr);
  void onButtonClicked(QString str);
  void onButtonDel();
  void onButtonEqually();
  void onAreaXAction();
  void onAreaYAction();
  void onButtonCredit();
  ~MainVeiw();

  double value_x = 0.0;
  bool buildingСhart = false;
  double areaX = 10;
  double areaY = 1000000;
  double step = 0.04;

 private:
  void CalcView();
  void ChartView();
  void CreditView();
  void HistoryView();
  void BuildChart();

  s21::Controller *controller{};
  Ui::MainVeiw *ui{};
  QCustomPlot *chartView{};
  QTabWidget *centralWidget{};
  QWidget *tab1{};
  QWidget *tab2{};
  QWidget *tab3{};
  QWidget *tab4{};
  QLabel *display{};
  QUndoStack *undoStack{};
  QUndoView *undoView{};
  QAction *XAction{};
  QAction *YAction{};
  QAction *StepAction{};

  QLineEdit *amountEdit{};
  QLineEdit *periodEdit{};
  QLineEdit *interestEdit{};
  PeriodButton *periodButton{};
  QRadioButton *AnnuityPaymentBut{};
  QRadioButton *DifferentPaymentsBut{};
  QLabel *lablePayment{};
  QLabel *lableOverpayment{};
  QLabel *lableTotalAmount{};

  int isBracketsBalanced = 0;
  bool exponentialError = false;
  bool pointsError = false;

  QVector<double> rangeX{};
  QVector<double> rangeY{};

  int period = s21::Controller::year;
  int type_credit = s21::Controller::different_payment;
};
#endif  // VIEW_MAINVEIW_H
