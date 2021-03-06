class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1,INT_MAX));
        
        int i = 1, j = 1;
        dp[0][0] = grid[0][0];
        //dp[i][0]
        while (i < m) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            i++;
        }
        while (j < n) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
            j++;
        }
        
        for (i = 1; i < m; i++)
            for (j = 1; j < n; j++) 
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        
        return dp[m-1][n-1];
        
    }
};