#include <iostream>
#include <vector>

namespace exc{
    struct data_vec{
        double mean;
        double median;
        double largest;
        double smallest;
    };
    double mean;
    double median;
    double largest;
    double smallest;
}

void maxv(const std::vector<double>& v)
{
    exc::mean = v[0];
    exc::largest = v[0];
    exc::smallest = v[0];
    for(const double& d:v){
        exc::mean += d;
        if(d>exc::largest)
            exc::largest = d;
        if(d<exc::smallest)
            exc::smallest = d;
    }
    exc::mean /= v.size();
    exc::median = v[v.size()/2];
}

exc::data_vec max_struct(const std::vector<double>& v)
{
    double mean = 0;
    double largest = v[0];
    double smallest = v[0];
    for(const double& d:v){
        mean += d;
        if(d>largest)
            largest = d;
        if(d<smallest)
            smallest = d;
    }
    mean /= v.size();
    double median = v[v.size()/2];
    return exc::data_vec{mean, median, largest, smallest};
}

int main()
{
    std::vector<double>v = {1,2,3,4,5,6,7,8,9,12,23,1234,345.65,76554,7852345.6};
    exc::data_vec data = max_struct(v);
    std::cout << "mean = " << data.mean << " median = " << data.median << " largest = " << data.largest << " smallest = " << data.smallest << std::endl;
}
