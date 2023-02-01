#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double a[4], b[4];
    for(int i = 0; i < 4; i++) {
        scanf("%lf", &a[i]);
    }
    for(int i = 0; i < 4; i++) {
        scanf("%lf", &b[i]);
    }
    if(a[0] > a[2]) swap(a[0], a[2]);
    if(a[1] > a[3]) swap(a[1], a[3]);
    if(b[0] > b[2]) swap(b[0], b[2]);
    if(b[1] > b[3]) swap(b[1], b[3]);

    double x1 = max(a[0], b[0]);
    double x2 = min(a[2], b[2]);
    double y1 = max(a[1], b[1]);
    double y2 = min(a[3], b[3]);
    if(x2 <= x1 || y2 <= y1) {
        printf("0.00\n");
        return 0;
    }
    printf("%.2lf\n", (x2-x1) * (y2-y1));
    return 0;
}
