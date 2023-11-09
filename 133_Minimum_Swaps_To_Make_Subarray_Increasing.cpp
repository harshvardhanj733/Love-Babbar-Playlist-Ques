class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        if(index == nums1.size()){
            return 0;
        }

        int ans = INT_MAX;
        int prev, next;
        if(index != 0){
            prev = nums1[index-1];
            next = nums2[index-1];

            if(swapped){
                swap(prev, next);
            }
        }

        if(index == 0 || (nums1[index] > prev && nums2[index] > next)){
            ans = min(ans, solve(nums1, nums2, index+1, false));
        }
        if(index == 0 || (nums1[index] > next && nums2[index] > prev)){
            ans = min(ans, 1 + solve(nums1, nums2, index+1, true));
        } 

        return ans;
    }

    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp){
        if(index == nums1.size()){
            return 0;
        }
        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }

        int ans = INT_MAX;
        int prev, next;
        if(index != 0){
            prev = nums1[index-1];
            next = nums2[index-1];

            if(swapped){
                swap(prev, next);
            }
        }

        if(index == 0 || (nums1[index] > prev && nums2[index] > next)){
            ans = min(ans, solveMem(nums1, nums2, index+1, false, dp));
        }
        if(index == 0 || (nums1[index] > next && nums2[index] > prev)){
            ans = min(ans, 1 + solveMem(nums1, nums2, index+1, true, dp));
        } 

        return dp[index][swapped] = ans;
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>> dp(nums1.size()+1, vector<int> (2, 0));
        
        for(int i = nums1.size() - 1; i >= 0; i--){
            for(int swapped = 0; swapped < 2; swapped++){

            
            int ans = INT_MAX;
            int prev, next;
            if(i != 0){
                prev = nums1[i-1];
                next = nums2[i-1];

                if(swapped == 1){
                    swap(prev, next);
                }
            }

            if(i == 0 || (nums1[i] > prev && nums2[i] > next)){
                ans = min(ans, dp[i+1][0]);
            }
            if(i == 0 || (nums1[i] > next && nums2[i] > prev)){
                ans = min(ans, 1 + dp[i+1][1]);
            } 

            dp[i][swapped] = ans;
        }
        }

        return dp[0][0];
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        bool swapped = false;
        // return solve(nums1, nums2, 0, swapped);
        // vector<vector<int>> dp(nums1.size(), vector<int> (2, -1));
        // return solveMem(nums1, nums2, 0, swapped, dp);
        return solveTab(nums1, nums2);
    }
};

//TC: O(n*2);
//SC: O(n) -> can be optimised to O(1);