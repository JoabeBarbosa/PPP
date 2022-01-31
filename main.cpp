#include <iostream>
#include <vector>

void rev_vec1(std::vector<int>vec1, std::vector<int>& v)
{
    for(int i=vec1.size()-1; i>=0; --i)
        v.push_back(vec1[i]);
}

void rev_vec2(std::vector<int>& v)
{
    for(int i=0, j=v.size()-1; i<j; ++i, --j)
        std::swap(v[i], v[j]);
}

int main()
{
    std::vector<int>test = {1, 2, 3, 4 , 5, 9, 0,};
    std::vector<int>test2;
    std::cout << "Original vector: ";
    for(const int& i:test)
        std::cout << i << " ";
    std::cout << std::endl;
    rev_vec1(test, test2);
    std::cout << "rev_vec1: ";
    for(const int& i:test2)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Original vector: ";
    for(const int& i:test)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "rev_vec2: " << std::endl;
    rev_vec2(test);
    std::cout << "Original vector: ";
    for(const int& i:test)
        std::cout << i << " ";

}
