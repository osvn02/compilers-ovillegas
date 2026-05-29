#include "LexicalAnalyzer.hpp"
#include <cctype>
#include <sstream>

LexicalAnalyzer::LexicalAnalyzer() 
{
    // Initialize keywords (reserved words)
    keywords.push_back("START");
    keywords.push_back("STOP");
    keywords.push_back("ADD");
    keywords.push_back("SUSTR");
    keywords.push_back("MULT");
    keywords.push_back("DIV");
    keywords.push_back("MOV");
    keywords.push_back("MOVE");
    keywords.push_back("STORE");
    keywords.push_back("STO");
    
    // Initialize delimiters
    delimiters.push_back(',');
    delimiters.push_back(';');
    delimiters.push_back(' ');
    delimiters.push_back('\t');
    delimiters.push_back('\n');
}

bool LexicalAnalyzer::isKeyword(string word) 
{
    for (size_t i = 0; i < keywords.size(); i++) {
        if (keywords[i] == word) {
            return true;
        }
    }
    return false;
}

bool LexicalAnalyzer::isDelimiter(char ch) 
{
    for (size_t i = 0; i < delimiters.size(); i++) {
        if (delimiters[i] == ch) {
            return true;
        }
    }
    return false;
}

bool LexicalAnalyzer::isDigit(char ch) 
{
    return ch >= '0' && ch <= '9';
}

bool LexicalAnalyzer::isIdentifier(string word) 
{
    if (word.empty()) return false;
    
    // Check if first character is a letter
    if (!isalpha(word[0])) return false;
    
    // Check remaining characters are alphanumeric
    for (size_t i = 1; i < word.length(); i++) {
        if (!isalnum(word[i])) return false;
    }
    
    return true;
}

vector<Token> LexicalAnalyzer::tokenize(string input) 
{
    vector<Token> tokens;
    string currentToken = "";
    
    for (size_t i = 0; i < input.length(); i++) {
        char ch = input[i];
        
        if (isDelimiter(ch)) {
            if (!currentToken.empty()) {
                Token token;
                token.value = currentToken;
                
                // Determine token type
                if (isKeyword(currentToken)) {
                    token.type = KEYWORD;
                } else if (isIdentifier(currentToken)) {
                    token.type = IDENTIFIER;
                } else {
                    bool allDigits = true;
                    for (size_t j = 0; j < currentToken.length(); j++) {
                        if (!isDigit(currentToken[j]) && currentToken[j] != '-') {
                            allDigits = false;
                            break;
                        }
                    }
                    token.type = allDigits ? DIGIT : UNKNOWN;
                }
                
                tokens.push_back(token);
                currentToken = "";
            }
            
            // Add delimiter as token if it's not a space
            if (ch != ' ' && ch != '\t' && ch != '\n') {
                Token delimToken;
                delimToken.value = string(1, ch);
                delimToken.type = DELIMITER;
                tokens.push_back(delimToken);
            }
        } else {
            currentToken += ch;
        }
    }
    
    // Add last token if exists
    if (!currentToken.empty()) {
        Token token;
        token.value = currentToken;
        
        if (isKeyword(currentToken)) {
            token.type = KEYWORD;
        } else if (isIdentifier(currentToken)) {
            token.type = IDENTIFIER;
        } else {
            bool allDigits = true;
            for (size_t j = 0; j < currentToken.length(); j++) {
                if (!isDigit(currentToken[j]) && currentToken[j] != '-') {
                    allDigits = false;
                    break;
                }
            }
            token.type = allDigits ? DIGIT : UNKNOWN;
        }
        
        tokens.push_back(token);
    }
    
    return tokens;
}

void LexicalAnalyzer::displayTokens(vector<Token> tokens) 
{
    cout << "\n=== LEXICAL ANALYSIS ===" << endl;
    cout << "Token\t\tType" << endl;
    cout << "------------------------" << endl;
    
    for (size_t i = 0; i < tokens.size(); i++) {
        cout << tokens[i].value << "\t\t";
        
        switch (tokens[i].type) {
            case KEYWORD:
                cout << "KEYWORD";
                break;
            case IDENTIFIER:
                cout << "IDENTIFIER";
                break;
            case DIGIT:
                cout << "DIGIT";
                break;
            case DELIMITER:
                cout << "DELIMITER";
                break;
            case UNKNOWN:
                cout << "UNKNOWN";
                break;
        }
        cout << endl;
    }
    cout << "========================\n" << endl;
}

bool LexicalAnalyzer::validateInstruction(string instruction) 
{
    vector<Token> tokens = tokenize(instruction);
    
    if (tokens.empty()) return false;
    
    // First token should be a keyword
    if (tokens[0].type != KEYWORD) {
        cout << "Error: Instruction must start with a keyword" << endl;
        return false;
    }
    
    // Check for unknown tokens
    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == UNKNOWN) {
            cout << "Error: Unknown token '" << tokens[i].value << "'" << endl;
            return false;
        }
    }
    
    return true;
}

