#include "mainveiw.h"

#include "mycommand.h"
#include "mydialog.h"
#include "ui_mainveiw.h"
#include "xareadialog.h"
#include "yareadialog.h"

MainVeiw::MainVeiw(s21::Controller *controller_m, QWidget *parent)
    : QMainWindow(parent), controller(controller_m), ui(new Ui::MainVeiw) {
  ui->setupUi(this);

  this->resize(280, 490);
  this->setMinimumSize(280, 490);
  centralWidget = new QTabWidget(this);
  centralWidget->setTabPosition(QTabWidget::North);
  tab1 = new QWidget(this);
  centralWidget->addTab(tab1, " Calc ");
  tab2 = new QWidget(this);
  centralWidget->addTab(tab2, "Chart");
  tab3 = new QWidget(this);
  centralWidget->addTab(tab3, "Сredit");
  tab4 = new QWidget(this);
  centralWidget->addTab(tab4, "History");
  this->setCentralWidget(centralWidget);
  CalcView();
  ChartView();
  CreditView();
  HistoryView();
}

void MainVeiw::CalcView() {
  QGridLayout *gridLayout = new QGridLayout(tab1);
  gridLayout->setContentsMargins(0, 0, 0, 0);  // Убираем отступы
  gridLayout->setSpacing(0);  // Устанавливаем расстояние между виджетами
  gridLayout->setVerticalSpacing(
      12);  // Устанавливаем расстояние между виджетами по вертикали
  gridLayout->setHorizontalSpacing(
      0);  // Устанавливаем расстояние между виджетами по горизонтали

  display = new QLabel("0", this);
  display->setStyleSheet(
      "color: #FFFFFF; "
      "font-size: 20px; "
      "font-weight: bold;"
      "padding: 5px 10px;");
  display->setAlignment(Qt::AlignCenter | Qt::AlignRight);
  display->setMinimumHeight(60);
  display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  gridLayout->addWidget(display, 0, 0, 1, 4);

  QMenu *menu1 = new QMenu;
  QAction *lnAction = new QAction("ln ( )", this);
  menu1->addAction(lnAction);
  QAction *logAction = new QAction("log ( )", this);
  menu1->addAction(logAction);
  QAction *SqrtAction = new QAction("sqrt ( )", this);
  menu1->addAction(SqrtAction);
  QAction *ModAction = new QAction("mod", this);
  menu1->addAction(ModAction);
  QAction *PowAction = new QAction("pow ( )", this);
  menu1->addAction(PowAction);
  CustomButton_menu *push1 = new CustomButton_menu("Mathematics", 30, this);
  push1->setMenu(menu1);
  gridLayout->addWidget(push1, 1, 0, 1, 2);
  CustomButton_menu *push2 = new CustomButton_menu("Trigonometry", 30, this);
  QMenu *menu2 = new QMenu;
  QAction *SinAction = new QAction("sin ( )", this);
  menu2->addAction(SinAction);
  QAction *CosAction = new QAction("cos ( )", this);
  menu2->addAction(CosAction);
  QAction *TanAction = new QAction("tan ( )", this);
  menu2->addAction(TanAction);
  QAction *AsinAction = new QAction("asin ( )", this);
  menu2->addAction(AsinAction);
  QAction *AcosAction = new QAction("acos ( )", this);
  menu2->addAction(AcosAction);
  QAction *AtanAction = new QAction("atan ( )", this);
  menu2->addAction(AtanAction);
  push2->setMenu(menu2);
  gridLayout->addWidget(push2, 1, 2, 1, 2);
  CustomButton_menu *push2_1 = new CustomButton_menu("(", 30, this);
  gridLayout->addWidget(push2_1, 2, 0, 1, 2);
  CustomButton_menu *push2_2 = new CustomButton_menu(")", 30, this);
  gridLayout->addWidget(push2_2, 2, 2, 1, 2);
  CustomButton *push3_1 = new CustomButton("С", 70, this);
  gridLayout->addWidget(push3_1, 3, 0);
  CustomButton *push3_2 = new CustomButton("x", 70, this);
  gridLayout->addWidget(push3_2, 3, 1);
  CustomButton *push3_3 = new CustomButton("e", 70, this);
  gridLayout->addWidget(push3_3, 3, 2);
  CustomButton_right *push3_4 = new CustomButton_right("÷", 70, this);
  gridLayout->addWidget(push3_4, 3, 3);
  CustomButton *push4_1 = new CustomButton("7", 70, this);
  gridLayout->addWidget(push4_1, 4, 0);
  CustomButton *push4_2 = new CustomButton("8", 70, this);
  gridLayout->addWidget(push4_2, 4, 1);
  CustomButton *push4_3 = new CustomButton("9", 70, this);
  gridLayout->addWidget(push4_3, 4, 2);
  CustomButton_right *push4_4 = new CustomButton_right("×", 70, this);
  gridLayout->addWidget(push4_4, 4, 3);
  CustomButton *push5_1 = new CustomButton("4", 70, this);
  gridLayout->addWidget(push5_1, 5, 0);
  CustomButton *push5_2 = new CustomButton("5", 70, this);
  gridLayout->addWidget(push5_2, 5, 1);
  CustomButton *push5_3 = new CustomButton("6", 70, this);
  gridLayout->addWidget(push5_3, 5, 2);
  CustomButton_right *push5_4 = new CustomButton_right("−", 70, this);
  gridLayout->addWidget(push5_4, 5, 3);
  CustomButton *push6_1 = new CustomButton("1", 70, this);
  gridLayout->addWidget(push6_1, 6, 0);
  CustomButton *push6_2 = new CustomButton("2", 70, this);
  gridLayout->addWidget(push6_2, 6, 1);
  CustomButton *push6_3 = new CustomButton("3", 70, this);
  gridLayout->addWidget(push6_3, 6, 2);
  CustomButton_right *push6_4 = new CustomButton_right("+", 70, this);
  gridLayout->addWidget(push6_4, 6, 3);
  CustomButton *push7_1 = new CustomButton("0", 70, this);
  gridLayout->addWidget(push7_1, 7, 0, 1, 2);
  CustomButton *push7_2 = new CustomButton(".", 70, this);
  gridLayout->addWidget(push7_2, 7, 2);
  CustomButton_right *push7_4 = new CustomButton_right("=", 70, this);
  gridLayout->addWidget(push7_4, 7, 3);

  // numder
  connect(push4_1, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("7"); });
  connect(push4_2, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("8"); });
  connect(push4_3, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("9"); });
  connect(push5_1, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("4"); });
  connect(push5_2, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("5"); });
  connect(push5_3, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("6"); });
  connect(push6_1, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("1"); });
  connect(push6_2, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("2"); });
  connect(push6_3, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("3"); });
  connect(push7_1, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("0"); });
  // operation
  connect(push3_4, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("/"); });
  connect(push4_4, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("*"); });
  connect(push5_4, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("-"); });
  connect(push6_4, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("+"); });
  connect(PowAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("^"); });
  connect(ModAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("%"); });
  // x e
  connect(push3_2, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("x"); });
  connect(push3_3, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("e"); });
  // Brackets
  connect(push2_1, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("("); });
  connect(push2_2, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked(")"); });
  // function Math
  connect(lnAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("ln("); });
  connect(logAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("log("); });
  connect(SqrtAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("sqrt("); });
  // function Trig
  connect(SinAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("sin("); });
  connect(CosAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("cos("); });
  connect(TanAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("tan("); });
  connect(AsinAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("asin("); });
  connect(AcosAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("acos("); });
  connect(AtanAction, &QAction::triggered, this,
          [this] { MainVeiw::onButtonClicked("atan("); });
  // dot and del
  connect(push7_2, &QPushButton::clicked, this,
          [this] { MainVeiw::onButtonClicked("."); });
  connect(push3_1, &QPushButton::clicked, this, &MainVeiw::onButtonDel);
  // =
  connect(push7_4, &QPushButton::clicked, this, &MainVeiw::onButtonEqually);
}

