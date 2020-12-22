#include <iostream>
#include "Token.h"
using namespace std;
Token::Token() {
 priority = -1;
 token = "";
 type = INVALID;
}
Token::Token(string s) {
  set(s);
}
void Token::set(string s){
 priority = -1;
 token = s;
// int tok = stoi(token,nullptr,10);
 int numints = 0;
 int numstrs = 0;
 int somethingelse = 0;
 if(s == "(")
 {
     type = OpenBrace;
 }
  if(s == ")")
 {
     type = CloseBrace;
 }
 if(s =="-" || s =="+" || s =="*" || s== "/") {
     type = OP;
 }
  if(s == "=") {
  type = EQ;
  }
 for(int i = 0; s[i] != '\0'; i++)
 {
     if(s[i] != '_'){
     if(isalpha(s[i]))
     {
         numstrs++;
     }
     else if(isdigit(s[i])){
         numints ++;
     }
     else {somethingelse ++;
     }
   }
 }
 if(numstrs != 0 || numints !=0){
     if((isalpha(s[0]) || s[0] == '_') && somethingelse == 0)
     {
     type = ID;
     }
     else if(numstrs == 0 && somethingelse == 0)
    {
        if(numints > 1 && s[0] == '0')
        {
            type = INVALID;
        }
        else{
     type = INT;
        }
    }
    else{
        type = INVALID;
    }
   }
  }
int Token::value() const {
    if(type == ID)
    {
        return -1;
    }
    if(type == INT)
    {
        int li1;
        li1 = stoi (token,nullptr,10);
        return li1;
    }
    else{
        return -2;
    }
    
}
void Token::display() const {
    if(type == INVALID){
    cout << "type = INVALID" << endl;
    }
    if(type == ID){
    cout << "type = ID" << endl; 
    }
    if(type == OP){
    cout << "type = OP" << endl; 
    }
    if(type == INT){
    cout << "type = INT" << endl; 
    }
    if(type == EQ){
    cout << "type = EQ" << endl; 
    }
    if(type == OpenBrace){
    cout << "type = OpenBrace" << endl; 
    }
    if(type == CloseBrace){
    cout << "type = CloseBrace" << endl; 
    }
    cout << "token = " << token << endl;
    cout << "priority = " << priority << endl;
}
Token_type Token::get_type() const{
    return type;
}
string Token::get_token() const{
    return token;
}
int Token::get_priority() const{
    return priority;
}

