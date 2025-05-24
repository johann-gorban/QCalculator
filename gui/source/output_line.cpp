#include "output_line.hpp"

#include <QVBoxLayout>

OutputLine::OutputLine(QWidget *parent) : QWidget(parent) {
    this->_is_answer = true;

    this->_output_line = new QLineEdit("0", this);
    this->_output_line->setReadOnly(true);   
    this->_output_line->setAlignment(Qt::AlignRight);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(this->_output_line);
    layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(layout);
}

bool OutputLine::is_answer() const {
    return this->_is_answer;
}

void OutputLine::clear() {
    this->_output_line->clear();
}

void OutputLine::set_answer(const QString &text) {
    this->_output_line->setText(text);
    this->_is_answer = true;
}

void OutputLine::insert(const QString &text) {
    // If answer, clear ouput and set text
    if (this->_is_answer) {
        this->_output_line->clear();
        this->_is_answer = false;
    }

    this->_output_line->insert(text);
}

void OutputLine::insert_function(const QString &text) {
    // Insert function and parenthesis
    this->insert(text + "()");

    // Set cursor one character left
    this->_output_line->setCursorPosition(this->_output_line->text().length() - 1);
}