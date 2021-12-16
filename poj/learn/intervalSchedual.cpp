/**
 * 区间调度问题
 * 有n项工作， 每项工作分别在si开始，ti结束。对每项工作，你都可以选择参与与否。选择参与不能提前结束，参与工作的时间不能重叠（即使开始瞬间和结束瞬间重叠也不行）
 * 目标：参加尽可能多的工作，求最多参加多少项工作？
 *
 * 1 <= N <= 100000
 * 1 <= si <= ti <= 10^9
 *
 * 解决方案：按结束时间排序
 */
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

using namespace std;

const int MAX_N = 100000;

int N, S[MAX_N], T[MAX_N];

pair<int, int> itv[MAX_N];

void solve() {
    for (int i = 0; i < N; i++) {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv, itv + N);

    int ans = 0, t = 0;
    for (int i = 0; i < N; i++) {
        if (t < itv[i].second) {
            ans++;
            t = itv[i].first;
        }
    }

    printf("%d\n", ans);
}
