#ifndef VIEW_CUSTOMBUTTON_H
#define VIEW_CUSTOMBUTTON_H

#include <QPushButton>

class CustomButton_menu : public QPushButton {
  Q_OBJECT
 public:
  explicit CustomButton_menu(const QString &text, int height,
                             QWidget *parent = nullptr)
      : QPushButton(text, parent) {
    this->setMaximumHeight(height);
    this->setMinimumHeight(height);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
  }
};

class CustomButton_right : public QPushButton {
  Q_OBJECT
 public:
  explicit CustomButton_right(const QString &text, int height,
                              QWidget *parent = nullptr)
      : QPushButton(text, parent) {
    this->setMaximumHeight(height);
    this->setMinimumHeight(height - 5);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
  }
};

class CustomButton : public QPushButton {
  Q_OBJECT
 public:
  explicit CustomButton(const QString &text, int height,
                        QWidget *parent = nullptr)
      : QPushButton(text, parent) {
    this->setMaximumHeight(height);
    this->setMinimumHeight(height - 5);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
  }
};

class ScopeButton : public QPushButton {
  Q_OBJECT
 public:
  explicit ScopeButton(const QString &text, int height,
                       QWidget *parent = nullptr)
      : QPushButton(text, parent) {
    this->setMaximumHeight(height);
    this->setMaximumWidth(height);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  }
};

class PeriodButton : public QPushButton {
  Q_OBJECT
 public:
  explicit PeriodButton(const QString &text, QWidget *parent = nullptr)
      : QPushButton(text, parent) {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  }
};

#endif  // VIEW_CUSTOMBUTTON_H
