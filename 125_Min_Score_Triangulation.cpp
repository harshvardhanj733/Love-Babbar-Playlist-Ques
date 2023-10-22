class Solution {
public:

    int solveRec(vector<int> values, int i, int j){
        if(i+1 == j){
            return 0;
        }

        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++){
            ans = min(ans, values[i]*values[j]*values[k] + solveRec(values, i, k) + solveRec(values, k, j));
        }

        return ans;
    }

    int solveMem(vector<int> values, int i, int j, vector<vector<int>>& dp){
        if(i+1 == j){
            return dp[i][j] = 0;
        }
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        for(int k = i + 1; k < j; k++){
            dp[i][j] = min(dp[i][j], values[i]*values[j]*values[k] + solveMem(values, i, k, dp) + solveMem(values, k, j, dp));
        }

        return dp[i][j];
    }

    int solveTab(vector<int> values){
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), INT_MAX));
        
        for(int i = values.size() - 2; i >= 0; i--){
            for(int j = i + 2; j < values.size(); j++){
                for(int k = i + 1; k < j; k++){
                    if(i+1 == k){
                        dp[i][k] = 0;
                    }
                    if(k+1 == j){
                        dp[k][j] = 0;
                    }
                    dp[i][j] = min(dp[i][j], values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][values.size()-1];
    }

    int minScoreTriangulation(vector<int>& values) {
        // int mini = 0;
        // return solveRec(values, 0, values.size()-1);
        // vector<vector<int>> dp(values.size(), vector<int>(values.size(), INT_MAX));
        // return solveMem(values, 0, values.size()-1, dp);
        return solveTab(values);
    }
};

//TC: O(n^3);
//SC: O(n^2);