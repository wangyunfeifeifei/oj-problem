#ifndef __DISPLAY_H
#define __DISPLAY_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void display2dVec(vector<vector<T>> vec)
{
    if (vec.size() == 0)
        return;
    int m = vec.size();
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

#endif // __DISPLAY_H
