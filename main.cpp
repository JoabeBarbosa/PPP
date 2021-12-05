#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void conjunction();
void verb();
void noun();

void sentence()
{
    conjunction();
    char word = ' ';
    cin >> word;
    if(word=='.')
        cout << "It's ok!" << endl;
    else
    {
        cin.putback(word);
        sentence();
    }
}

void conjunction()
{
    verb();
    char space = ' ';
    char dot = ' ';
    cin.get(space);
    dot = cin.peek();
    if(dot!='.'){
        string word = " ";
        cin >> word;
        if(word!="and" && word!="or" && word!="but"){ //Pattern consistency
            cout << "Not ok!" << endl;
            throw(word);
        }
    }
}

void verb()
{
    noun();
    string word = " ";
    cin >> word;
    if(word!="rules" && word!="fly" && word!="swim"){
        cout << "Not ok!" << endl;
        throw(word);
    }
}

void noun()
{
    string word = " ";
    cin >> word;
    if(word!="birds" && word!="fish" && word!="c++"){
        cout << "Not ok!" << endl;
        throw(word);
    }

}

int main()
try
{
    cout << "Please, enter a simple English sentence: \n"
            "Enter any number to quit.\n";
    while(cin){
        sentence();
    }
}

catch(string myString)
{
    cout << "Bad input: " << myString << endl;
}