void MainVeiw::ChartView() {
  QGridLayout *gridLayout = new QGridLayout(tab2);
  chartView = new QCustomPlot(tab2);
  gridLayout->setContentsMargins(0, 0, 0, 0);  // Убираем отступы
  gridLayout->setSpacing(0);  // Устанавливаем расстояние между виджетами
  gridLayout->addWidget(chartView);

  ScopeButton *scopeDef = new ScopeButton("", 30, chartView);
  scopeDef->setIcon(QIcon(":/settings.png"));
  QMenu *menu2 = new QMenu;
  XAction =
      new QAction("Область определения:  ±" + QString::number(areaX), this);
  menu2->addAction(XAction);
  YAction =
      new QAction("Область значения:        ±" + QString::number(areaY), this);
  menu2->addAction(YAction);
  StepAction = new QAction(
      "Шаг:                          " + QString::number(step, 'f', 5), this);
  menu2->addAction(StepAction);
  scopeDef->setMenu(menu2);
  scopeDef->move(5, 5);

  chartView->xAxis->setRange(-areaX, areaX);
  chartView->yAxis->setRange(-10, 10);

  chartView->setInteraction(QCP::iRangeZoom, true);
  chartView->setInteraction(QCP::iRangeDrag, true);

  connect(XAction, &QAction::triggered, this, &MainVeiw::onAreaXAction);
  connect(YAction, &QAction::triggered, this, &MainVeiw::onAreaYAction);
}

