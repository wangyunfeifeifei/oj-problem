#include <cstdio>
#include <algorithm>

using namespace std;

int maxSum = 0;

void stat(int a[], int m) {
    int sum = a[0];
    int maxScore = a[0], minScore = a[0];
    for (int i = 1; i < m; i++) {
        sum += a[i];
        if (maxScore < a[i]) maxScore = a[i];
        if (minScore > a[i]) minScore = a[i];
    }
    maxSum = max(maxSum, sum - maxScore - minScore);
}

int main() {
    int n, m;
    int data[21];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &data[j]);
        }
        stat(data, m);
    }
    printf("%.2lf\n", maxSum * 1.0 / (m - 2));
    return 0;
}
