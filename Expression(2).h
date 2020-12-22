#ifndef Expression_H
#define Expression_H
#include <vector>
#include <iostream>
#include "Token.h"
using namespace std;
enum Exp_type {ASSIGNMENT, ARITHMETIC, ILLEGAL};
class Expression
{
public:
// constructors 
    
    Expression();
    Expression(const string& s);
   
    // Methods
    void set(const string& s);
    void display() const;
    // getters 
    string get_original() const;
    vector<Token> get_tokenized() const;
    private:
    //data members
    string original;
    vector<Token> tokenized;
    vector<Token> postfix;
    bool valid;
    Exp_type type;
};
#endif