#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Enter names: \n";
    vector<string>names;
    for(string g:names)
        cout << g << " ";
    string para = "0";
    for(string name; cin>>name;)
    {
        if(name!=para)
        names.push_back(name);
        else
        break;
    }
    string Max, min, mode;
    std::sort(names.begin(), names.end());
    for(string h:names)
        cout << h << " ";
    min = names[0];
    Max = names[names.size()-1];
    int score_previous = 0;
    int score_later = 0;
    for(int p=0; p<names.size(); ++p)
     {
        string position = names[p];
        for(int i=0; i<names.size(); ++i)
        {
            if(names[i]==position)
            ++score_later;
        }
        if(score_later>score_previous)
        {
        mode = names[p];
        score_previous=score_later;
        score_later = 0;
        }
        else
        score_later = 0;
     }
    cout << "\nMax " << Max
         << "\nmin " << min
         << "\nmode " << mode;
}
