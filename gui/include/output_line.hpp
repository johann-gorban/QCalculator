#pragma once

#include <QWidget>
#include <QLineEdit>

class OutputLine : public QWidget {
    Q_OBJECT
private:
    QLineEdit *_output_line;
    bool _is_answer = true;
public: 
    OutputLine(QWidget *parent = nullptr);

    bool is_answer() const;
public slots:
    void set_answer(const QString &text);

    void set_text(const QString &text);
};