/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

#include "include/headers.h"

// @lc code=start
struct Pos
{
    int x, y;
    Pos(int x, int y) : x(x), y(y)
    {
    }
}; // 坐标

const int di[4] = {0, 0, 1, -1};
const int dj[4] = {1, -1, 0, 0};

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // 1 <= m, n <= 10;
        int m = grid.size();    // 行数
        int n = grid[0].size(); // 列数
        int cnt = 0;            // 新鲜橘子个数
        queue<Pos> q;           // 腐烂橘子队列
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    Pos t(i, j);
                    q.push(t);
                }
                else if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        if (cnt == 0)
            return 0;
        int ans = 0;
        while (!q.empty())
        {
            queue<Pos> tmp;
            while (!q.empty())
            {
                Pos p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int ni = p.x + di[i];
                    int nj = p.y + dj[i];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1)
                    {
                        cnt--;
                        grid[ni][nj] = 2;
                        tmp.emplace(ni, nj);
                    }
                }
            }
            ans++;
            q = tmp;
        }
        if (cnt != 0)
            return -1;
        return ans - 1;
    }
};
// @lc code=end