void MainVeiw::CreditView() {
  QGridLayout *gridLayout = new QGridLayout(tab3);
  gridLayout->setContentsMargins(5, 0, 5, 0);  // Убираем отступы
  gridLayout->setSpacing(0);  // Устанавливаем расстояние между виджетами
  amountEdit = new QLineEdit();
  amountEdit->setPlaceholderText("Сумма кредита");
  amountEdit->setToolTip("Максимальное значение 999 999 999 999");
  QLabel *amountLabel = new QLabel("   ₽");
  gridLayout->addWidget(amountEdit, 0, 0, 1, 1);
  gridLayout->addWidget(amountLabel, 0, 1, 1, 1);
  periodEdit = new QLineEdit();
  periodEdit->setPlaceholderText("Срок кредита");
  periodEdit->setStyleSheet("margin-top: 0px;");
  periodEdit->setToolTip("Максимальное значение 50 лет");
  QMenu *menu = new QMenu;
  QAction *yearAction = new QAction("лет", this);
  menu->addAction(yearAction);
  QAction *monthAction = new QAction("месяцев", this);
  menu->addAction(monthAction);
  periodButton = new PeriodButton("лет");
  periodButton->setMenu(menu);
  gridLayout->addWidget(periodEdit, 1, 0, 1, 1);
  gridLayout->addWidget(periodButton, 1, 1, 1, 1);
  interestEdit = new QLineEdit();
  interestEdit->setPlaceholderText("Процентная ставка");
  interestEdit->setToolTip("Максимальное значение 999 %");
  QLabel *interestLabel = new QLabel("   %");
  gridLayout->addWidget(interestEdit, 2, 0, 1, 1);
  gridLayout->addWidget(interestLabel, 2, 1, 1, 1);
  QGroupBox *groupBox1 = new QGroupBox("Тип ежемесячных платежей");
  AnnuityPaymentBut = new QRadioButton("Аннуитетные");
  DifferentPaymentsBut = new QRadioButton("Дифференцированные");
  DifferentPaymentsBut->setChecked(true);
  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding,
                                QSizePolicy::Maximum));  // Добавляем промежуток
  vbox->addWidget(DifferentPaymentsBut);
  vbox->addWidget(AnnuityPaymentBut);
  CustomButton_menu *buttonCredit = new CustomButton_menu("Рассчитать", 50);
  vbox->addWidget(buttonCredit);
  groupBox1->setLayout(vbox);
  gridLayout->addWidget(groupBox1, 3, 0, 2, 2);

  QGroupBox *groupBox2 = new QGroupBox("");
  QVBoxLayout *vbox2 = new QVBoxLayout();
  lablePayment = new QLabel("Ежемесячный платеж: 0");
  vbox2->addWidget(lablePayment);
  lableOverpayment = new QLabel("Начисленные проценты: 0");
  vbox2->addWidget(lableOverpayment);
  lableTotalAmount = new QLabel("Долг + проценты: 0");
  vbox2->addWidget(lableTotalAmount);
  groupBox2->setLayout(vbox2);
  gridLayout->addWidget(groupBox2, 5, 0, 2, 2);
  gridLayout->addItem(
      new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Maximum), 7,
      0, 1, 2);  // Добавляем промежуток

  connect(monthAction, &QAction::triggered, this, [this] {
    periodButton->setText("месяцев");
    period = s21::Controller::month;
  });
  connect(yearAction, &QAction::triggered, this, [this] {
    periodButton->setText("лет");
    period = s21::Controller::year;
  });
  connect(buttonCredit, &QPushButton::clicked, this, &MainVeiw::onButtonCredit);
  connect(amountEdit, &QLineEdit::textChanged, this,
          [this] { amountEdit->setStyleSheet("border: 2px solid #31CC24 ;"); });
  connect(periodEdit, &QLineEdit::textChanged, this,
          [this] { periodEdit->setStyleSheet("border: 2px solid #31CC24 ;"); });
  connect(interestEdit, &QLineEdit::textChanged, this, [this] {
    interestEdit->setStyleSheet("border: 2px solid #31CC24 ;");
  });
}

