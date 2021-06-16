#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   vector<string>names;
   vector<int>scores;
   cout << "Enter a name and score: ";
   string name_later;
   int score_later;
   while(cin>>name_later>>score_later)
   {
        for(int i=0; i<names.size(); ++i)
        {
            if(name_later==names[i])
            {
                cout << "\nError: name entered twice.";
                return 0;
            }
        }
        if(name_later=="NoName" && score_later==0)
            break;
        else
            {
                names.push_back(name_later);
                scores.push_back(score_later);
            }

   }
   for(int p=0; p<names.size(); ++p)
        cout << '\n' << names[p] << " " << scores[p] << '\n';
    cout << "One more time, enter a name: \n";
    string check;
    while(cin>>check)
     {
         for(int j=0; j<names.size(); ++j)
         {
             if(check==names[j])
                {
                   cout << "\nCorresponding score: " << scores[j];
                   return 0;
                }
         }
         cout << "\nName not found.";
     }
}
