#include "tokens.hpp"

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

Token::Token(const std::string &name) {
    this->name = name;
}

const std::string &Token::get_name() const {
    return this->name;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

Operator::Operator(const std::string &name) : Token(name) {};

unsigned int Operator::get_precedance() const {
    return this->precedance;
}

OperatorAssociativity Operator::get_associativity() const {
    return this->associativity;
}

void Operator::set_associativity(OperatorAssociativity associativity) {
    this->associativity = associativity;
}

void Operator::set_precedance(unsigned int precedance) {
    this->precedance = precedance;
}

//////////////////////////////////////////////////////////////////////////////////////////

OperatorAddition::OperatorAddition() : Operator("ADD") {
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(2);
}

OperatorSubstraction::OperatorSubstraction() : Operator("SUB") {
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(2);
}

OperatorMultiplication::OperatorMultiplication() : Operator("MUL") {
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(3);
}

OperatorDivision::OperatorDivision() : Operator("DIV") {
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(3);
}

OperatorPower::OperatorPower() : Operator("POW") {
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(5);
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

Number::Number(const double value) : Token("NUMBER"), value(value) {};

double Number::get_value() const {
    return this->value;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

LeftParanthesis::LeftParanthesis() : Token("LEFT_PARANTHESIS") {}

RightParanthesis::RightParanthesis() : Token("RIGHT_PARANTHESIS") {}