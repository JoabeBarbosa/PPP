#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double>numbers;
    cout << "Enter numbers: " << '\n';
    for(int i; cin>>i;)
        numbers.push_back(i);
    std::sort(numbers.begin(), numbers.end());
    if(numbers.size()%2!=0)
        cout << "\nThe median is: "
             << numbers[(numbers.size()-1)/2];
    else
        cout << "\nThe median is: "
             << (numbers[numbers.size()/2-1]+numbers[numbers.size()/2])/2
             << '\n';
}
