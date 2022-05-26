#include <stdio.h>

int main() {
	int n, N;
	int a[201]={0};
	scanf("%d%d", &n, &N);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int cur = 0;
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(cur<n&&i>=a[cur+1])cur++;
		ans+=cur;
	}
	printf("%d\n", ans);
	return 0;
}
