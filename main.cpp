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
    cout << "One more time, enter a score: \n";
    int check;
    int control = 0;
    cin>>check;
    for(int j=0; j<scores.size(); ++j)
         {
             if(check==scores[j])
                {
                   cout << "\nCorresponding name: " << names[j] << '\n' ;
                   ++control;
                }
         }
    if(control==0)
         {
            cout << "\nScore not found.";
         }



}
