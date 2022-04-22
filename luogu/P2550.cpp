#include <cstdio>
#define M 7

int main() {
    int n;
    int luck[M];
    int ans[M] = {0};
    int temp;
    scanf("%d", &n);
    for(int i = 0; i < M; i++) {
        scanf("%d", &luck[i]);
    }
    for(int i = 0; i < n; i ++) {
        int cnt = 0;
        for(int j = 0; j < M; j++) {
            scanf("%d", &temp);
            for(int k = 0; k < M; k++) {
                if(temp == luck[k]) {
                    cnt++;
                    break;
                }
            }
        }
        ans[7-cnt]++;
    }
    for(int i = 0; i < M; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
