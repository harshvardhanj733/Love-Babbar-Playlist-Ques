class Solution {
public:

    void solveRecursively(vector<int> nums, vector<vector<int>> & res, int index){
        if(index >= nums.size()-1){
            res.push_back(nums);
            return;
        }

        for(int i = index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            solveRecursively(nums, res, index+1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        solveRecursively(nums, res, 0);

        sort(res.begin(), res.end());

        return res;

    }
};