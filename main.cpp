#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Enter value n (n first primes)\n";
    int n;
    cin >> n;
    vector<int>primes;
    for(int i=1; i<=n*n; i++)
        primes.push_back(i);
    primes.erase(std::remove(primes.begin(), primes.end(), 1), primes.end());
    for(int p=0; p<=n; ++p)
    {
        int j = primes[p]*2;
        for(int i=j; i<=n*n; i+=primes[p])
            primes.erase(std::remove(primes.begin(), primes.end(), i), primes.end());
    }
    cout << '\n' << '\n' << "First " << n << " primes: \n";
    for(int x=0; x<n; ++x)
    {
        cout << primes[x] << " ";
    }
}
