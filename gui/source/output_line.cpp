#include "output_line.hpp"

#include <QVBoxLayout>

OutputLine::OutputLine(QWidget *parent) : QWidget(parent) {
    this->_is_answer = true;

    this->_output_line = new QLineEdit("0", this);
    this->_output_line->setReadOnly(true);   
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(this->_output_line);
    layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(layout);
}

bool OutputLine::is_answer() const {
    return this->_is_answer;
}

void OutputLine::set_answer(const QString &text) {
    this->_output_line->setText(text);
    this->_is_answer = true;
}

void OutputLine::set_text(const QString &text) {
    if (this->_is_answer) {
        this->_output_line->clear();
        this->_is_answer = false;
    }

    this->_output_line->setText(text);
}