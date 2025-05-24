#include "OutputLine.hpp"

#include <QVBoxLayout>

OutputLine::OutputLine(QWidget *parent) : QWidget(parent) {
    this->isAnswerFlag = true;

    this->outputDisplay = new QLineEdit("0", this);
    this->outputDisplay->setReadOnly(true);   
    this->outputDisplay->setAlignment(Qt::AlignRight);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(this->outputDisplay);
    layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(layout);
}

bool OutputLine::isAnswer() const {
    return this->isAnswerFlag;
}

const QString OutputLine::getContent() const {
    return this->outputDisplay->text();
}

void OutputLine::clear() {
    this->setAnswer("0");
}

void OutputLine::backspace() {
    this->outputDisplay->backspace();
}

void OutputLine::setAnswer(const QString &text) {
    this->outputDisplay->setText(text);
    this->isAnswerFlag = true;
}

void OutputLine::insert(const QString &text) {
    // If answer, clear ouput and set text
    if (this->isAnswerFlag) {
        this->outputDisplay->clear();
        this->isAnswerFlag = false;
    }

    this->outputDisplay->insert(text);
}

void OutputLine::insertFunction(const QString &text) {
    // Insert function and parenthesis
    this->insert(text + "()");

    // Set cursor one character left
    this->outputDisplay->setCursorPosition(this->outputDisplay->text().length() - 1);
}