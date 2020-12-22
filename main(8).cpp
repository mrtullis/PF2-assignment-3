/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "Token.h"
#include "Expression.h"

int main()
{

     Expression ep;
     cout <<"testing the expression function" <<endl;
    string s1 = "a12 = 1?ab +  - a 0123 c (a + 12 3 ) *(ab - (3 + 4  ))";
    ep.set(s1);
    ep.display();
    s1 = "(2+3)*4";
        ep.set(s1);
    ep.display();
    s1 = " a23b+12cs-0023*123  ab123((0)";
            ep.set(s1);
    ep.display();
        s1 = "a";
     ep.set(s1);
    ep.display();
    cout << "testing the token function" << endl;
   Token tok;
    s1 = "b123";
    tok.set(s1);
    tok.display();
    s1 = "(Yube123!";
    tok.set(s1);
    tok.display();
    s1 = "_123";
    tok.set(s1);
    tok.display();
    s1 = "0123";
    tok.set(s1);
    tok.display();
    s1 = "_u_";
    tok.set(s1);
    tok.display();
    s1 = " abb";
    tok.set(s1);
    tok.display();
    s1 = "112()abc!";
    tok.set(s1);
    tok.display(); 

    return 0;
}
