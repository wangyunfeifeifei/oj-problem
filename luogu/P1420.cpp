//
// Created by wang on 2022/3/24.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    int a, b;
    int k = 1;
    int max_k = 1;
    scanf("%d", &n);
    scanf("%d", &b);
    for (int i = 1; i < n; i++) {
        a = b;
        scanf("%d", &b);
        if (b == a + 1) {
            k++;
        } else {
            k = 1;
        }
        max_k = k > max_k ? k : max_k;
    }
    printf("%d\n", max_k);
    return 0;
}
