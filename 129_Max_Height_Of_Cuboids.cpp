class Solution {
private:
    bool check(vector<vector<int>>& cuboids, int prev, int index){
        if(cuboids[prev][0] <= cuboids[index][0] && cuboids[prev][1] <= cuboids[index][1] && cuboids[prev][2] <= cuboids[index][2]){
            return true;
        }

        return false;
    }

    int solveMem(vector<vector<int>>& cuboids, int n, int index, int prev, vector<vector<int>>& dp){
        if(index == n){
            return 0;
        }
        if(dp[index][prev+1] != -1){
            return dp[index][prev+1];
        }

        int incl = 0, excl = 0;
        if(prev == -1 || check(cuboids, prev, index)){
            incl = cuboids[index][2] + solveMem(cuboids, n, index+1, index, dp);
        }
        excl = solveMem(cuboids, n, index+1, prev, dp);

        return dp[index][prev+1] = max(incl, excl);
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(int i = 0; i < n; i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        sort(cuboids.begin(), cuboids.end());

        vector<vector<int>> dp(n+1, vector<int> (n+2, -1));
        return solveMem(cuboids, n, 0, -1, dp);
    }
};

//TC: O(n^2);
//SC: O(n^2);