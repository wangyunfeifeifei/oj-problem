#include<stdio.h>

int n, m, k;
int t, c;
int arr[400005] = {0};
int q;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<n;i++){
		scanf("%d%d", &t, &c);
		arr[t-c>0?t-c+1:1] ++;
		arr[t+1]--;
	}
	for(int i = 1; i < 400005; i++) {
		arr[i] += arr[i-1];
	}
	while(m--) {
		scanf("%d", &q);
		printf("%d\n", arr[q+k]);
	}
	return 0;
}
