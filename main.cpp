#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    double a, b, c;
    double x_1, x_2;
    double delta;
    cout << "Enter a quadratic equation (ax^2 + bx + c = 0). Inputs a, b, and c: ";
    cin >> a >> b >> c;
    cout << '\n' << a << "x^2 + " << b << "x" << " + " << c << " = 0" << '\n';
    delta = b*b-4*a*c;
    cout << "Delta = " << delta;
    if(delta<0)
        {
           cout << "\nDelta < 0, have no real roots. Try again.";
           return 0;
        }
    else if(delta>0)
        {
            x_1= (-b+sqrt(delta))/2*a;
            x_2= (-b-sqrt(delta))/2*a;
            cout << "\nx_1 = " << x_1
                 << "\nx_2 = " << x_2;
        }
    else
        {
            x_1= (-b+sqrt(0))/2*a;
            cout << "x_1 = x_2 = " << x_1;
        }
}
