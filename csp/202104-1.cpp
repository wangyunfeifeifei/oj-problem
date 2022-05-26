#include<stdio.h>

int main() {
	int n, m, L;
	int out[300] = {0};
	scanf("%d%d%d", &n, &m, &L);
	int t;
	for(int i = 0; i < n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &t);
			out[t]++;
		}
	}
	for(int i = 0; i < L; i++) {
		printf("%d ", out[i]);
	}
	return 0;
}
