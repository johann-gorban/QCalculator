#include "output_line.hpp"

OutputLine::OutputLine(const QString &text) : QLineEdit(text) {

}

bool OutputLine::is_answer() const {
    return this->_is_answer;
}

void OutputLine::set_answer(bool is_answer) {
    this->_is_answer = is_answer;
}