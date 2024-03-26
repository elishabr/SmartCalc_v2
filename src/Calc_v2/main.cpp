#include <QApplication>

#include "View/mainveiw.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  a.setWindowIcon(QIcon(":/calculator.ico"));
  QFile fileStyles(":/styles.css");
  fileStyles.open(QFile::ReadOnly);
  a.setStyleSheet(fileStyles.readAll());

  s21::Model model_calc;
  s21::Credit model_credit;
  s21::Controller controller(&model_calc, &model_credit);
  MainVeiw w(&controller);
  w.setWindowTitle("");
  w.show();
  return a.exec();
}
