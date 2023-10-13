class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> subArrayMap;
        subArrayMap[0] = 1;

        int sum = 0, count = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            count += subArrayMap[sum-k];

            subArrayMap[sum]++;
        }

        return count;
    }
};