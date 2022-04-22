#include <cstdio>
#include <cmath>

bool light[2000001]={0};
int main() {
    int n;
    double a;
    int t;
    int maxi = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%d", &a, &t);
        for(int j = 1; j <= t; j++) {
            int idx = floor(j*a);
            light[idx] = !light[idx];
            if(idx > maxi) maxi = idx;
        }
    }
    for(int i=0; i <=maxi; i++) {
        if(light[i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
