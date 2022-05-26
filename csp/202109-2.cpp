#include<stdio.h>
#include <algorithm>
using namespace std;

int darr[10001] = {0};
int main() {
	int n;
	scanf("%d", &n);
	int last, x=0;
	int maxnum = 0;
	for(int i = 0 ; i< n; i++) {
		last = x;
		scanf("%d", &x);
		maxnum = max(x, maxnum);
		if(x > last) {
			darr[last+1] ++;
			darr[x+1]--;
		}
	}
	int ans = 0;
	int sum = 0;
	for(int i = 0; i <= maxnum; i++) {
		sum += darr[i];
		ans = max(sum, ans);
	}
	printf("%d\n", ans);
	return 0;
}
