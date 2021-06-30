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
    default: //Not a signal, so it's a number.
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

Token evaluate(int initial_position)////Function: Evaluates and erase elements of vector, until remain one.
{
    Token perform {'8', 0};
    Token answer {'8', 0};
        for(int q=initial_position; q<tok.size(); ++q){
            switch(tok[q].kind){
            case '*':
                perform.value = tok[q-1].value*tok[q+1].value;
                tok.erase(tok.begin()+q-1, tok.begin()+q+1+1);
                tok.insert(tok.begin()+q-1, perform);
                --q;
                break;
            case '/':
                perform.value = tok[q-1].value/tok[q+1].value;
                tok.erase(tok.begin()+q-1, tok.begin()+q+1+1);
                tok.insert(tok.begin()+q-1, perform);
                --q;
                break;
            }
        }
        for(int q=initial_position; q<tok.size(); ++q){
            switch(tok[q].kind){
            case '+':
                perform.value = tok[q-1].value+tok[q+1].value;
                tok.erase(tok.begin()+q-1, tok.begin()+q+1+1);
                tok.insert(tok.begin()+q-1, perform);
                --q;
                break;
            case '-':
                perform.value = tok[q-1].value-tok[q+1].value;
                tok.erase(tok.begin()+q-1, tok.begin()+q+1+1);
                tok.insert(tok.begin()+q-1, perform);
                --q;
                break;
            }
       }
       answer.value = tok[0].value;
       return answer;
}

Token evaluate_parentheses(int initial_position) //Function: evaluates values inside parentheses and erase them.
{                                    //The argument initial_position: first parentheses of the pair more inner.
    Token perform {'8', 0};          //Erase elements of vector, until remain one.
    Token answer {'8', 0};
        for(int q=initial_position; tok[q].kind!=')'; ++q){
            switch(tok[q].kind){
            case '*':
                perform.value = tok[q-1].value*tok[q+1].value;
                tok.erase(tok.begin()+q-1, tok.begin()+q+1+1);
                tok.insert(tok.begin()+q-1, perform);
                --q;
                break;
            case '/':
                perform.value = tok[q-1].value/tok[q+1].value;
                tok.erase(tok.begin()+q-1, tok.begin()+q+1+1);
                tok.insert(tok.begin()+q-1, perform);
                --q;
                break;
            }
        }
        for(int q=initial_position; tok[q].kind!=')'; ++q){
            switch(tok[q].kind){
            case '+':
                perform.value = tok[q-1].value+tok[q+1].value;
                tok.erase(tok.begin()+q-1, tok.begin()+q+1+1);
                tok.insert(tok.begin()+q-1, perform);
                --q;
                break;
            case '-':
                perform.value = tok[q-1].value-tok[q+1].value;
                tok.erase(tok.begin()+q-1, tok.begin()+q+1+1);
                tok.insert(tok.begin()+q-1, perform);
                --q;
                break;
            }
       }
       if(tok[initial_position].kind=='(' && tok[initial_position+2].kind==')')
       tok.erase(tok.begin()+initial_position+2); //Erase parentheses signal '(' and ')'.
       tok.erase(tok.begin()+initial_position);
    answer.value = tok[initial_position].value;
    return answer;
}

int main()
{
   int previous_parentheses, latter_parentheses;
   int control = 0;
   Token result;
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
    for(int t=0; t<tok.size(); ++t) {
        for(int p=0; p<tok.size(); ++p){
        if(tok[p].kind=='('){
            previous_parentheses = p;
           }
        if(tok[p].kind==')'){
            latter_parentheses = p;
            ++control;
           }
        if(control==1){
            result = evaluate_parentheses(previous_parentheses);
            control = 0;
            break;
        }
      }
    }
    result = evaluate(0);
    cout << "Result: " << result.value;
}
