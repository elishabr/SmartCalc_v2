#ifndef VIEW_MYCOMMAND_H
#define VIEW_MYCOMMAND_H

#include <QLabel>
#include <QUndoCommand>

// Определение класса MyCommand, который наследуется от QUndoCommand
class MyCommand : public QUndoCommand {
 public:
  MyCommand(QLabel *label, const QString &oldText, const QString &newText,
            QUndoCommand *parent = 0)
      : QUndoCommand(parent),
        myLabel(label),
        myOldText(oldText),
        myNewText(newText) {}

  // Переопределение метода undo
  void undo() override {
    myLabel->setText(myOldText);
    setText(myOldText + " = ");
  }

  // Переопределение метода redo
  void redo() override {
    myLabel->setText(myNewText);
    setText(myNewText);
  }

 private:
  QLabel *myLabel;
  QString myOldText;
  QString myNewText;
};

#endif  // VIEW_MYCOMMAND_H
