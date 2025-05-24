#pragma once

#include <QWidget>
#include <QLineEdit>

class OutputLine : public QWidget {
    Q_OBJECT
private:
    QLineEdit *outputDisplay;
    bool isAnswerFlag;
public: 
    explicit OutputLine(QWidget *parent = nullptr);

    bool isAnswer() const;

    const QString getContent() const;
public slots:
    void setAnswer(const QString &text);

    void backspace();

    void insert(const QString &text);

    void insertFunction(const QString &text);

    void clear();
};