#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Token{
public:
    char kind;
    double value;
};

Token get_token() //WARN: Return only Token-types! Return the object (t1)! Do not return your members (t1.kind or t1.value).
{
    char sign;
    double number;
    Token t1;
    cin >> sign;
    switch(sign){
    case 'x': //"x" Terminates the loop.
        {
            t1.kind = sign;
            return t1;
        }
    case '+': case '-': case '*': case '/': case '(': case ')':
        {
            t1.kind = sign;
            return t1;
        }
    default: //Not a sign, so it's a number.
        {
            cin.putback(sign);
            cin >> number;
            t1.kind = '8';
            t1.value = number;
            return t1;
        }
    }

}

vector<Token>tok;

int main()
{
   cout << "Enter a number or operators: ";
   while(cin){
        Token t = get_token();
        if(t.kind=='x')//"x" Terminates the loop.
            break;
        tok.push_back(t);
    }
    cout << "Vector size: " << tok.size() << '\n';
    cout << "Each vector:\n";
    for(int i=0; i<tok.size(); ++i)
        cout << tok[i].kind << " " << tok[i].value << '\n';
}
