//
// Created by wang on 2022/3/24.
//
#include <iostream>
using namespace std;

int main()
{
    long long int a=0, b=1,c;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        c = a+b;
        a = b;
        b = c;
    }
    printf("%.2lf\n", (double)a);
    return 0;
}
