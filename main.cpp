#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

int check(int x)
{
    if(x==1)
    {
        return 0;
    }
    else
    {
       for(int i=2; i<x; ++i)
          {
             if(x%i==0)
              {
               return 0;

              }
             else
               { } //Do nothing.
          }
    }

    return x;

}
int main()
{
    cout << "Enter Max.\n";
    int Max;
    cin >> Max;
    vector<int>primes;
    for(int i=1; i<=Max; ++i)
    if(check(i)!=0)
    primes.push_back(i);

    for(int x:primes)
    cout << x << " ";
}


