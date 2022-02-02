#include <iostream>
#include <vector>

namespace exc{
    std::vector<double>price = {2, 4, 6 , 8, 10};
    std::vector<double>weight = {40, 60, 80, 100, 120};
    double pw(const std::vector<double>& d, const std::vector<double>& v);
}

void sum_all()
{
    double d = 0;
    if(exc::price.size()==exc::weight.size())
        for(int i=0; i<exc::price.size(); ++i){
            d += exc::pw(exc::price, exc::weight);
            std::cout << "Sum of price[i]*weight[i] = " << d << std::endl;
        }
    else
        throw(exc::price.size());
}

double exc::pw(const std::vector<double>& d, const std::vector<double>& v)
{
    static int i = 0;
    double j = d[i]*v[i];
    ++i;
    std::cout << "Multiplication of price[i]*weight[i] = " << j << '\n';
    return j;
}

int main()
{
    sum_all();
}
