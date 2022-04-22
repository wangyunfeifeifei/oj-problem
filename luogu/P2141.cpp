#include <cstdio>
#include <algorithm>

int main() {
    int n;
    int num[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    std::sort(num, num + n);
    int ans = 0;
    for (int k = 0; k < n; k++) {
        int i = 0, j = n - 1;
        while (i < j) {
            int sum = num[i] + num[j];
            if (sum == num[k]) {
                i++;
                j--;
                ans++;
                break;
            } else if (sum < num[k]) i++;
            else j--;
        }
    }
    printf("%d\n", ans);
    return 0;
}
