#include <stdio.h>
#include <algorithm>
using namespace std;

int sum[605][605] = {0};
int n, l, r, t;
int main() {
	scanf("%d%d%d%d", &n, &l, &r, &t);
	int x;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &x);
			sum[i][j] = x + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int left = max(0, j-r-1);
			int top = max(0, i-r-1);
			int right = min(n, j+r);
			int bottom = min(n, i+r);
			int area = sum[bottom][right]-sum[bottom][left]-sum[top][right]+sum[top][left];
			double m = area*1.0 / ((bottom-top)*(right-left));
			if(m<=t) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
