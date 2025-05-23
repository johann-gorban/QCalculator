#pragma once

#include <QLineEdit>

class OutputLine : public QLineEdit {
private:
    bool _is_answer = true;
public: 
    explicit OutputLine(const QString &text);

    bool is_answer() const;

    void set_answer(bool is_answer);
};