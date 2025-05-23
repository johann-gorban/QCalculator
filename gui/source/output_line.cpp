#include "output_line.hpp"

OutputLine::OutputLine(QWidget *parent) : QWidget(parent) {
    this->_is_answer = true;

    this->output_line = new QLineEdit("0", this);
    this->output_line->setReadOnly(true);   
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(this->output_line);
    layout->setContentMargins(0, 0, 0, 0);
    this->setLayout(layout);
}

bool OutputLine::is_answer() const {
    return this->_is_answer;
}

void OutputLine::set_answer(const QString &text) {
    this->output_line->setText(text);
    this->_is_answer = true;
}

void OutputLine::set_text(const QString &text) {
    this->output_line->setText(text);
    this->_is_answer = false;
}