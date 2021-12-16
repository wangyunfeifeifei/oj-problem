#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(void)
{
    double T, D, H, E, h, t1, t2;
    char c1, c2;
    while (cin >> c1&&c1 != 'E')
    {
        cin >> t1 >> c2 >> t2;
        if (c1 == 'T'&&c2 == 'D' || c1 == 'D'&&c2 == 'T')
        {
            T = t1, D = t2;
            if (c1 == 'D') swap(T, D);
            H = T + 0.5555*(6.11*exp(5417.7530*((1 / 273.16) - (1 / (D + 273.16)))) - 10.0);
        }
        else if (c1 == 'T'&&c2 == 'H' || c1 == 'H'&&c2 == 'T')
        {
            T = t1, H = t2;
            if (c1 == 'H') swap(T, H);
            D = 1 / (1 / 273.16 - log(((H - T) / 0.5555 + 10.0 )/ 6.11) / 5417.7530) - 273.16;
        }
        else
        {
            D = t1, H = t2;
            if (c1 == 'H') swap(D, H);
            T = H - 0.5555*(6.11*exp(5417.7530*((1 / 273.16) - (1 / (D + 273.16)))) - 10.0);
        }
        cout << setiosflags(ios::fixed) << setprecision(1) << "T " << T << " D " << D << " H " << H << endl;
    }
    return 0;
}