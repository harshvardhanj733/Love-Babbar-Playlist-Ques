class Solution {
public:

    void getSubsets(vector<int> & nums, vector<vector<int>> & res, int n, vector<int> temp){
        if(n >= nums.size()){
            res.push_back(temp);
            return;
        }

        getSubsets(nums, res, n+1, temp);
        temp.push_back(nums[n]);
        getSubsets(nums, res, n+1, temp);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> temp;

        getSubsets(nums, res, 0, temp);

        return res;

    }
};