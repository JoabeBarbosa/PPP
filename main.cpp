#include <iostream>
#include <vector>

std::vector<int> num_char(const std::vector<std::string>& v)
{
    std::vector<int>ch;
    for(const std::string& s:v){
        ch.push_back(s.size());
    }
    return ch;
}

std::string longest(const std::vector<std::string>& v)
{
    std::string longest = v[0];
    for(const std::string& s:v){
        if(s.size()>longest.size())
            longest = s;
    }
    return longest;
}

std::string shortest(const std::vector<std::string>& v)
{
    std::string shortest = v[0];
    for(const std::string& s:v){
        if(s.size()<shortest.size())
            shortest = s;
    }
    return shortest;
}

std::string first(const std::vector<std::string>& v)
{
    std::string first = v[0];
    for(const std::string& s:v){
        if(s<first)
            first = s;
    }
    return first;
}

std::string last(const std::vector<std::string>& v)
{
    std::string last = v[0];
    for(const std::string& s:v){
        if(s>last)
            last = s;
    }
    return last;
}

int main()
{
    std::vector<std::string>v = {"carro", "bola", "constitucional", "zaratrusta", "barreira"};
    std::vector<int>numChar = num_char(v);
    for(int i:numChar)
        std::cout << i << " ";
    std::cout << std::endl;
    std::string longest_ = longest(v);
    std::string shortest_ = shortest(v);
    std::string first_ = first(v);
    std::string last_ = last(v);
    std::cout << " Longest, shortest, first, last = {" << longest_ << shortest_ << first_ << last_ << "}";
}
