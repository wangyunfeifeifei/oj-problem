#include <map>
#include <queue>

using namespace std;

const int MAX_N = 101;
const int MAX_M = 101;
const int INF = 100000000;

typedef pair<int, int> P;

char maze[MAX_N][MAX_M];
int N, M;
int sx, sy; // 起点
int gx, gy; // 终点

int d[MAX_N][MAX_M];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<P> que;
    // 把所有的位置都初始化为INF
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            d[i][j] = INF;
    // 将起点加入队列，并把这一地点的距离设置为0
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    // 不断循环直到队列的长度为0
    while (que.size()) {
        P p = que.front();
        if (p.first == gx && p.second == gy) break;

        for (int i = 0; i < 4; i++) {
            // 移动之后的位置记为(nx, ny)
            int nx = p.first + dx[i], ny = p.second + dy[i];

            // 判断是否可以移动以及是否已经访问过
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

void solve() {
    int res = bfs();
    printf("%d\n", res);
}
