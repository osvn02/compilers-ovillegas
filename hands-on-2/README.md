# Finite State Automata (FSA)

This project implements Deterministic Finite State Automata in C++ using Object-Oriented Programming principles.

## Author Information

**Name**: Octavio Salvador Villegas Navarro  
**Email**: octavio.villegas7760@alumnos.udg.mx
**Student ID**: 221977608
**Course**: Compilers 

## Numeric Pattern Validation

### Overview

Implementation of a Finite State Automaton that validates **unsigned numeric literals** according to the transition diagram from slide 13 of the "Regular Expressions" presentation.

### Supported Number Formats

The FSA accepts the following numeric formats:

1. **Integer numbers**: `123`, `456`, `0`
2. **Decimal numbers**: `123.456`, `.5`, `0.123`, `9.99`
3. **Scientific notation**:
   - With positive exponent: `1.23E+5`, `5.67E+2`
   - With negative exponent: `1E-3`
   - Without sign: `123E10`

### State Diagram Implementation

The FSA implements states 12-21 from the transition diagram:

- **State 12**: Initial state (start)
- **State 13**: After digit(s) - **ACCEPT STATE**
- **State 14**: After decimal point
- **State 15**: After decimal point and digit(s) - **ACCEPT STATE**
- **State 16**: After 'E' (exponent marker)
- **State 17**: After 'E' and sign (+/-)
- **State 18**: After exponent digit(s) - **ACCEPT STATE**
- **State 19**: Reject state (other character after valid number)
- **State 20**: Reject state (other character from start/digit)
- **State 21**: Reject state (other character from decimal)

### How to Compile and Run

#### Compile the main program:
```
g++ -std=c++11 -o automaton main.cpp FiniteStateAutomata.cpp NumericExpression.cpp AlphabeticExpression.cpp Pattern.cpp RegularExpression.cpp

./automaton
```


### Usage Example

When running the main program:
```
==========================================
 Deterministic Finite State Automata (FSA)
 1. Validate alphabetic string [A-Za-z]+
 2. Validate numeric string [0-9]+
 3. Exit
==========================================
Choose an option: 2
Enter a numeric string: 123.45E+6
Result: ACCEPTED
Final state: q18
```

### Test Results

All test cases pass successfully:

**Valid Inputs (ACCEPTED):**
- `123`, `456`, `0` - integers
- `123.456`, `.5`, `0.123`, `9.99` - decimals
- `1.23E+5`, `1E-3`, `123E10`, `5.67E+2` - scientific notation

**Invalid Inputs (REJECTED):**
- `abc` - alphabetic characters
- `12.34.56` - multiple decimal points
- `E5` - starting with E
- `12E`, `12E+` - incomplete exponent
- `.E5` - decimal point followed by E without digits
- `12+34` - sign in wrong position
- Empty string, `.`, `E` - incomplete numbers

