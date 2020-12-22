#include <iostream>
#include "Expression.h"
#include <vector>
#include <string.h>
using namespace std;
Expression::Expression()
{
    original = "";
    tokenized.clear();
    postfix.clear();
    valid = false;
    type = ILLEGAL;
}

   Expression::Expression(const string& s){
        set(s);
    }
    
    void Expression::set(const string& s) {
    original = s;
    tokenized.clear();
    string temp;
    Token tok;
    char cur;
    bool keepgoing = false;
    int start = 0;
    int len = original.length();
    for (int i = 0; i < len; i++) {
        cur = original.at(i);
        if(cur != ' '){
        if (cur == '+' || cur == '=' || cur == '-' || cur == '(' || cur == ')' || cur == '*' || cur == '/')
        {
            if (keepgoing)
            {
                tok.set(original.substr(start, i - start));
                tokenized.push_back(tok);
                keepgoing = false;
            }
            temp = cur;
            tok.set(temp);
            tokenized.push_back(tok);
            keepgoing = false;
         }
          else if (!keepgoing)
             {
            keepgoing = true;
            start = i;
            }
        }
    else if (keepgoing) {
    tok.set(original.substr(start, i - start));
    tokenized.push_back(tok);
    keepgoing = false;
    }
  }// end of for loop
  if(keepgoing) {
    tok.set(original.substr(start, len - start));
    tokenized.push_back(tok);
    keepgoing = false;
      
  }
  postfix.clear();
  valid = false;
  type = ILLEGAL;
}
       void Expression::display() const{
           cout << "original = " << original << endl;
           cout << "tokenized = ";
           for(int i = 0 ; i < tokenized.size() ; i++)
           cout << tokenized.at(i).get_token() << ";";
           cout << endl;
           cout << "number of tokens = " << tokenized.size() << endl;
           cout << "postfix = " <<endl;
            cout << "type = Illegal" << endl;
           }
          
   /*
    // Methods
    void display() const;
    // getters 
    string get_original() const;
    vector <Token> get_tokenized() const; */