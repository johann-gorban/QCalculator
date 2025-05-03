#include "tokens.hpp"

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

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
    this->name = "ADD";
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(2);
}

OperatorSubstraction::OperatorSubstraction() {
    this->name = "SUB";
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(2);
}

OperatorMultiplication::OperatorMultiplication() {
    this->name = "MUL";
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(3);
}

OperatorDivision::OperatorDivision() {
    this->name = "DIV";
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(3);
}

OperatorPower::OperatorPower() {
    this->name = "POW";
    this->set_associativity(OperatorAssociativity::LEFT);
    this->set_precedance(5);
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

Number::Number(const double value) : value(value) {
    this->name = "NUMBER";
};

double Number::get_value() const {
    return this->value;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

LeftParanthesis::LeftParanthesis() {
    this->name = "LEFT_PARANTHESIS";
}

RightParanthesis::RightParanthesis() {
    this->name = "RIGHT_PARANTHESIS";
}