#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Token{
public:
    char kind;
    double value;
    Token(char sign)
    :kind(sign), value(0){}
    Token(char sign, double number)
    :kind(sign), value(number){}
};

class Token_stream{
public:
    Token_stream();
    Token get();
    void putback(Token);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream()
:full(false), buffer(0){};

void Token_stream::putback(Token t)
{
    if(full)throw(t);
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if(full)
        {
            full = false;
            return buffer;
        }
    char sign;
    cin >> sign;
    switch(sign){
    case 'x': // Quit
    case '=': // Print
    case '(': case ')': case '+': case '*': case '/': case '-': case '{': case '}':
        return Token(sign);
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(sign);
        double val;
        cin >> val;
        return Token('8', val);
    }
default:
    throw(sign);
 }
}

Token_stream ts;

double expression();

double term();

double primary();

double expression()
{
    double left = term();
    Token t = ts.get();
    while(true){
        switch(t.kind){
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();
    while(true){
        switch(t.kind){
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
                double d = primary();
                if(d==0) throw(d); //throw a double, zero. Don't divide by zero.
                left /= d;
                t = ts.get();
                break;
            }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double primary()
{
    Token t = ts.get();
    switch(t.kind){
    case '{':
        {
            double c = expression();
            t = ts.get();
            if(t.kind!='}')throw(t);
            return c;
        }
    case '(':
        {
            double d = expression();
            t = ts.get();
            if(t.kind!=')') throw(t); // Throw t!=')'. Is not a expression.
            return d;
        }
    case '8':
        return t.value;
    default:
        throw(t.kind); // Error: primary expected.
    }
}

int main()
try
{

    cout << "Welcome to our simple calculator.\n"
            "Please enter expression using floating-point numbers.\n"
            "Operators available: +, -, *, (, ), {, } and /.\n"
            "To print the evaluation on the screen enter =.\n"
            "To quit enter the letter q.\n";
    double val = 0;
    while(cin){
        Token t = ts.get();

        if(t.kind=='x')break;
        if(t.kind == '=')
            cout << "=" << val << '\n';
        else
         ts.putback(t);

        val = expression();
    }
}

catch(char myNum){
    if(myNum=='q')
        cout << "By by!" << endl;
    else
        cout << "Error. Bad Token: " << myNum <<  '\n';
}
