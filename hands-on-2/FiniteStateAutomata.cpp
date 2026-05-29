#include "FiniteStateAutomata.hpp"
#include <cctype>

FiniteStateAutomata::FiniteStateAutomata(RegularExpression* expr) {
    initialState = 12;
    acceptState = -1; // Multiple accept states: 19, 20, 21
    currentState = initialState;
    expression = expr;
}

FiniteStateAutomata::~FiniteStateAutomata() {
    delete expression;
    expression = nullptr;
}

void FiniteStateAutomata::reset() {
    currentState = initialState;
}

bool FiniteStateAutomata::transition(char symbol) {
    bool isDigit = std::isdigit(static_cast<unsigned char>(symbol)) != 0;
    bool isDot = (symbol == '.');
    bool isE = (symbol == 'E' || symbol == 'e');
    bool isSign = (symbol == '+' || symbol == '-');
    
    switch (currentState) {
        case 12: // Start state
            if (isDigit) {
                currentState = 13;
                return true;
            } else if (isDot) {
                currentState = 14;
                return true;
            } else {
                currentState = 20; // Other -> reject state
                return true;
            }
            
        case 13: // After first digit
            if (isDigit) {
                currentState = 13; // Stay in state 13
                return true;
            } else if (isDot) {
                currentState = 14;
                return true;
            } else if (isE) {
                currentState = 16;
                return true;
            } else {
                currentState = 20; // Other -> reject state
                return true;
            }
            
        case 14: // After dot
            if (isDigit) {
                currentState = 15;
                return true;
            } else {
                currentState = 21; // E or other -> reject state
                return true;
            }
            
        case 15: // After dot and digit
            if (isDigit) {
                currentState = 15; // Stay in state 15
                return true;
            } else if (isE) {
                currentState = 16;
                return true;
            } else {
                currentState = 21; // Other -> reject state
                return true;
            }
            
        case 16: // After E
            if (isSign) {
                currentState = 17;
                return true;
            } else if (isDigit) {
                currentState = 18;
                return true;
            } else {
                currentState = 21; // Other -> reject state
                return true;
            }
            
        case 17: // After E and sign
            if (isDigit) {
                currentState = 18;
                return true;
            } else {
                currentState = 19; // Other -> reject state
                return true;
            }
            
        case 18: // After E and digit
            if (isDigit) {
                currentState = 18; // Stay in state 18
                return true;
            } else {
                currentState = 19; // Other -> reject state
                return true;
            }
            
        case 19: // Reject state (after valid number with other char)
        case 20: // Reject state (other from start/digit)
        case 21: // Reject state (other from decimal)
            return true; // Stay in reject state
            
        default:
            return false;
    }
}

bool FiniteStateAutomata::process(const std::string& input) {
    reset();

    if (input.empty()) {
        return false;
    }

    for (size_t i = 0; i < input.length(); i++) {
        if (!transition(input[i])) {
            return false;
        }
    }

    return isAcceptingState();
}

bool FiniteStateAutomata::isAcceptingState() const {
    // Accept states are 13 (after digits), 15 (after decimal and digits), and 18 (after exponent and digits)
    // States 19, 20, and 21 are reject states (marked with * in diagram)
    return (currentState == 13 || currentState == 15 || currentState == 18);
}

int FiniteStateAutomata::getCurrentState() const {
    return currentState;
}
