#include "NumericExpression.hpp"
#include <cctype>

NumericExpression::NumericExpression(Pattern* p)
    : RegularExpression(p) {
}

NumericExpression::~NumericExpression() {
}

bool NumericExpression::isValid(const std::string& input) const {
    // Validation is now handled by the FSA state machine
    return true;
}

bool NumericExpression::isAcceptedSymbol(char symbol) const {
    // Accept digits, decimal point, E/e, and signs
    return std::isdigit(static_cast<unsigned char>(symbol)) != 0 ||
           symbol == '.' ||
           symbol == 'E' || symbol == 'e' ||
           symbol == '+' || symbol == '-';
}
