#ifndef LEXICALANALYZER_HPP
#define LEXICALANALYZER_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum TokenType {
    KEYWORD,
    IDENTIFIER,
    DIGIT,
    DELIMITER,
    UNKNOWN
};

struct Token {
    string value;
    TokenType type;
};

class LexicalAnalyzer 
{
    private:
        vector<string> keywords;
        vector<char> delimiters;
        
        bool isKeyword(string word);
        bool isDelimiter(char ch);
        bool isDigit(char ch);
        bool isIdentifier(string word);
        
    public:
        LexicalAnalyzer();
        vector<Token> tokenize(string input);
        void displayTokens(vector<Token> tokens);
        bool validateInstruction(string instruction);
};

#endif