void MainVeiw::HistoryView() {
  QGridLayout *gridLayout = new QGridLayout(tab4);
  // Создание стека действий
  undoStack = new QUndoStack(tab4);
  undoView = new QUndoView(undoStack);
  gridLayout->setContentsMargins(0, 0, 0, 0);  // Убираем отступы
  gridLayout->setSpacing(0);  // Устанавливаем расстояние между виджетами
  gridLayout->addWidget(undoView);
  undoView->setEmptyLabel(tr("0"));
}

void MainVeiw::BuildChart() {
  rangeX.clear();
  rangeY.clear();
  if (exponentialError || pointsError || isBracketsBalanced != 0) return;
  if (display->text() == "(" || display->text() == "") return;
  double valueY = 0.0;
  for (double x = -areaX; x <= areaX;) {
    QString result = controller->GetResult(display->text(), x);
    if (controller->GetErrorType() != s21::OK) return;
    valueY = result.toDouble();
    if (std::fabs(valueY) <= areaY) {
      rangeX.push_back(x);
      rangeY.push_back(valueY);
    }
    x += step;
  }

  chartView->clearGraphs();
  chartView->addGraph();
  QPen pen;
  pen.setColor(QColor(49, 204, 36));
  pen.setWidth(2);
  chartView->graph(0)->setPen(pen);
  chartView->graph(0)->addData(rangeX, rangeY);
  chartView->replot();
}

void MainVeiw::onButtonClicked(QString str) {
  QVector<QString> vector_func{"ln(",  "log(",  "sqrt(", "sin(", "cos(",
                               "tan(", "asin(", "acos(", "atan("};
  QString array_oper = "*/+-^%";
  QString text = display->text();
  int length = text.length();

  if (text == "" && (str == "." || str == "e")) return;
  if (text.length() == 300) return;
  if (length > 2 && text[length - 2] == 'e') exponentialError = true;
  if (str != "-" && str != "+" && text != "" && text[length - 1] == 'e') return;
  if (text != "" && text[length - 1] == 'x' && str[0].isDigit()) return;
  if (str == ")" && isBracketsBalanced == 0) return;
  if (text != "" && (text[length - 1].isDigit() || text[length - 1] == 'x') &&
      str == "(" && text != "0")
    return;
  if (text != "" && text[length - 1] == ')' && str == "(") return;

  if (text == "0" && str == "e") return;
  if (text != "" && text[length - 1].isDigit() && str == "x" && text != "0")
    return;
  if (text != "" && str == "e" && !text[length - 1].isDigit()) return;
  if (text != "" && text[length - 1] == 'x' && str == "x") return;

  if (text != "" && str == "." && (!text[length - 1].isDigit() || pointsError))
    return;
  if (text != "" && text[length - 1] == '.' && !str[0].isDigit()) return;
  if (!pointsError && str == "." && text != "") {
    int i = length - 1;
    for (; i > 0 && text[i].isDigit(); i--)
      ;
    if (text[i] == '.') return;
  }

  for (const QString &item : vector_func) {
    if (item == str) {
      if (text == "0")
        ;
      else if (text == "")
        ;
      else if (text[length - 1] == 'x' || text[length - 1].isDigit())
        return;
      isBracketsBalanced++;
    }
  }

  bool bracketsError = false;
  if (text != "") bracketsError = text[length - 1] == ')' ? true : false;
  for (int i = array_oper.length() - 1; i >= 0; i--) {
    if (array_oper[i] == str[0]) {
      for (int j = array_oper.length() - 1; j >= 0; j--) {
        if (text != "" && text[length - 1] == array_oper[j]) return;
      }
      if (text != "" && text[length - 1] == '(' && str != "+" && str != "−")
        return;
      if (text == "" && str != "+" && str != "-") return;
      if (text == "0") str = "0" + str;
      if (pointsError) pointsError = false;
      if (exponentialError) exponentialError = false;
      bracketsError = false;
    }
  }
  if (bracketsError && str != ")") return;

  if (exponentialError && !str[0].isDigit()) return;

  if (text != "" && text[length - 1] == '(' && str == ")") {
    str = "0" + str;
    isBracketsBalanced--;
  }

  if (str == ")") isBracketsBalanced--;
  if (str == "(") isBracketsBalanced++;
  if (str == ".") pointsError = true;
  if (str == "." && text == "0") str = "0" + str;
  if (text == "0") display->setText("");
  display->setText(display->text() + str);
}

