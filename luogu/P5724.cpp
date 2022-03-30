//
// Created by wang on 2022/3/24.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    int a[101];
    scanf("%d", &n);
    int min_i=0, max_i=0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] > a[max_i]) max_i = i;
        if(a[i] < a[min_i]) min_i = i;
    }
    printf("%d\n", a[max_i] - a[min_i]);
    return 0;
}
