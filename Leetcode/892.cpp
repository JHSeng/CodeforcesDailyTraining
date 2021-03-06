class Solution {
public:
    int surfaceArea(vector<vector<int>> &grid) {
        int ans = 0, len = grid.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0) ans += grid[i][j] * 4 + 2;
                if (i > 0) ans -= min(grid[i - 1][j], grid[i][j]) * 2;
                if (j > 0) ans -= min(grid[i][j - 1], grid[i][j]) * 2;
            }
        }
        return ans;
    }
};
