//
// Created by wang on 2021/12/7.
//

#include<stdio.h>
#include<algorithm>

using namespace std;

#define Max_N 1000000

int L, n;
int x[Max_N];

void solve() {
    // 计算最短时间： 当所有蚂蚁的方向都是离自己最近端点的方向。不会发生碰撞
    int minT = 0;
    for (int i = 0; i < n; i++) {
        minT = max(minT, min(x[i], L - x[i]));
    }
    // 计算最长时间：所有蚂蚁朝向离端点最远方向， 蚂蚁碰撞掉头其实相当于蚂蚁穿过了另一个蚂蚁。
    int maxT = 0;
    for (int i = 0; i < n; i++) {
        maxT = max(maxT, max(x[i], L - x[i]));
    }
    printf("%d %d\n", minT, maxT);
}

int main() {
    int T;
    freopen("../input.txt", "r", stdin);
    scanf("%d", &T);
    for (int k = T; k > 0; k--) {
        scanf("%d%d", &L, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        solve();
    }
    return 0;
}
