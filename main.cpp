#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int answer;
    string reply;
    vector<int>numbers;
    for(int i=1; i<=100; ++i)
        numbers.push_back(i);
    int n = numbers.size();
    int lo = 0;
    int hi = n-1;
    cout << "Think a number between one and hundred!" << '\n';
    while(lo<=hi)
    {
        int mi = lo + (hi-lo)/2;
        cout << "Is the number you are thinking of less than or equal "
             << numbers[mi] << "? yes or no?" << '\n';
        cin >> reply;
        if(reply=="no")
            lo = mi+1;
        else
            hi = mi-1;
    }
    answer = lo+1;
    cout << "The number you thought is "
         << answer << "!" << '\n';

}
