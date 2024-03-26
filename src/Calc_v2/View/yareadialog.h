#ifndef VIEW_YAREADIALOG_H
#define VIEW_YAREADIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

#include "mainveiw.h"

class YAreaDialog : public QDialog {
  Q_OBJECT
 public:
  YAreaDialog(MainVeiw *mainV, QWidget *parent = nullptr)
      : QDialog(parent), mainView(mainV) {
    this->resize(280, 70);
    this->setMinimumSize(280, 70);
    this->setMaximumSize(280, 70);

    QHBoxLayout *layout = new QHBoxLayout(this);
    lEdit = new QLineEdit();
    lEdit->setPlaceholderText("Введите область значения функции");
    layout->addWidget(lEdit);

    connect(lEdit, &QLineEdit::returnPressed, this,
            &YAreaDialog::onYAreaEnterClicked);
    connect(lEdit, &QLineEdit::textChanged, this,
            [this] { lEdit->setStyleSheet("border: 2px solid #31CC24 ;"); });
  }

  void onYAreaEnterClicked() {
    bool ok = false;
    mainView->areaY = lEdit->text().toDouble(&ok);
    if (ok && mainView->areaY <= 1000000 && mainView->areaY > 0) {
      mainView->buildingСhart = false;
      this->close();
    } else {
      lEdit->setStyleSheet("border: 2px solid #ED031D;");
    }
  }

 private:
  MainVeiw *mainView{};
  QLineEdit *lEdit{};
};

#endif  // VIEW_YAREADIALOG_H
