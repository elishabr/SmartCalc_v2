#ifndef VIEW_MYDIALOG_H
#define VIEW_MYDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLineEdit>

#include "View/custombutton.h"
#include "mainveiw.h"

class MyDialog : public QDialog {
  Q_OBJECT
 public:
  MyDialog(MainVeiw *mainV, QWidget *parent = nullptr)
      : QDialog(parent), mainView(mainV) {
    this->resize(280, 70);
    this->setMinimumSize(280, 70);
    this->setMaximumSize(280, 70);

    QHBoxLayout *layout = new QHBoxLayout(this);
    pButton = new CustomButton_menu("Chart", 30);
    lEdit = new QLineEdit();
    lEdit->setPlaceholderText("Введите x");
    layout->addWidget(lEdit);
    layout->addWidget(pButton);
    pButton->setAutoDefault(false);
    pButton->setDefault(false);

    connect(pButton, &QPushButton::clicked, this, &MyDialog::onButtonClicked);
    connect(lEdit, &QLineEdit::returnPressed, this, &MyDialog::onEnterClicked);
    connect(lEdit, &QLineEdit::textChanged, this,
            [this] { lEdit->setStyleSheet("border: 2px solid #31CC24 ;"); });
  }

  void onEnterClicked() {
    bool ok = false;
    mainView->value_x = lEdit->text().toDouble(&ok);
    if (ok) {
      mainView->buildingСhart = false;
      this->close();
    } else {
      lEdit->setStyleSheet("border: 2px solid #ED031D;");
    }
  }

  void onButtonClicked() {
    mainView->buildingСhart = true;
    this->close();
  }

 private:
  MainVeiw *mainView{};
  QLineEdit *lEdit{};
  QPushButton *pButton{};
};

#endif  // VIEW_MYDIALOG_H
