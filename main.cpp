#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Token{
public:
    Token(char);
    Token(char, int);
    void set_kind(char);
    void set_value(int);
    char get_kind();
    double get_value();
private:
    char kind;
    int value;
};

Token::Token(char sign)
:kind(sign), value(0){}

Token::Token(char sign, int number)
:kind(sign), value(number){}

void Token::set_kind(char sign)
{
    kind = sign;
}

void Token::set_value(int number)
{
    value = number;
}

char Token::get_kind()
{
    return kind;
}

double Token::get_value()
{
    return value;
}

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
:full(false), buffer(0){}

Token Token_stream::get()
{
    if(full){
        full = false;
        return buffer;
    }

    char kind = ' ';
    cin >> kind;
    switch(kind){
    case '|': case '^': case '&': case '!': case '~': case '(': case ')': case 'q': case ';':
        return Token(kind);
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(kind);
            int value;
            cin >> value;
            return Token('8', value);
        }
    default:
        throw(kind);
    }
}

void Token_stream::putback(Token t)
{
    if(full)throw(t);
    buffer = t;
    full = true;
}

int term();
int primary();
int unary();

Token_stream ts;

int expression()
{
    int left = term();
    Token t = ts.get();
    while(true){
        switch(t.get_kind()){
            case '|':
                left = left|term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
      }
    }

}

int term()
{
    int left = primary();
    Token t = ts.get();
    while(true){
        switch(t.get_kind()){
        case '^':
            left = left^primary();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int primary()
{
    int left = unary();
    Token t = ts.get();
    while(true){
        switch(t.get_kind()){
        case '&':
                left = left&unary();
                t = ts.get();
                break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int unary()
{
    Token t = ts.get();
    while(true){
        switch(t.get_kind()){
            case '(':
                   {
                       int left = expression();
                       t = ts.get();
                       if(t.get_kind()!=')')
                            throw(t.get_kind());
                       return left;
                   }

            case '~':
                {
                    t = ts.get();
                    if(t.get_kind()!='8')
                        throw(t.get_kind());
                    int left = t.get_value();
                    left = ~left;
                    return left;
                }
            case '!':
                {
                    t = ts.get();
                    if(t.get_kind()!='8')
                        throw(t.get_kind());
                    int left = !t.get_value();
                    return left;
                }
            case '8':
                return t.get_value();
        }
    }
}

int main()
try
{
    cout << "Enter a bitwise operation: "
            "\nEnter 'q' to quit."
         << endl;
    int result;
    while(cin){
        Token t = ts.get();
        if(t.get_kind()=='q') break;
        if(t.get_kind()==';')
            cout << "=" << result << endl;
        else
        {
            ts.putback(t);
            result = expression();
        }
    }
}

catch(char t){
    cout << "Error! " << t << endl;
}
