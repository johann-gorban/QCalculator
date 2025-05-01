#include "tokens.hpp"

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void Token::set_name(const std::string &name) {
    this->name = name;
}

const std::string &Token::get_name() const {
    return this->name;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

Operator::Operator() {};

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

OperatorAddition::OperatorAddition() {
    this->set_name("ADD");
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(2);
}

OperatorSubstraction::OperatorSubstraction() {
    this->set_name("SUB");
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(2);
}

OperatorMultiplication::OperatorMultiplication() {
    this->set_name("MUL");
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(3);
}

OperatorDivision::OperatorDivision() {
    this->set_name("DIV");
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(3);
}

OperatorPower::OperatorPower() {
    this->set_name("POW");
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(5);
}

OperatorMinus::OperatorMinus() {
    this->set_name("MIN");
    this->set_associativity(OperatorAssociativity::RIGHT);
    this->set_precedance(6);
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

Number::Number(const double value) : value(value) {
    this->set_name(std::to_string(value));
};

double Number::get_value() const {
    return this->value;
}