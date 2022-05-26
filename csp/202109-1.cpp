#include<stdio.h>

int main() {
	int n;
	int a[101];
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int maxsum = a[0];
	int minsum = a[0];
	for(int i = 1; i < n; i++) {
		maxsum+=a[i];
		if(a[i]>a[i-1]) minsum += a[i];
	}
	printf("%d\n%d\n", maxsum, minsum);
	return 0;
}
