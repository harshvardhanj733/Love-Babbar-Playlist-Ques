class Solution {
private:
    int solve(vector<vector<int>>& triangle, int n, int i, int j, 
    vector<vector<int>>& dp){
        if(i == n-1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans1 = triangle[i][j] + solve(triangle, n, i+1, j, dp);
        int ans2 = triangle[i][j] + solve(triangle, n, i+1, j+1, dp);
        
        return dp[i][j] = min(ans1, ans2);
    }

    int solveTab(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp;
        for(int i = 0; i < n; i++){
            vector<int> temp(i+1, 0);
            dp.push_back(temp);
        }
        for(int j = 0; j < n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int ans1 = triangle[i][j] + dp[i+1][j];
                int ans2 = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(ans1, ans2);
            }
        }

        return dp[0][0];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // vector<vector<int>> dp;
        // for(int i = 0; i < n; i++){
            // vector<int> temp(i+1, -1);
            // dp.push_back(temp);
        // }
        // return solve(triangle, n, 0, 0, dp);
        return solveTab(triangle);
    }
};

//TC: O(n^2);
//SC: O(n^2);