#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   double sum = 0; //Total distance
   double smallest = 0;
   double greatest = 0;
   double mean = 0;

   vector<double>distances;
   cout << "Enter distances between two cities: ";
   for(double i; cin>>i;)
      {
          distances.push_back(i);
          sum+=i; //Total distance
      }
      cout << "Total: " << sum << '\n';

   std::sort(distances.begin(), distances.end());
   smallest = distances[0];
   greatest = distances[distances.size()-1];
   mean = sum/distances.size();
   cout << "Smallest: " << smallest
        << "\nLargest: " << greatest
        << "\nMean distance: " << mean
        << '\n';

}
