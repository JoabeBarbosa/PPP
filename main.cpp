#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   int number;
   int square_position = 1;
   int grains_add = 1;
   int total_grains = 1;
   cout << "Enter a number: ";
   cin >> number;
   while(total_grains<number)
       if(square_position==1)
       {
          cout << "Square position (" << square_position
            << ") Grains add (" << grains_add
            << ") Total grains (" << total_grains << ")"
            << '\n';
            ++square_position;
       }
       else if(square_position==2)
       {
          grains_add = 2;
          total_grains = 3;
          cout << "Square position (" << square_position
               << ") Grains add (" << grains_add
               << ") Total grains (" << total_grains << ")"
               << '\n';
            ++square_position;
       }
       else
       {
          grains_add *= 2;
          total_grains += grains_add;
          cout << "Square position (" << square_position
               << ") Grains add (" << grains_add
               << ") Total grains (" << total_grains << ")"
               << '\n';
           ++square_position;
       }

}
