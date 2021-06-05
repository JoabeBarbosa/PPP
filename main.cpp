#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int check(int x)
{
    if(x==2||x==3||x==5||x==7)
    return x;
    else if(x==1||x%2==0||x%3==0||x%5==0||x%7==0)
    return 0;
    else
    return x;
}
int main()
{

    vector<int>primes;
    for(int i=1; i<=100; ++i)
    if(check(i)!=0)
    primes.push_back(i);

    for(int x:primes)
    cout << x << " ";

}

