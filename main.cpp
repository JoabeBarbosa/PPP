#include <iostream>
#include <vector>

void print(std::string label, const std::vector<int>& vec)
{
    std::cout << label << std::endl;
    for(const int& i:vec)
        std::cout << i << std::endl;

}

void fibonacci(int x, int y, std::vector<int>& v, int n)
{
    v.push_back(x);
    v.push_back(y);
    for(int i=1; i<n-1; ++i)
        v.push_back(v[i]+v[i-1]);
}

int main()
{
    std::vector<int>v;
    fibonacci(0, 1, v, 10);
    print("v", v);
}
