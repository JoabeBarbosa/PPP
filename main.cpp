#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   double first_number, last_one, smallest, largest;
   double sum = 0;
   double num_val = 0;
   string unit = " ";
   vector<double>numbers;
    while(cin >> first_number >> unit)
       if(unit=="m")
       {
        cout << first_number << unit << '\n';
        sum+=first_number;
        ++num_val;
        numbers.push_back(first_number);
        break;
       }
       else if(unit=="cm")
       {
           cout << first_number/100.0 << "m" << '\n';
           first_number/=100.0;
           sum+=first_number;
           ++num_val;
           numbers.push_back(first_number);
           break;
       }
       else if(unit=="in")
       {
           cout << first_number*0.0254 << "m" << '\n';
           first_number*=0.0254;
           sum+=first_number;
           ++num_val;
           numbers.push_back(first_number);
           break;
       }
       else if(unit=="ft")
       {
           cout << first_number*0.3048 << "m" << '\n';
           first_number*=0.3048;
           sum+=first_number;
           ++num_val;
           numbers.push_back(first_number);
           break;
       }
        else
       {
            cout << "Wrong unit. Try again!";
       }
    smallest = first_number;
    largest = first_number;
    while(cin>>last_one>>unit)
    if(unit=="m")
    {
        if(last_one>largest)
       {
        cout << last_one << unit << " the largest so far." << '\n';
        largest = last_one;
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
       }
        else if(last_one<smallest)
       {
        cout << last_one << unit << " the smallest so far" << '\n' ;
        smallest = last_one;
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
        }
        else
        {
        cout << last_one << unit << '\n';
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
        }

    }
    else if(unit=="cm")
    {
        last_one/=100.0;
        if(last_one>largest)
       {
        cout << last_one << "m" << " the largest so far." << '\n';
        largest = last_one;
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
       }
        else if(last_one<smallest)
       {
        cout << last_one << "m" << " the smallest so far" << '\n' ;
        smallest = last_one;
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
        }
        else
        {
        cout << last_one << "m" << '\n';
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
        }
    }
    else if(unit=="in")
    {
        last_one*=0.0254;
        if(last_one>largest)
       {
        cout << last_one << "m" << " the largest so far." << '\n';
        largest = last_one;
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
        }
        else if(last_one<smallest)
       {
        cout << last_one << "m" << " the smallest so far" << '\n' ;
        smallest = last_one;
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
        }
        else
        {
        cout << last_one << "m" << '\n';
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
        }
    }
    else if(unit=="ft")
    {
        last_one*=0.3048;
        if(last_one>largest)
       {
        cout << last_one << "m" << " the largest so far." << '\n';
        largest = last_one;
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
       }
        else if(last_one<smallest)
       {
        cout << last_one << "m" << " the smallest so far" << '\n' ;
        smallest = last_one;
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
        }
        else
        {
        cout << last_one << "m" << '\n';
        sum+=last_one;
        ++num_val;
        numbers.push_back(last_one);
        }
    }
    else
    {
        cout << "Wrong unit. Try again!" << '\n';
    }
    std::sort(numbers.begin(), numbers.end());
    cout << "The sum is " << sum
         << "m.\nThe number of values is " << num_val
         << ".\nThe smallest is " << smallest
         << "m.\nThe largest is " << largest
         << "m."
         << '\n';
         cout << "All the values entered:\n";
         for(double x:numbers)
            cout << x << " ";
}
