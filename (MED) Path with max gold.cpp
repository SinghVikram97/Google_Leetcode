// https://leetcode.com/problems/path-with-maximum-gold/
class Solution
{
public:
  int dfs(vectocr<vector<int>> &grid, vector<vector<int>> &visited, int i, int j)
  {

    int m = grid.size();
    int n = grid[0].size();

    if (i >= m || i < 0 || j >= n || j < 0)
    {
      return 0;
    }

    if (grid[i][j] == 0)
    {
      return 0;
    }

    if (visited[i][j] != 0)
    {
      return 0;
    }

    int finalAns = 0;

    finalAns = finalAns + grid[i][j];

    visited[i][j] = 1;

    // 4 options
    int op1 = dfs(grid, visited, i + 1, j);
    int op2 = dfs(grid, visited, i - 1, j);
    int op3 = dfs(grid, visited, i, j + 1);
    int op4 = dfs(grid, visited, i, j - 1);

    visited[i][j] = 0;

    return finalAns + max(op1, max(op2, max(op3, op4)));
  }
  int getMaximumGold(vector<vector<int>> &grid)
  {

    int m = grid.size();
    int n = grid[0].size();
    int finalAns = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] != 0)
        {
          // Start from here
          vector<vector<int>> visited(m, vector<int>(n));
          int ans = dfs(grid, visited, i, j);
          finalAns = max(ans, finalAns);
        }
      }
    }
    return finalAns;
  }
};