void MainVeiw::onButtonDel() {
  QString text = display->text();
  if (text == "") return;
  int length = text.length();
  if (text[length - 1] == '(') isBracketsBalanced--;
  if (text[length - 1] == ')') isBracketsBalanced++;
  if (text[length - 1] == '.' && pointsError) pointsError = false;
  if (text[length - 1] == 'e') exponentialError = false;
  text.chop(1);
  display->setText(text);
}

void MainVeiw::onButtonEqually() {
  QString expression = display->text();
  if (exponentialError || pointsError || isBracketsBalanced != 0) return;
  if (expression == "(" || expression == "") return;

  if (expression.toStdString().find('x') != std::string::npos) {
    MyDialog dialog(this);
    dialog.setModal(true);
    dialog.exec();
  }
  if (buildingСhart) {
    buildingСhart = false;
    BuildChart();
    centralWidget->setCurrentIndex(1);
    // Добавление действий в стек
    QUndoCommand *myCommand =
        new MyCommand(display, display->text(), display->text());
    undoStack->push(myCommand);
  } else {
    QString result = controller->GetResult(expression, value_x);
    value_x = 0.0;
    if (controller->GetErrorType() == s21::OK) {
      isBracketsBalanced = 0;
      pointsError = false;
      exponentialError = false;

      // Добавление действий в стек
      QUndoCommand *myCommand = new MyCommand(display, display->text(), result);
      undoStack->push(myCommand);

      display->setText(result);
    }
  }
}

void MainVeiw::onAreaXAction() {
  XAreaDialog dialog(this);
  dialog.setModal(true);
  dialog.exec();
  chartView->xAxis->setRange(-areaX, areaX);
  step = areaX * 2 / 1000.0;
  XAction->setText("Область определения:  ±" + QString::number(areaX));
  StepAction->setText("Шаг:                          " +
                      QString::number(step, 'f', 5));
  BuildChart();
}

void MainVeiw::onAreaYAction() {
  YAreaDialog dialog(this);
  dialog.setModal(true);
  dialog.exec();
  chartView->yAxis->setRange(-areaY, areaY);
  YAction->setText("Область значения:        ±" + QString::number(areaY));
  BuildChart();
}

void MainVeiw::onButtonCredit() {
  double amountCredit = 0.0;
  double period_in = 0.0;
  double interestRate = 0.0;
  bool okAmount = false;
  bool okPeriod = false;
  bool okInterest = false;
  type_credit =
      (AnnuityPaymentBut->isChecked() ? s21::Controller::annuity_payment
                                      : s21::Controller::different_payment);
  amountCredit = amountEdit->text().toDouble(&okAmount);
  if (okAmount && amountCredit <= 999999999999.0 && amountCredit > 0) {
    okAmount = true;
  } else {
    okAmount = false;
    amountEdit->setStyleSheet("border: 2px solid #ED031D;");
  }
  period_in = periodEdit->text().toDouble(&okPeriod);
  if (okPeriod &&
      (period == s21::Controller::year ? period_in * 12 : period_in) <= 600 &&
      period_in > 0) {
    okPeriod = true;
  } else {
    okPeriod = false;
    periodEdit->setStyleSheet("border: 2px solid #ED031D;");
  }
  interestRate = interestEdit->text().toDouble(&okInterest);
  if (okInterest && interestRate <= 999 && interestRate > 0) {
    okInterest = true;
  } else {
    okInterest = false;
    interestEdit->setStyleSheet("border: 2px solid #ED031D;");
  }
  if (okInterest && okPeriod && okAmount) {
    controller->CalcCredit(type_credit, period, amountCredit, period_in,
                           interestRate);
    if (type_credit == s21::Controller::annuity_payment) {
      lablePayment->setText("Ежемесячный платеж: " +
                            controller->GetAnnuityPayment());
      lableOverpayment->setText("Начисленные проценты: " +
                                controller->GetAnnuityOverpament());
      lableTotalAmount->setText("Долг + проценты: " +
                                controller->GetAnnuityTotalAmount());
    } else {
      lablePayment->setText(
          "Ежемесячный платеж: " + controller->GetFirstDifferentPayments() +
          " .. " + controller->GetLastDifferentPayments());
      lableOverpayment->setText("Начисленные проценты: " +
                                controller->GetDiffOverpayment());
      lableTotalAmount->setText("Долг + проценты: " +
                                controller->GetDiffTotalAmount());
    }
  }
}

MainVeiw::~MainVeiw() { delete ui; }
