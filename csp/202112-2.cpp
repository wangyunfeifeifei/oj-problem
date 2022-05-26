#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100005]={0};
int main() {
	int n, N;
	scanf("%d%d", &n, &N);
	int r = N/(n+1);
	for(int i = 1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	a[n+1] = N;

	int k=0;
	long long int ans=0;
	for(int i=0; i<N; i+=r) {
		int fl = a[k];
		int fr = a[k+1]-1;
		int gl = i;
		int gr = min(i+r-1, N-1);
		int L = max(gl, fl);
		int R = min(gr, fr);
		int f = k, g = i/r;
		ans += (R-L+1) * abs(g-f);
		if(R==fr) k++;
		if(R!=gr) i-=r;
	}
	printf("%lld\n", ans);
	return 0;
}
