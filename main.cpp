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
    int get_value();
private:
    char kind;
    int value;
};

Token::Token(char ch)
:kind(ch), value(0){}

Token::Token(char ch, int i)
:kind(ch), value(i){}

void Token::set_kind(char ch)
{
    kind = ch;
}

void Token::set_value(int i)
{
    value = i;
}

char Token::get_kind()
{
    return kind;
}

int Token::get_value()
{
    return value;
}

Token get_token()
{
    char ch = ' ';
    cin >> ch;
    switch(ch){
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            int i = 0;
            cin >> i;
            return Token{'8', i};
        }
    case 'c': case 'p': case 'q':
        return Token{ch};
    default:
        throw(ch);
    }
}

int factorial(int f)
{
    if(f==0||f==1)return 1;
    for(int i=f-1; i>0; --i)
        f*=i;
    return f;
}

int permutation(int n, int k)
{
    int p = factorial(n)/factorial(n-k);
    return p;
}

int combination(int n, int k)
{
    int c = permutation(n, k)/factorial(k);
    return c;
}

int main()
try
{
    cout << "Enter two positive integers 'n' and 'k' and choose 'p'(permutation) or 'c'(combination)."
            "\nEnter 'q' to quit.\n"
         << endl;
    while(cin){
        cout << "Enter 'n': ";
        Token n = get_token();
        if(n.get_kind()=='q')break;
        cout << "\nEnter 'k': ";
        Token k = get_token();
        if(k.get_kind()=='q')break;
        cout << "\nChoose 'p'(permutation) or 'c'(combination): ";
        Token choose = get_token();
        if(choose.get_kind()=='q')break;
        switch(choose.get_kind()){
        case 'p':
            cout << "\n=" << permutation(n.get_value(), k.get_value()) << endl;
            break;
        case 'c':
            cout << "\n=" << combination(n.get_value(), k.get_value()) << endl;
            break;
        default:
            throw(choose.get_kind());
        }
        cout << endl;
    }
}

catch(char myChar)
{
    cout << "\nException! " << "Bad input: " << myChar << endl;
}
