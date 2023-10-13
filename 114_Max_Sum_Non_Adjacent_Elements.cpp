#include <bits/stdc++.h> 

int solve(vector<int> nums, int index, vector<int>& dp){
    if(index >= nums.size()){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }

    return dp[index] = max(nums[index] + solve(nums, index+2, dp), solve(nums, index+1, dp));
}

int solveTab(vector<int> nums){
    if(nums.size() == 1){
        return nums[0];
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    // dp[1] = nums[1];

    for(int i = 1; i < nums.size(); i++){
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }

    return dp[nums.size()-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    // int index = 0;
    // vector<int> dp(nums.size()+1, -1);
    // return solve(nums, index, dp);

    return solveTab(nums);
}