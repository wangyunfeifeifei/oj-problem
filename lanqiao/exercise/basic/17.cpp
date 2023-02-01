#include <iostream>
#include <vector>
using namespace std;

// 方阵乘法
vector<vector<int> > mul(vector<vector<int> > a, vector<vector<int> > b) {
    int n = a.size();
    vector<vector<int> > ret = vector<vector<int> >(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int> > matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    vector<vector<int> > ans(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        // 初始化为单位阵
        ans[i][i] = 1;
    }
    for(int i = 0; i < m; i++) {
        ans = mul(ans, matrix);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j!=0) {
                printf(" ");
            }
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
