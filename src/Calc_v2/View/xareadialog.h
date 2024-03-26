#ifndef VIEW_XAREADIALOG_H
#define VIEW_XAREADIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

#include "mainveiw.h"

class XAreaDialog : public QDialog {
  Q_OBJECT
 public:
  XAreaDialog(MainVeiw *mainV, QWidget *parent = nullptr)
      : QDialog(parent), mainView(mainV) {
    this->resize(280, 70);
    this->setMinimumSize(280, 70);
    this->setMaximumSize(280, 70);

    QHBoxLayout *layout = new QHBoxLayout(this);
    lEdit = new QLineEdit();
    lEdit->setPlaceholderText("Введите область определения функции");
    lEdit->setStyleSheet("QLineEdit::placeholder { color: red; }");
    layout->addWidget(lEdit);

    connect(lEdit, &QLineEdit::returnPressed, this,
            &XAreaDialog::onXAreaEnterClicked);
    connect(lEdit, &QLineEdit::textChanged, this,
            [this] { lEdit->setStyleSheet("border: 2px solid #31CC24 ;"); });
  }
  void onXAreaEnterClicked() {
    bool ok = false;
    mainView->areaX = lEdit->text().toDouble(&ok);
    if (ok && mainView->areaX <= 1000000 && mainView->areaX > 0) {
      this->close();
    } else {
      lEdit->setStyleSheet("border: 2px solid #ED031D;");
    }
  }

 private:
  MainVeiw *mainView{};
  QLineEdit *lEdit{};
};

#endif  // VIEW_XAREADIALOG_H
