#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Enter values r(rocket), p(paper) or s(scissors).\n";
    vector<char>machine;
    for(char random; cin>>random;)
    {
        if(random=='r'||random=='p'||random=='s')
        machine.push_back(random);
        else
        break;

    }
    for(int i=0; i<machine.size(); ++i)
    {
        cout << "Let's play. Choose r, p or s.\n";
        char choice;
        cin >> choice;
        switch(machine[i]){
        case 'r':
        {
        if(choice=='r')
        cout << "Draw. RxR\n";
        else if(choice=='p')
        cout << "Win. RxP\n";
        else
        cout << "Lose. RxS\n";
        }
        break;
        case 'p':
        {
        if(choice=='r')
        cout << "Lose. PxR\n";
        else if(choice=='p')
        cout << "Draw. PxP\n";
        else
        cout << "Win. PxS\n";
        }
        break;
        case 's':
        {
        if(choice=='r')
        cout << "Win. SxR\n";
        else if(choice=='p')
        cout << "Lose. SxP\n";
        else
        cout << "Draw. SxS\n";
        }
        break;}

    }
}

