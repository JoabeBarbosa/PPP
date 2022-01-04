#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Token{
public:
    Token(char);
    Token(char, char);
    void set_kind(char);
    void set_value(char);
    char get_kind();
    char get_value();
private:
    char kind;
    char value;
};

Token::Token(char c)
:kind(c), value(0){}

Token::Token(char c, char i)
:kind(c), value(i){}

void Token::set_kind(char c)
{
    kind = c;
}

void Token::set_value(char i)
{
    value = i;
}

char Token::get_kind()
{
    return kind;
}

char Token::get_value()
{
    return value;
}

Token get_token()
{
    char digit = ' ';
    cin >> digit;
    switch(digit){
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        return Token{'8', digit};
    case ';':
        return Token{';'};
    default:
        throw(digit);
    }
}

vector<int>digits;

void read()
{
    int i = 0;
    while(cin){
       Token digit = get_token();
       if(digit.get_kind()==';')break;
       i = digit.get_value()-'0';
       digits.push_back(i);
    }
}

vector<string>decimals;

void init()
{
    decimals.push_back("thousand");
    decimals.push_back("hundred");
    decimals.push_back("tens");
    decimals.push_back("ones");
}

void compose()
{
    for(int i=0, j=4-digits.size(); i<digits.size(); ++i, ++j){
        cout << digits[i] << " " << decimals[j] << " ";
    }
    cout << endl;
}

int main()
try
{
    cout << "Enter numbers: " << endl;
    init();
    while(cin){
        read();
        compose();
        digits.erase(digits.begin(), digits.end());
    }

}

catch(char myChar)
{
    cout << "Error! " << myChar << endl;
}
