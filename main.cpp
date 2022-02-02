#include <iostream>
#include <vector>
#include <algorithm>

namespace buff{
    std::vector<std::string>name;
    std::vector<double>age;
    std::vector<std::string>nbuffer;
    std::vector<double>abuffer;
    void fill_abuffer(std::vector<double>&);
    int order();
    std::string next();
}

void define_names(std::vector<std::string>& v)
{
    std::cout << "Enter names: ";
    std::string name;
    char test;
    while(std::cin){
        std::cin >> test;
        if(isalpha(test)){
            std::cin.putback(test);
            std::cin >> name;
            v.push_back(name);
        }
        else
            break;
    }
    std::cout << std::endl;
}

void define_ages(std::vector<double>& v)
{
    std::cout << "Enter the respective ages: ";
    double ages;
    char test;
    while(std::cin){
        std::cin >> test;
        if(isdigit(test)){
            std::cin.putback(test);
            std::cin >> ages;
            v.push_back(ages);
        }
        else
            break;
    }
    std::cout << std::endl;
}

void print_pairs(const std::vector<std::string>& n, const std::vector<double>& a)
{
    for(int i=0; i<n.size(); ++i)
        std::cout << n[i] << '\t' << a[i] << std::endl;
}

void buff::fill_abuffer(std::vector<double>& d)
{

    while(d.size()<buff::name.size()){
        int i = buff::order();
        d.push_back(buff::age[i]);
    }
}

int buff::order()
{
    std::string s = buff::next();
    for(int i=0; i<buff::name.size(); ++i)
        if(s==buff::nbuffer[i])return i;
    throw(s);
}

std::string buff::next()
{
    static int i = -1;
    ++i;
    return buff::name[i];
}

void calculate()
try
{
    define_names(buff::name);
    define_ages(buff::age);
    print_pairs(buff::name, buff::age);
    buff::nbuffer = buff::name;
    sort(buff::name.begin(), buff::name.end());
    buff::fill_abuffer(buff::abuffer);
    std::cout << '\n' << "Sort:" << '\n' << std::endl;
    print_pairs(buff::name, buff::abuffer);
}

catch(std::string myString)
{
    std::cout << "Error myString: " << myString << std::endl;
}

catch(int myInt)
{
    std::cout << "Error myInt" << std::endl;
}

int main()
{
    calculate();
}
