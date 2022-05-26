#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, b;
    int h[20005];
    cin >> n >> b;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        pq.push(h[i]);
    }
    int high = 0;
    int ans = 0;
    while(high < b && !pq.empty()) {
        ans ++;
        high += pq.top();
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}
