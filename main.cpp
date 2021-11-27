#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Name_value{
public:
    Name_value();
    string name;
    int value;
};

Name_value::Name_value()
{
    name = " "; //String initialization
    value = 0;
}

void Validation();

Name_value nm;

void Set_name_value()
{
    cin >> nm.name >> nm.value;
    Validation();
}

vector<Name_value>Nava;

void Validation()
{
    for(int i=0; i<Nava.size(); ++i){
        if(nm.name==Nava[i].name)
        {
            cout << "Name entered twice. Try again!\n";
            Set_name_value();
        }
    }
}

int main()
{
    cout << "Enter a name and score:\n"
            "The inputs 'NoName 0' stop the loop. \n";
    while(cin){
        Set_name_value();
        if(nm.name=="NoName" && nm.value==0)
            break;
        else
            Nava.push_back(nm);
    }
    for(int i=0; i<Nava.size(); ++i){
        cout << Nava[i].name << '\t' << Nava[i].value << endl;
    }
}
