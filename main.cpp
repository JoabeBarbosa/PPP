#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Enter a set of positive integers.\n";
    vector<int>numbers;
    for(int i; cin>>i;)
        numbers.push_back(i);
    std::sort(numbers.begin(), numbers.end());
    for(int x:numbers)
        cout << x << " ";
    int score_previous = 0;
    int score_later = 0;
    int mode;
    for(int p=0; p<numbers.size(); ++p)
    {
        int position = numbers[p];
        for(int i=0; i<numbers.size(); ++i)
        {
            if(numbers[i]==position)
                ++score_later;
        }
        if(score_later>score_previous)
        {
            mode = numbers[p];
            score_previous=score_later;
            score_later = 0;
        }
        else
            score_later = 0;
    }
    cout << "\nMode is " << mode;
}
