#include "facade.hpp"

#include "tokenization/tokens.hpp"
#include "tokenization/tokenizer.hpp"

#include "parsing/parser.hpp"
#include "parsing/extended_tokens.hpp"

#include "sorting/sorter.hpp"
#include "translating/translator.hpp"
#include "computation/calculator.hpp"


const std::string Facade::calculate(const std::string &expression) {
    std::string result;

    static Tokenizer tokenizer;
    static Parser parser;
    static Sorter sorter;
    static Translator translator;
    static Calculator calculator;
    try {
        std::vector<token_ptr> tokens = tokenizer.tokenize(expression);
        std::vector<token_ptr> extended_tokens = parser.parse(tokens);
        std::vector<token_ptr> sorted_tokens = sorter.rpn_sort(extended_tokens);
        std::vector<command_ptr> commands = translator.translate_tokens(sorted_tokens);

        result = std::to_string(calculator.calculate(commands));
    }
    catch (std::exception &error) {
        result = error.what();
    }
    
    return result;
}