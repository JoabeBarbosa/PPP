#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>primes;
    for(int i=1; i<=100; i++)
        primes.push_back(i);
    for(int x:primes)
        cout << x << " ";
    primes.erase(std::remove(primes.begin(), primes.end(), 1), primes.end());
    for(int p=0; p<=10; ++p)
    {
        int j = primes[p]*2;
        for(int i=j; i<=100; i+=primes[p])
          primes.erase(std::remove(primes.begin(), primes.end(), i), primes.end());
    }
    cout << '\n' << '\n';
    for(int x:primes)
        cout << x << " ";
}
