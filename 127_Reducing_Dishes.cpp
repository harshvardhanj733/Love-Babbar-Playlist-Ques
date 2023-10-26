class Solution {
private:
    int solve(vector<int>& satisfaction, int index, int counter){
        if(index == satisfaction.size()){
            return 0;
        }

        // int ans = INT_MIN;
        int path1 = solve(satisfaction, index+1, counter+1) + satisfaction[index]*counter;
        int path2 = solve(satisfaction, index+1, counter);

        // ans = max(ans, max(path1, path2));
        
        // return ans;
        return max(path1, path2);
    }

    int solveMem(vector<int>& satisfaction, int index, int counter, vector<vector<int>>& dp){
        if(index == satisfaction.size()){
            return 0;
        }
        if(dp[index][counter] != -1){
            return dp[index][counter];
        }

        int path1 = solveMem(satisfaction, index+1, counter+1, dp) + satisfaction[index]*counter;
        int path2 = solveMem(satisfaction, index+1, counter, dp);

        return dp[index][counter] = max(path1, path2);
    }

    int solveTab(vector<int>& satisfaction){
        vector<vector<int>> dp(satisfaction.size()+1, vector<int>(satisfaction.size()+2, 0));
        for(int i = satisfaction.size() - 1; i >= 0; i--){
            for(int t = satisfaction.size(); t >= 1; t--){
                int path1 = satisfaction[i]*t + dp[i+1][t+1];
                int path2 = dp[i+1][t];
                
                dp[i][t] = max(path1, path2);
            }
        }

        return dp[0][1];
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // return solve(satisfaction, 0, 1);
        // vector<vector<int>> dp(satisfaction.size(), vector<int> (satisfaction.size() + 1, -1));
        // return solveMem(satisfaction, 0, 1, dp);
        return solveTab(satisfaction);
    }
};

//TC: O(nlogn);
//SC: O(n^2);