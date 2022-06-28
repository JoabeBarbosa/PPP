#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

const char stop = '0';

namespace Pairs{
    class Name_pairs{
    public:
            void read_names();
            void read_ages();
            void print();
            void sort_();
            void printt();
    private:
            vector<string>name;
            vector<double>age;
    };
}

Pairs::Name_pairs& p1()
{
    static Pairs::Name_pairs a;
    return a;
}

void Pairs::Name_pairs::read_names()
{
    string s;
    if(cin>>s&&isalpha(s[0])){
        p1().name.push_back(s);
    }
    else{
        cout << "Wrong input!\n";
        cout << "Enter a name: ";
        p1().read_names();
    }
}

void Pairs::Name_pairs::read_ages()
{
    char ch;
    double d;
    if(cin>>ch&&isdigit(ch)){
        cin.putback(ch);
        cin >> d;
        p1().age.push_back(d);
    }
    else{
        cout << "Wrong input!" << endl;
        string s;
        getline(cin, s);
        cout << "Enter a age: ";
        p1().read_ages();
    }
}

void Pairs::Name_pairs::print()
{
    for(int i=0; i<p1().name.size(); ++i){
        cout << p1().name[i] << '\t' << p1().age[i] << endl;
    }
}

void Pairs::Name_pairs::sort_()
{
    vector<string>name3 {p1().name};
    vector<double>age4;
    sort(p1().name.begin(), p1().name.end());
    for(int i=0; i<p1().name.size(); ++i){
        for(int j=0; j<name3.size(); ++j){
            if(p1().name[i]==name3[j])
                age4.push_back(p1().age[j]);
        }
    }
    p1().age = age4;
}

void get_pair()
{
    while(true){
        char ch;
        cout << "Enter a name: ";
        cin >> ch;
        if(ch==stop)break;
        cin.putback(ch);
        p1().read_names();
        cout << "Enter a age: ";
        p1().read_ages();

    }
}

int main()
{
    get_pair();
    p1().print();
    p1().sort_();
    p1().print();
}

