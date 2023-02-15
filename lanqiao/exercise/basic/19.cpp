#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    char str[8001];
    scanf("%d%s", &n, str);

    int end = n-1;
    int odds = 0; // 记录奇数个数
    int ans = 0;
    for(int i = 0; i < end; i++) {
        int k;
        for(k = end; k > i; k--) {
            if(str[i] == str[k]) {
                for(int x = k; x < end; x++) {
                    swap(str[x], str[x+1]);
                    ++ans;
                }
                --end;
                break;
            }
        }
        if(k == i) {
            // 没找到相同的
            odds++;
            if(n%2 == 0 || odds == 2) {
                printf("Impossible");
                return 0;
            }
            ans += n / 2 - i;
        }
    }
    printf("%d\n", ans);

    return 0;
}
